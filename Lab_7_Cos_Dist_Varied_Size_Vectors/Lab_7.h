#ifndef _LAB_7_H_
#define _LAB_7_H_

#include <iostream>
#include <cmath>
#include <vector>
#include <ostream>
#include <string>
#include <istream>
#include <sstream>
#include <fstream>

using namespace std;

template<typename T>
ostream & operator << (ostream& os, const vector<T> & vec) {
    os << "( ";
    for (T val : vec) {
        os << val << " ";
    }
    os << ")";

    return os;
}

vector<double> doubles_read(istream & in_stream, const string & terminal);
vector<vector<double>> doubles_read_matrix(istream & in_stream);

double square(const double & d);
double dot_product(const vector<double> & one, const vector<double> & two) ;
double magnitude(const vector<double> & my_vector);
double cosine_distance(const vector<double> & one, const vector<double>& two);

struct pairwise_output {
    vector<double> one;
    vector<double> two;
    double cos_dist;

    pairwise_output(const vector<double> & one, const vector<double> & two, const double cos_dist) : one(one), two(two), cos_dist(cos_dist) {};
    
    friend ostream& operator << (ostream &os, const pairwise_output& po){
        os << po.one << " & " << po.two << "\n\tCosine Distance of Vectors: " << po.cos_dist << " radians";
        return os;
    }    

};

vector<pairwise_output> sorted_cos_dist_computation(vector<vector<double>> & vdv);

void print_sorted_cos_dists(vector<pairwise_output> & pairs);

#endif