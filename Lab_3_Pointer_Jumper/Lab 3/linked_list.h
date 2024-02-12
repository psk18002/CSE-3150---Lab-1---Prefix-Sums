#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

struct node {
    int data;
    struct node * next;
    struct node * jumper;
};

struct node * build_new_linked_list(int total_new_elements);
void print_linked_list(struct node * start);
void delete_linked_list(struct node *& start);
struct node * pointer_jumper_recursive(struct node * start);
struct node * pointer_jumper_bruteforce(struct node * start);
struct node * get_linked_list_node(struct node * start, int node_number, int total_elements);
int get_linked_list_data_item_value(struct node * start, int node_number, int total_elements);

#endif