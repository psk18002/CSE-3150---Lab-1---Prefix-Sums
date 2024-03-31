#include <iostream>
#include <cmath>
#include <fstream>
#include <algorithm>

#include "Lab_7.h"

using namespace std;

vector<double> doubles_read(istream & in_stream, const string & terminal) {
    vector<double> res;
    for(double i; in_stream >> i && std::to_string(i) != terminal; ) {
        res.push_back(i);
    }

    if (in_stream.eof())
        return res;
    
    if (in_stream.fail()) {
        in_stream.clear();
        string s;
        if (in_stream >> s && s == terminal) {
            return res;
        }
        in_stream.setstate(ios_base::failbit);
    }
  
    return res;
};


vector<vector<double>> doubles_read_matrix(istream & in_stream) {
    
    vector<vector<double>> matrix;
    string line;
    
    while (! in_stream.eof() ) {
        getline(in_stream, line);
        istringstream is_line(line);
        matrix.push_back(doubles_read(is_line, line));
    }

    return matrix;
}

double square(const double & d){
    return d*d;
}

double dot_product(const vector<double> & one, const vector<double> & two) {
    double dot_prod = 0.0;
    for (int i = 0; i < one.size(); i++) {
        dot_prod += one.at(i) * two.at(i);
    }
    return dot_prod;
}

double magnitude(const vector<double> & vec) {
    double sq_sum = 0.0;
    for (double val : vec) {
        sq_sum += square(val);
    }
    return sqrt(sq_sum);
};

double cosine_distance(const vector<double> & one, const vector<double>& two) {
    double dot_prod = dot_product(one, two);
    double one_magnitude = magnitude(one);
    double two_magnitude = magnitude(two);

    double d = dot_prod/(one_magnitude*two_magnitude) ;

    return acos(d);
}

vector<pairwise_output> sorted_cos_dist_computation(vector<vector<double>> & matrix) {
    
    vector<pairwise_output> pairs;
    
    for (int i = 0; i < matrix.size()-1; i++) {

        cout << "Pairings for vector: " << matrix.at(i) << endl;

        for (int j = i + 1; j < matrix.size(); j++) {

            double cos_dist = cosine_distance(matrix.at(i), matrix.at(j));
            cout << "\t" << matrix.at(j) << " = " << cos_dist << " radians" << endl;
            pairwise_output pair = pairwise_output(matrix.at(i), matrix.at(j), cos_dist);
            pairs.push_back(pair);
        }
    }

    sort(pairs.begin(), pairs.end(), [](const pairwise_output & one, const pairwise_output & two) {
        return one.cos_dist < two.cos_dist;
    });

    return pairs;
}

void print_sorted_cos_dists(vector<pairwise_output> & pairs) {
    
    cout << "\n-----------------------------------------\nSorted Cosine Distances:" << endl;
    for (pairwise_output pair : pairs) {
        cout << "Vector Pairing: " << pair << endl;
    }

}