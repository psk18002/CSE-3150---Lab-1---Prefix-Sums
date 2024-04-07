#ifndef _LAB_8_HEADER_
#define _LAB_8_HEADER_

#include <iostream>
#include <memory>

using namespace std;

template <typename T>
ostream & operator << (ostream & os, shared_ptr<T> p) {
    return os << p.get() << " shared_ptr count : [" << p.use_count() << "]";
}

template <typename T>
ostream & operator << (ostream & os, weak_ptr<T> p) {
    T * raw = nullptr;

    {
        auto sp = p.lock();
        raw = sp.get();
    }

    return os << "weak_ptr to " << raw << " shared_ptr count : [" << p.use_count() << "]";
}

struct LinkedList {
    
    public:
        struct Node {
            int data;
            shared_ptr<Node> next;
            Node() {};
            Node(Node * node) : data{node->data}, next{node->next} {};
            Node(int data, shared_ptr<Node> ptr) : data{data}, next{ptr} {};
        };

        struct CopyNode {
            weak_ptr<Node> weak_node_ptr;
        };

        void build_node_list(int k);
        CopyNode * build_copyNodes_weak_ptrs();
        void delete_node_shared_ptr_list();
        void print_node_list_shared_ptrs();
        void print_node_array_weak_ptrs(CopyNode * array);
        shared_ptr<Node> get_root();
        int get_NodeCount();

        LinkedList();
        ~LinkedList();


    private:

        shared_ptr<Node> root;

        int nodeCount;
};

#endif