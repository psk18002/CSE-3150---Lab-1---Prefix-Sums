#include <iostream>
#include "Lab 2.h"

using namespace std;

void print_array(int* array, int len) {
    for (int i = 0; i < len; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int swap(int * first, int * second) {
    int temp = *first;
    *first = *second;
    *second = temp;
    return 0;
}

int* sum_prefix(int array[], int length, int prefix_sums[]) {
    int sum = 0;
    //cout << "{ ";
    if (length != 0) {
        for (int i = 0; i < length; i++) {
            sum += array[i];
            prefix_sums[i] = sum;
            //cout << prefix_sums[i] << " ";
        }
    } else {
        prefix_sums[0] = 0;
    }
    //cout << "}" << endl;

    return prefix_sums;
}

void fisher_yates(int array[], const int length, int (* rand_func)()) {
    for (int i = 0; i < length; i++) {
        int rand_location = rand_func() % (length - 2);
        //cout << "Index " << i << ": " << rand_location << endl;
        swap(& array[i], & array[rand_location]);
    }
    //print_array(array, length);
}

void swap_list_scramble(int array[], const int length) {
    for (int i = 0; i < length/2; i++) {
        swap(& array[i], & array[i+(length/2)]);
    }
    print_array(array, length);
}

void balanced_list(int array[], const int length) {
    for (int i = 0; i < length/2; i++) {
        array[i] = 1;
    }

    for (int i = 0; i < length/2; i++) {
        array[i+(length/2)] = -1;
    }
    //print_array(array, length);
}

bool non_neg_prefix_sum(int array[], int length) {

    int prefix_sums[length];

    sum_prefix(array, length, prefix_sums);

    //cout << "For Non-negative Prefix Sums:" << endl;
    for (int i = 0; i < length; i++){
        if (prefix_sums[i] < 0) {
            //cout << "FALSE @ Index " << i << "\n" << endl;
            return false;
        }
    }
    //cout << "TRUE!\n" << endl;

    return true;
}

bool non_pos_prefix_sum(int array[], int length) {

    int prefix_sums[length];

    sum_prefix(array, length, prefix_sums);

    //cout << "For Non-positive Prefix Sums:" << endl;
    for (int i = 0; i < length; i++) {
        if (prefix_sums[i] > 0) {
            //cout << "FALSE @ Index " << i << "\n" << endl;
            return false;
        }
    }
    //cout << "TRUE!\n" << endl;
    return true;
}

bool balanced_list_check(int array[], int length) {
    if (non_pos_prefix_sum(array, length)) {
        return false;
    } else if ( non_neg_prefix_sum(array, length)) {
        return true;
    }
}

void list_symbols_visualizer(int array[], int length) {
    
    for (int i = 0; i < length; i++) {
        if (array[i] == 1) {
            cout << "( ";
        } else if (array[i] == -1) {
            cout << ") ";
        }
    
    }
    cout << endl; 
}