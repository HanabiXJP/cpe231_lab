#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

/*Compare function for ASCENDING order*/
int compareFunction(int a, int b){
    if (a < b){
        return 1;
    }
    return 0;
}

/*Compare function for DESCENDING order*/
/* 

int compareFunction(int a, int b){
    if (a > b){
        return 1;
    }
    return 0;
}

*/

int main(){
    vector <int> vecc; //created an EMPTY vector

    vecc.push_back(97);
    vecc.push_back(67);
    vecc.push_back(53);
    vecc.push_back(108);
    vecc.push_back(83);

    printf(".front() is %d\n", vecc.front()); //front is DIRECTLY the first element in vector
    printf(".begin() is %p\n", vecc.begin()); //begin returns the iterator (something like address)
    printf("first element address is %p\n", &vecc[0]); //you can see that vecc.begin() and &vecc[0] is the same
    // printf("vector address is %p\n", vecc);

    vecc.insert(vecc.begin()+2, 99); // insert 99 as element 2 then make other next elements move to next index

    vector <int> vecc2(10); //created a vector with initially 10 elements (can be expanded later)

    vecc2[3] = 2;
    vecc2[1] = 100;
    vecc2[8] = 98;
    for (int i =0;i<15;i++){
        printf("vecc2[%d] is %d\n", i, vecc2[i]); //using #include<cstdio>, you can also printf and scanf 
    }

    
    cout << "Vector Size is " << vecc.size() << endl; //.size() will return the number of elements in vector

    cout << "Printed using normal iteration : ";
    for (int i=0; i < vecc.size();i++){
        cout << vecc[i] << " ";
    }
    cout << "\n"; // endl and "\n" is the same.

    cout << "Printed using RANGE-BASED for loop (using auto variable type) : ";
    for (auto i : vecc){
        cout << i << " ";
    }
    cout << endl;

    cout << "Printed using RANGE-BASED for loop (using int variable type) : ";
    for (int i : vecc){
        cout << i << " ";
    }
    cout << endl;

    cout << "Printed using RANGE-BASED for loop (using char variable type --> SEE THE DIFFERENCE) : ";
    for (char i : vecc){
        cout << i << " ";
    }
    cout << endl;

    for (int i : {50,60,70,80}){
        cout << "WEE "; // You will see that "WEE" will be printed out for 4 times (equal to number of elements in an array)
    }
    cout << endl;


    vector <int> vecc3 = {1034,1054,1056,1049,1055,1068,1034,1034};
    sort(vecc3.begin(), vecc3.end(), compareFunction); //using compare function can help you to be more flexible when writing sorting logic.
    for (auto i : vecc3){
        printf("%d ",i);
    }
}
