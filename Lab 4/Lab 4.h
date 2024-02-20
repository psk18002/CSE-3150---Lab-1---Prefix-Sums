#ifndef _LAB_4_H
#define _LAB_4_H

void print_array(int * array, int len);
int swap(int * first, int * second);
void fisher_yates(int array[], const int length, int (* rand_func)());
void swap_list_scramble(int array[], const int length);
void balanced_list(int array[], const int length);
bool non_neg_prefix_sum(int array[], int length);
bool non_pos_prefix_sum(int array[], int length);
void list_symbols_visualizer(int array[], int length);
bool balanced_list_check(int array[], int length);

//LAB 4
void balanced_list_2n_1(int array[], const int length);
int lowest_valley_index(int array[], const int length);
int * well_balanced_list(int array[], const int length, int lowest_depth_index);

#endif