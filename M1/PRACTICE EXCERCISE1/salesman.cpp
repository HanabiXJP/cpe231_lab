#include <bits/stdc++.h>

using namespace std;

void addgraph(string stt, string des, int cost, vector<vector<int>> &ID, vector<string> &name) {
    if (find(name.begin(), name.end(), stt) != name.end()) {
        name.push_back(stt);
    }
    if (find(name.begin(), name.end(), des) != name.end()) {
        name.push_back(des);
    }
}

int main () {

    int n, p;

    cin >> n >> p;

    vector<vector<int>> ID;
    vector<string> name;

    for (int i = 0; i < p; i++) {

        string stt,des;
        int cost;

        cin >> stt >> des >> cost;

        addgraph(stt, des, cost, ID, name);
    }

    return 0;
}