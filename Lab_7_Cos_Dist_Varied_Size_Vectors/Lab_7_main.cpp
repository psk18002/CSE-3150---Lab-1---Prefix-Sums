#include "Lab_7.h"

using namespace std;

int main() {

    ifstream in_file;

    in_file.open("vectors_3D_2.txt");
    vector<vector<double>> matrix = doubles_read_matrix(in_file);

    in_file.close();

    vector<pairwise_output> pairs = sorted_cos_dist_computation(matrix);
    print_sorted_cos_dists(pairs);

    return 0;
}