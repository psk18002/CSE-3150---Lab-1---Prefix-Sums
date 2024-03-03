#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "adjMat.h"
#include "expensiveDEP.h"

using namespace std;

int main() {

    vector<vector<int>> D_0, D_plus_1, D_minus_1;
    D_0 = D_plus_1 = D_minus_1 = vector<vector<int>>(6, vector<int>(6, 2));
    //readAdjacencyMatrix("graph_0.txt", D_0);
    //readAdjacencyMatrix("graph_1.txt", D_plus_1);
    //readAdjacencyMatrix("graph_m1.txt", D_minus_1);

    // Read the graph from file
    vector<vector<int>> graph = readGraphFromFile("graph_g.txt");
    
    // Initialize adjacency matrices
    initAdjacencyMatrices(D_minus_1, D_0, D_plus_1, graph);

    // Compute expensive digraph exact paths
    expensiveDigraphExactPaths(D_minus_1, D_0, D_plus_1);

    // Output the resulting matrices D_minus_1, D_0, D_plus_1
    cout << "D_minus_1:" << endl;
    for (const auto& row : D_minus_1) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "D_0:" << endl;
    for (const auto& row : D_0) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "D_plus_1:" << endl;
    for (const auto& row : D_plus_1) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}