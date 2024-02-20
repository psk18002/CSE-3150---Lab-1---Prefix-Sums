#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <cstdlib>
#include <iostream>
#include <random>
#include "doctest.h"
#include "Lab 4.h"

using namespace std;

int array_0[] = {};
int array_1[] = {1, -1};

int first1 = -99;
int save_first1 = first1;
int second1 = 4;
int save_second1 = second1;

int i = swap(&first1, &second1);

TEST_CASE("Fisher-Yates") {

    SUBCASE("Swap Tests") {
        CHECK_EQ(save_first1, second1);
        CHECK_EQ(save_second1, first1);
    }

    SUBCASE("BALANCED LIST CHECKS W/ STD::RAND AND SRAND") {
        cout << "RAND AND SRAND SEED GENERATOR" << endl;
        const int num_test_arrays = 200000;
        const int test_arrays_size = 3;
        int test_arrays[num_test_arrays][2*test_arrays_size];

        int num_balanced = 0;
        int num_imbalanced = 0;
        for (int i = 0; i < num_test_arrays; i++) {
            balanced_list(test_arrays[i], 2*test_arrays_size);
            srand(time(0) + i * (i + 1));
            fisher_yates(test_arrays[i], 2*test_arrays_size, rand);
            if (balanced_list_check(test_arrays[i], 2*test_arrays_size)) {
                num_balanced++;
            } else {
                num_imbalanced++;
            }
        }
        cout << "# OF BALANCED LISTS: " << num_balanced << endl;
        cout << "# OF IMBALANCED LISTS: " << num_imbalanced << endl;
        double percent_balanced = ((double)num_balanced/200000) * 100;
        cout << "% OF BALANCED LISTS: " << percent_balanced << endl;
    }

    SUBCASE("BALANCED LIST CHECKS W/ STD::RAND AND RANDOM_DEVICE") {
        cout << "RAND AND RANDOM_DEVICE SEED GENERATOR" << endl;
        const int num_test_arrays = 200000;
        const int test_arrays_size = 3;
        int test_arrays[num_test_arrays][2*test_arrays_size];
        random_device rd;

        int num_balanced = 0;
        int num_imbalanced = 0;
        for (int i = 0; i < num_test_arrays; i++) {
            balanced_list(test_arrays[i], 2*test_arrays_size);
            rd();
            fisher_yates(test_arrays[i], 2*test_arrays_size, rand);
            if (balanced_list_check(test_arrays[i], 2*test_arrays_size)) {
                num_balanced++;
            } else {
                num_imbalanced++;
            }
        }
        cout << "# OF BALANCED LISTS: " << num_balanced << endl;
        cout << "# OF IMBALANCED LISTS: " << num_imbalanced << endl;
        double percent_balanced = ((double)num_balanced/200000) * 100;
        cout << "% OF BALANCED LISTS: " << percent_balanced << endl;
    }

    SUBCASE("BALANCING 2N+1 ARRAYS") {
                
        int array[9] = {1, -1, -1, 1, 1, -1, 1, -1, -1};
        int lowest_depth_index = lowest_valley_index(array, 9);
        CHECK_EQ(lowest_depth_index, 2);

        int* result = well_balanced_list(array, 9, 2);
        CHECK_EQ(result[0], 1);
        CHECK_EQ(result[1], 1);
        CHECK_EQ(result[2], -1);
        CHECK_EQ(result[3], 1);
        CHECK_EQ(result[4], -1);
        CHECK_EQ(result[5], -1);
        CHECK_EQ(result[6], 1);
        CHECK_EQ(result[7], -1);
        CHECK_EQ(result[8], 0);

    }
}