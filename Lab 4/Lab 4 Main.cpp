#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>
#include "Lab 4.h"

using namespace std;

int main() {

    string n_string;
    int n;

    cout << "Enter the desired number of open-parentheses: "<< endl;
    cin >> n_string;
    n = stoi(n_string);

    int array1[2*n+1];

    cout << boolalpha;
    /*
    cout << "BALANCED ARRAY 1 INITIALIZATION TEST:" << endl; 
    balanced_list_2n_1(array1, 2*n+1);
    cout << balanced_list_check(array1, 2*n+1) << endl;
    cout << lowest_valley_index(array1, 2*n+1) << endl;
    
    cout << "ARRAY 1 VISUALIZATION TEST" << endl;
    list_symbols_visualizer(array1, 2*n+1);

    fisher_yates(array1, 2*n+1, rand);

    cout << "ARRAY 1 SCRAMBLED VISUALZIATION" << endl;
    list_symbols_visualizer(array1, 2*n+1);
    */
    
    int array[9] = {1, -1, -1, 1, 1, -1, 1, -1, -1};
    cout << lowest_valley_index(array, 9) << endl;
    list_symbols_visualizer(array, 9);

    int* result = well_balanced_list(array, 9, 2);
    list_symbols_visualizer(result, 9);
    print_array(result, 9);
    
    return 0;
}