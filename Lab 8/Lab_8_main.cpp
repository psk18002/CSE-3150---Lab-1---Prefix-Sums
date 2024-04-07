#include "Lab_8.h"

int main() {
    LinkedList list;
    list.build_node_list(5);
    cout << "Root Node Shared Pointer: " << list.get_root() << endl;

    cout << "Original Linked List:" << endl;
    list.print_node_list_shared_ptrs();


    auto copyNodesArray = list.build_copyNodes_weak_ptrs();

    cout << "Weak pointers to original (shared_ptrs) linked list:" << endl;
    list.print_node_array_weak_ptrs(copyNodesArray);


    list.delete_node_shared_ptr_list();

    cout << "Deleted orignal linked list:" << endl;
    list.print_node_list_shared_ptrs();

    cout << "Weak pointers after deletion:" << endl;
    list.print_node_array_weak_ptrs(copyNodesArray);

    delete[] copyNodesArray;

    return 0;
}