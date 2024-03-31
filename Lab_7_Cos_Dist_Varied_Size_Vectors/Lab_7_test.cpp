#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "Lab_7.h"
#include <cmath>

using namespace std;

TEST_CASE("Testing ALL Functions") {
    
    SUBCASE("Base Cases for Cosine Distance-Related Functions") {

        //cosine_dist between vectors (1.0, 1.0) and (1.0, 1.0)
        vector<double> v2d;
        v2d.push_back(1.0);
        v2d.push_back(1.0);

        CHECK(2.0 == dot_product(v2d, v2d));
        double actual_mag = magnitude(v2d);
        double sq = sqrt(2.0);
        CHECK(fabs(sq - actual_mag) < sq * 0.001);
        double answer_acos = cosine_distance(v2d, v2d);
        CHECK(answer_acos < 0.0001);

        //cosine_dist between vectors (1.0, 0.0) and (-1.0, 0.0)

        vector<double> one;
        one.push_back(1.0);
        one.push_back(0.0);

        vector<double> two;
        two.push_back(-1.0);
        two.push_back(0.0);

        double answer_acos_one_two = cosine_distance(one, two);

        CHECK(M_PI == answer_acos_one_two);

        //cosine_dist between vectors given from lecture
        vector<double> c;
        c.push_back(2.7);
        c.push_back(7.0);
        double answer_acos_c = cosine_distance(c, c);
        //CHECK(0 == answer_acos_c);

        double actual_dot_prod = dot_product(c, c);
        CHECK(56.29 == actual_dot_prod);

        double actual_mag_c = magnitude(c);
        CHECK(7.502666 - actual_mag_c < 0.000001);

        //Bit representation of actual magnitude and rote answer is different due to infinitesimal deficit
        CHECK(1 - (actual_dot_prod/(actual_mag_c * actual_mag_c)) < 0.000001);
    }

    SUBCASE("Base Cases for 2D Vector Input Function(s)") {

        ifstream in_file;
        in_file.open("vectors_2D.txt");

        vector<vector<double>> vdv = doubles_read_matrix(in_file);

        int vdv_index = 0;
        
        while(! in_file.eof()) {
            int vec_index = 0;
            for(double i; in_file >> i && to_string(i) != "\n"; ) {    
                CHECK(i == vdv.at(vdv_index).at(vec_index));
                vec_index++;
            }
            vdv_index++;
        }

        in_file.close();
    }

    SUBCASE("Base Case for Sorting Vector Pairings by Cosine Distances Function(s)") {

        ifstream in_file;
        in_file.open("vectors_2D.txt");

        vector<vector<double>> vdv = doubles_read_matrix(in_file);
        vector<pairwise_output> sorted_output = sorted_cos_dist_computation(vdv);
        double array[] = {0.0123756, 0.0522779, 0.0971839, 0.10956, 0.149462, 0.161837, 0.28354, 0.295915, 0.393099, 0.445377};

        for(int i = 0; i < sorted_output.size()-1; i++) {
            //Infinitesimal Deficit check with doctest double value(s) comparisons w/ Approx().epsilon()
            CHECK(doctest::Approx(array[i]).epsilon(0.01) == sorted_output.at(i).cos_dist);
        }
    }
}