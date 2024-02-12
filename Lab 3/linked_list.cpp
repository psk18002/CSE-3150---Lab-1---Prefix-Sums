#include <iostream>

#include "linked_list.h"

using namespace std;

/*
build_new_linked_list:
	returns a pointer to the first node in the linked list
    If 0 == total_new_elements, then return null
*/
struct node * build_new_linked_list(int total_new_elements) {
    if (0 == total_new_elements) {
        return NULL;
    } else {
        struct node * root = new node;
        root->data = -1;
        struct node * linked_list = root;

        for (int i = 0 ; i < total_new_elements; i++) {
            linked_list->next = new node;
            linked_list->jumper = linked_list->next;
            linked_list->data = i+1;
            linked_list = linked_list->next;
        }
        return root;
    }
}
/*
get_linked_list_data_item_value:

    returns -1 if not enough nodes
*/
int get_linked_list_data_item_value(struct node * start, int node_number, int total_elements) {
    if (node_number > total_elements) {
        return -1;
    } else {
        struct node * linked_list = start;

        for (int i = 0; i < node_number -1; i++) {
            linked_list = linked_list->next;
        }

        return linked_list->data;
    }
}

void print_linked_list(struct node * start, int total_elements) {
    struct node * linked_list =  start;

    for (int i = 0; i < total_elements; i++) {
        cout << linked_list->data << endl;
        linked_list = linked_list->next;
    }
}

/*
update_data_in_linked_list:
	Returns false if node_to_update > total_elements
	Returns true otherwise
*/
bool update_data_in_linked_list(struct node * start, 
    int node_to_update, 
    int update_val, 
    int total_elements) {

        return true;

    }

void delete_linked_list(struct node *& start) {

    node * current = start;
    node * nextNode;

    while (current != NULL) {
        nextNode = current->next;
        delete current;
        current = nextNode;         
    }

    start = nullptr;
}

struct node * pointer_jumper_bruteforce(struct node * start) {
    if (start == nullptr || start->next == nullptr) {
        return NULL;
    }

    node * last = start;
    while(last->next != nullptr) {
        last = last->next;
    }

    node * current = start;
    while (current->next != nullptr) {
        current->jumper = last;
        current = current->next;
    }

    return last;
}

struct node * pointer_jumper_recursive(struct node * start) {
    if (start->next == NULL || start->next == start) {
        return start;
    } else {
        node * last = pointer_jumper_recursive(start->next);
        start->jumper = last;
        return last;
    }

}

struct node * get_linked_list_node(struct node * start, int node_number, int total_elements) {
    if (node_number > total_elements) {
        return NULL;
    } else {
        struct node * target = start;

        for (int i = 0; i < node_number -1; i++) {
            target = target->next;
        }

        return target;
    }
}