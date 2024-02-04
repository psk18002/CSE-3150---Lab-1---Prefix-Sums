#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>
#include "Lab 2.h"

using namespace std;

int main() {

    string n_string;
    int n;

    cout << "Enter the desired number of open-parentheses: "<< endl;
    cin >> n_string;
    n = stoi(n_string);

    int array1[2*n];
    int array2[2*n];

    cout << boolalpha;
    /*
    cout << "BALANCED ARRAY 1 INITIALIZATION TEST:" << endl; 
    balanced_list(array1, 2*n);
    cout << balanced_list_check(array1, 2*n) << endl; 
    
    cout << "ARRAY 1 VISUALIZATION TEST" << endl;
    list_symbols_visualizer(array1, 2*n);
    */
    cout << "BALANCED ARRAY 2 INITIALIZATION TEST:" << endl; 
    balanced_list(array2, 2*n);
    cout << balanced_list_check(array2, 2*n) << endl; 
    /*
    cout << "ARRAY 2 VISUALIZATION TEST" << endl;
    list_symbols_visualizer(array2, 2*n);
    cout << "BASIC SWAP LIST SCRAMBLE TEST (ARRAY 1):" << endl; 
    swap_list_scramble(array1, 2*n);
    cout << balanced_list_check(array1, 2*n) << endl; 
    
    cout << "SCRAMBLED VISUALIZATION TEST (ARRAY 1):" << endl;
    list_symbols_visualizer(array1, 2*n);
    */
    srand(time(0));
    cout << "FISHER-YATES TEST (ARRAY 2):" << endl; 
    fisher_yates(array2, 2*n, rand);
    cout << "FISHER-YATES VISUALIZATION TEST (ARRAY 2):" << endl;
    list_symbols_visualizer(array2, 2*n);
    cout << "FISHER-YATES BALANCED CHECK TEST (ARRAY 2):" << endl;
    cout << balanced_list_check(array2, 2*n) << endl; 

    const int num_test_arrays = 10000;
    const int test_arrays_size = 3;
    int test_arrays[num_test_arrays][2*test_arrays_size];

    int num_balanced = 0;
    int num_imbalanced = 0;
    for (int i = 0; i < num_test_arrays; i++) {
        balanced_list(test_arrays[i], 2*test_arrays_size);
        srand(time(0) + i % test_arrays_size);
        fisher_yates(test_arrays[i], 2*test_arrays_size, rand);
        if (balanced_list_check(test_arrays[i], 2*test_arrays_size)) {
            num_balanced++;
        } else {
            num_imbalanced++;
        }
    }
    cout << "# OF BALANCED LISTS: " << num_balanced << endl;
    cout << "# OF IMBALANCED LISTS: " << num_imbalanced << endl;
    double percent_balanced = ((double)num_balanced/10000) * 100;
    cout << "% OF BALANCED LISTS: " << percent_balanced << endl;

    return 0;
}