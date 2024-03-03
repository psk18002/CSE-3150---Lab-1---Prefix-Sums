#include <fstream>
#include <vector>
#include <sstream>

#include "adjMat.h"

using namespace std;

void readAdjacencyMatrix(const string& filename, vector<vector<int>>& matrix) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }

    string line;
    while (getline(file, line)) {
        vector<int> row;
        int value;
        stringstream ss(line);
        while (ss >> value) {
            if (value == 2) {
                row.push_back(2);
            } else {
                row.push_back(value);
            }
        }
        matrix.push_back(row);
    }

    file.close();
}

void initAdjacencyMatrices(vector<vector<int>>& D_minus_1, vector<vector<int>>& D_0, vector<vector<int>>& D_plus_1, const vector<vector<int>>& G) {
    int n = G.size();
    //D_minus_1 = D_0 = D_plus_1 = vector<vector<int>>(n, vector<int>(n, INF));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (G[i][j] == -1) {
                D_minus_1[i][j] = -1;
            } else if (G[i][j] == 1) {
                D_plus_1[i][j] = 1;
            } else if (G[i][j] == 0) {
                D_0[i][j] = 0;
            } 
        }
    }
}