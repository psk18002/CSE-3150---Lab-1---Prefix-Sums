#include <vector>
#include <fstream>
#include <sstream>

#include "expensiveDEP.h"

using namespace std;

vector<vector<int>> expensiveDigraphExactPaths(vector<vector<int>>& D_minus_1, vector<vector<int>>& D_0, vector<vector<int>>& D_plus_1) {
    int n = D_0.size();
    for (int l = 2; l < 3*n*n+1; ++l) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if ((D_minus_1[i][k] + D_plus_1[k][j] == 0) || (D_plus_1[i][k] + D_minus_1[k][j] == 0)) {
                        D_0[i][j] = 0;
                    }
                    if ((D_plus_1[i][k] + D_0[k][j] == 1) || (D_0[i][k] + D_plus_1[k][j] == 1)) {
                        D_plus_1[i][j] = 1;
                    }
                    if ((D_minus_1[i][k] + D_0[k][j] == -1) || (D_0[i][k] + D_minus_1[k][j] == -1)) {
                        D_minus_1[i][j] = -1;
                    }
                }
            }
        }
    }
    return D_0;
}

vector<vector<int>> readGraphFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        exit(1);
    }

    vector<vector<int>> graph;
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        vector<int> row;
        int val;
        while (iss >> val) {
            row.push_back(val);
        }
        graph.push_back(row);
    }
    file.close();
    return graph;
}