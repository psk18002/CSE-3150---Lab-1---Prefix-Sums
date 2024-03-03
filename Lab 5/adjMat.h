#ifndef _ADJMAT_H
#define _ADJMAT_H

#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

void readAdjacencyMatrix(const string& filename, vector<vector<int>>& matrix);
void initAdjacencyMatrices(vector<vector<int>>& D_minus_1, vector<vector<int>>& D_0, vector<vector<int>>& D_plus_1, const vector<vector<int>>& G);

#endif