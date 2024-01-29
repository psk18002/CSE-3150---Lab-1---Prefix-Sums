#include <iostream>
#include "Lab 1.h"

using namespace std;

int* sum_prefix(int array[], int length, int prefix_sums[]) {
    int sum = 0;
    cout << "{ ";
    if (length != 0) {
        for (int i = 0; i < length; i++) {
            sum += array[i];
            prefix_sums[i] = sum;
            cout << prefix_sums[i] << " ";
        }
    } else {
        prefix_sums[0] = 0;
    }
    cout << "}" << endl;

    return prefix_sums;
}

bool non_neg_prefix_sum(int array[], int length) {

    int prefix_sums[length];

    sum_prefix(array, length, prefix_sums);

    cout << "For Non-negative Prefix Sums:" << endl;
    for (int i = 0; i < length; i++){
        if (prefix_sums[i] < 0) {
            cout << "FALSE @ Index " << i << "\n" << endl;
            return false;
        }
    }
    cout << "TRUE!\n" << endl;

    return true;
}

bool non_pos_prefix_sum(int array[], int length) {

    int prefix_sums[length];

    sum_prefix(array, length, prefix_sums);

    cout << "For Non-positive Prefix Sums:" << endl;
    for (int i = 0; i < length; i++) {
        if (prefix_sums[i] > 0) {
            cout << "FALSE @ Index " << i << "\n" << endl;
            return false;
        }
    }
    cout << "TRUE!\n" << endl;
    return true;
}