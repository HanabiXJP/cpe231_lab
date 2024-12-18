#include <bits/stdc++.h>
using namespace std;

// Fitness function to evaluate the knapsack value of a given population
int Fitness(vector<bool> &pops, vector<int> &value, vector<int> &weights, int j) {
    int totalw = 0, totalval = 0;
    for (size_t i = 0; i < pops.size(); i++) {
        if (pops[i]) {
            totalw += weights[i];
            totalval += value[i];
        }
    }
    return (totalw <= j) ? totalval : 0;
}

// Two point crossover function
void TwoPointCross(vector<bool> &parent1, vector<bool> &parent2) {
    int cutpoint1 = rand() % parent1.size();
    int cutpoint2 = rand() % parent1.size();
    if (cutpoint1 > cutpoint2) swap(cutpoint1, cutpoint2);
    if (cutpoint1 == cutpoint2) return; // Ensure cut points are not the same
    for (int i = cutpoint1; i <= cutpoint2; i++) {
        swap(parent1[i], parent2[i]);
    }
}

// Three point crossover function
void ThreePointCross(vector<bool> &parent1, vector<bool> &parent2) {
    int size = parent1.size();
    int cutpoint1 = rand() % size;
    int cutpoint2 = rand() % size;
    int cutpoint3 = rand() % size;

    vector<int> points = {cutpoint1, cutpoint2, cutpoint3};
    sort(points.begin(), points.end());
    cutpoint1 = points[0];
    cutpoint2 = points[1];
    cutpoint3 = points[2];

    if (cutpoint1 == cutpoint2 || cutpoint2 == cutpoint3) return; // Ensure cut points are not the same

    for (int i = cutpoint1; i <= cutpoint2; i++) {
        swap(parent1[i], parent2[i]);
    }
    for (int i = cutpoint2 + 1; i <= cutpoint3; i++) {
        swap(parent1[i], parent2[i]);
    }
}

// Four point crossover function
void FourPointCross(vector<bool> &parent1, vector<bool> &parent2) {
    int size = parent1.size();
    int cutpoint1 = rand() % size;
    int cutpoint2 = rand() % size;
    int cutpoint3 = rand() % size;
    int cutpoint4 = rand() % size;

    vector<int> points = {cutpoint1, cutpoint2, cutpoint3, cutpoint4};
    sort(points.begin(), points.end());
    cutpoint1 = points[0];
    cutpoint2 = points[1];
    cutpoint3 = points[2];
    cutpoint4 = points[3];

    if (cutpoint1 == cutpoint2 || cutpoint2 == cutpoint3 || cutpoint3 == cutpoint4) return; // Ensure cut points are not the same

    for (int i = cutpoint1; i <= cutpoint2; i++) {
        swap(parent1[i], parent2[i]);
    }
    for (int i = cutpoint2 + 1; i <= cutpoint3; i++) {
        swap(parent1[i], parent2[i]);
    }
    for (int i = cutpoint3 + 1; i <= cutpoint4; i++) {
        swap(parent1[i], parent2[i]);
    }
}

// Three-point mutation function
void nPointMutation(int n, vector<bool> &parent) {
    int size = parent.size();
    for(int i=0;i<n; i++){
        int point = rand()% parent.size();
        parent[point] = !parent[point];
    }
}

// Tournament selection function
int tournamentSelect(int numberIntournament, vector<vector<bool>> &population, vector<int> &fitness) {
    int maxIndex = -1;
    int maxval = -1;
    for (int i = 0; i < numberIntournament; i++) {
        int curr = rand() % population.size();
        if (fitness[curr] > maxval) {
            maxval = fitness[curr];
            maxIndex = curr;
        }
    }
    return maxIndex;
}

void performCrossover(vector<bool> &parent1, vector<bool> &parent2) {
    int crossoverType = rand() % 3; // 0 for two point crossover, 1 for three, 2 for four
    if (crossoverType == 0) {
        TwoPointCross(parent1, parent2);
    } 
    if (crossoverType == 1) {
        ThreePointCross(parent1, parent2);
    } else {
        FourPointCross(parent1, parent2);
    }
}

void performMutation(vector<bool> &parent1, vector<bool> &parent2) {
    int mutationType = rand() % 2; // 0 for twoPointMutation, 1 for threePointMutation, 2 for NoMutation
    if (mutationType == 0) {
        nPointMutation(2, parent1);
        nPointMutation(2, parent2);
    } 
    if (mutationType == 1) {
        nPointMutation(1, parent1);
        nPointMutation(1, parent2);
    } 
    else{
        nPointMutation(4, parent1);
        nPointMutation(4, parent2);
    }
}

// Genetic Algorithm for Knapsack problem
int GAKnapsack(int i, int j, vector<int> value, vector<int> weights) {

    srand(time(0));
    int numberOfpopulation = 5000;
    int values[] = {46, 10};    
    int randomIndex = rand() % 2;
    int randomValue = values[randomIndex];
    int numberIntournament = rand() % 49 + randomValue;
    int numberOfElite = numberOfpopulation / 10;

    // Initialize population
    vector<vector<bool>> population(numberOfpopulation, vector<bool>(i));
    for (int m = 0; m < numberOfpopulation; m++) {
        for (int k = 0; k < i; k++) {
            if(rand()%100 < 10){
                population[m][k] = 1;
            }else{
                population[m][k] = 0;
            }
        }
    }

    int noGen = 0;
    int countSameMax = 0;
    int maxFitness = INT_MIN;
    int oldMax = -1;
    int maxFitnessNotChange = 120;

    // Main GA loop
    while (countSameMax < maxFitnessNotChange) {
        vector<int> fitness(numberOfpopulation, -1);
        for (int i = 0; i < numberOfpopulation; i++) {
            fitness[i] = Fitness(population[i], value, weights, j);
            maxFitness = max(maxFitness, fitness[i]);
        }
        if (maxFitness != oldMax) {
            countSameMax = 0;
        } else {
            countSameMax++;
        }
        oldMax = maxFitness;
        cout << "generation : " << noGen << " max Fitness: " << maxFitness << endl;

        vector<vector<bool>> next_gen;
        vector<pair<int, vector<bool>>> fitnessPopulation(numberOfpopulation);
        for (int i = 0; i < numberOfpopulation; i++) {
            fitnessPopulation[i] = {fitness[i], population[i]};
        }
        sort(fitnessPopulation.rbegin(), fitnessPopulation.rend());
        for (int i = 0; i < numberOfElite; i++) {
            next_gen.push_back(fitnessPopulation[i].second);
        }

        while (next_gen.size() < numberOfpopulation) {
            vector<bool> parent1 = population[tournamentSelect(numberIntournament, population, fitness)];
            vector<bool> parent2 = population[tournamentSelect(numberIntournament, population, fitness)];

            performCrossover(parent1,parent2);
            performMutation(parent1, parent2);

            next_gen.push_back(parent1);
            next_gen.push_back(parent2);
        }
        population = next_gen;
        noGen++;
    }
    return maxFitness;
}