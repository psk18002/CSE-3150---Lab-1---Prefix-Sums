#include "Lab_8.h"

LinkedList::LinkedList() : root(make_shared<Node>(Node(0, nullptr))), nodeCount(0) {}

LinkedList::~LinkedList() {
    delete_node_shared_ptr_list();
}

void LinkedList::build_node_list(int k) {
    if (k <= 0) {
        return;
    }

    nodeCount = k;
    auto current = root;
    for (int i = 1; i <= k; i++) {
        current->next = make_shared<Node>(Node(i, nullptr));
        current = current->next;
    }
}

LinkedList::CopyNode * LinkedList::build_copyNodes_weak_ptrs() {
    CopyNode * copyNodesArray = new CopyNode[nodeCount];
    auto current = root->next;
    for (int i = 0; i < nodeCount; i++) {
        copyNodesArray[i].weak_node_ptr = current;
        current = current->next;
    }
    return copyNodesArray;
}

void LinkedList::delete_node_shared_ptr_list() {
    root.reset();
}

void LinkedList::print_node_list_shared_ptrs() {
    auto current = root;
    while(current != NULL && current->next) {
        cout << "data: " << current->next->data << "; " << current->next << endl;
        current = current->next;
    }
}

void LinkedList::print_node_array_weak_ptrs(LinkedList::CopyNode * array) {
    for (int i = 0; i < nodeCount; i++) {
        if (array[i].weak_node_ptr.expired()) {
            cout << "Shared Pointer Expired : " << array[i].weak_node_ptr << endl;
        } else {        
            cout << array[i].weak_node_ptr << endl;
        }
    }
}

shared_ptr<LinkedList::Node> LinkedList::get_root() {
    return root;
}

int LinkedList::get_NodeCount() {
    return nodeCount;
}
