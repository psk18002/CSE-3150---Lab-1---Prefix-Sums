#ifndef _EXPENSIVEDEP_H
#define _EXPENSIVEDEP_H

#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

vector<vector<int>> expensiveDigraphExactPaths(vector<vector<int>>& D_minus_1, vector<vector<int>>& D_0, vector<vector<int>>& D_plus_1);
vector<vector<int>> readGraphFromFile(const string& filename);

#endif