#include <iostream>
#include "Lab 1.h"

using namespace std;

int main() {
    int array[] = {1, -1, 1, -1};
    int length = sizeof(array)/sizeof(array[0]);
    int prefix_sums[length];

    cout << "Prefix Sums of { ";
    for (int i : array) {
        cout << i << " ";
    }
    cout << "}" << endl;
    cout << boolalpha;
    cout << non_neg_prefix_sum(array, length) << endl;
    cout << non_pos_prefix_sum(array, length) << endl;
    
}