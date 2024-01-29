#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Lab 1.h"

TEST_CASE("Testing sum_prefix function") {
    SUBCASE("Full Array") {
        int test_array[] = {1, 1, -1, -1};
        int prefix_sums[4];

        // Test sum_prefix function
        sum_prefix(test_array, 4, prefix_sums);

        // Check if the prefix sums are correct
        CHECK(prefix_sums[0] == 1);
        CHECK(prefix_sums[1] == 2);
        CHECK(prefix_sums[2] == 1);
        CHECK(prefix_sums[3] == 0);
    }

    SUBCASE("Empty Array") {
        int empty_array[] = {};
        int empty_prefix_sums[] = {};

        sum_prefix(empty_array, 0, empty_prefix_sums);

        CHECK(empty_prefix_sums[0] == 0);
    }

}

TEST_CASE("Testing non_neg_prefix_sum function") {
    SUBCASE("Full Array") {
        int test_array1[] = {1, 1, -1, -1};   // Non-negative prefix sums
        int test_array2[] = {1, -1, -1, 1};  // Contains a negative prefix sum

        // Test non_neg_prefix_sum function
        CHECK(non_neg_prefix_sum(test_array1, 4) == true);
        CHECK(non_neg_prefix_sum(test_array2, 4) == false);
        }

    SUBCASE("Empty Array") {
        int empty_array[] = {};

        CHECK(non_neg_prefix_sum(empty_array, 0) == true);
    }
}

TEST_CASE("Testing non_pos_prefix_sum function") {
    SUBCASE("Full Array") {
        int test_array1[] = {-1, -1, -1, 1};  // Non-positive prefix sums
        int test_array2[] = {1, -1, 1, 1};      // Contains a positive prefix sum

        // Test non_pos_prefix_sum function
        CHECK(non_pos_prefix_sum(test_array1, 4) == true);
        CHECK(non_pos_prefix_sum(test_array2, 4) == false);
    }

    SUBCASE("Empty Array") {
        int empty_array[] = {};

        CHECK(non_pos_prefix_sum(empty_array, 0) == true);
    }
}
