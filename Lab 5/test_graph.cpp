#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <sstream>
#include <vector>
#include <fstream>

#include "doctest.h"
#include "adjMat.h"
#include "expensiveDEP.h"

using namespace std;

TEST_CASE("adjMat FUNCTIONS") {

    SUBCASE("adjMat READ") {

        vector<vector<int>> test_vec;

        readAdjacencyMatrix("graph_0.txt", test_vec);

        vector<vector<int>> comp_vec = {{0, 2, 2, 2, 2, 2 }, { 2, 0, 2, 2, 2, 2 }, { 2, 2, 0, 2, 2, 2 }, { 2, 2, 2, 0, 2, 2 }, { 2, 2, 2, 2, 0, 2 }, { 2, 2, 2, 2, 2, 0 }};

        CHECK_EQ(test_vec, comp_vec); 
    }

    SUBCASE("adjMAT INIT") {

        vector<vector<int>> D_0, D_minus_1, D_plus_1;
        vector<vector<int>> graph = readGraphFromFile("loop_graph.txt");
        D_minus_1 = D_0 = D_plus_1 = vector<vector<int>>(4, vector<int>(4, 2));

        initAdjacencyMatrices(D_minus_1, D_0, D_plus_1, graph);

        vector<vector<int>> comp_vec = {{2, 2, 0, 0}, {0, 0, 2, 0}, {0, 0, 0, 2}, {2, 0, 0, 0}};

        CHECK_EQ(D_0, comp_vec);
    }
}

TEST_CASE("expensiveDEP FUNCTIONS") {

    SUBCASE("expensiveDEP READ") {

        vector<vector<int>> test_vec;

        test_vec = readGraphFromFile("loop_graph.txt");

        vector<vector<int>> comp_vec = {{-1, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}, {1, 0, 0, 0}};

        CHECK_EQ(test_vec, comp_vec);
    }

    SUBCASE("expensiveDEP ALGORITHM w/ ZERO-COST PATHS") {

        vector<vector<int>> D_0, D_minus_1, D_plus_1;
        vector<vector<int>> graph = readGraphFromFile("loop_graph.txt");
        D_minus_1 = D_0 = D_plus_1 = vector<vector<int>>(4, vector<int>(4, 2));

        initAdjacencyMatrices(D_minus_1, D_0, D_plus_1, graph);
        expensiveDigraphExactPaths(D_minus_1, D_0, D_plus_1);
        
        vector<vector<int>> comp_vec = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

        CHECK_EQ(D_0, comp_vec);
    }

    SUBCASE("expensiveDEP ALGORITHM w/ BARBELL GRAPH") {

        vector<vector<int>> D_0, D_minus_1, D_plus_1;
        vector<vector<int>> graph = readGraphFromFile("graph_barbell.txt");
        D_minus_1 = D_0 = D_plus_1 = vector<vector<int>>(7, vector<int>(7, 2));

        initAdjacencyMatrices(D_minus_1, D_0, D_plus_1, graph);
        expensiveDigraphExactPaths(D_minus_1, D_0, D_plus_1);
        
        vector<vector<int>> comp_vec = {{0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}};

        CHECK_EQ(D_0, comp_vec);
    }

}