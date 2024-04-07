#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "Lab_8.h"
#include "doctest.h"

TEST_CASE("Linked List Tests") {

    SUBCASE("Linked List Build") {
        LinkedList list0;
        list0.build_node_list(0);
        CHECK(list0.get_NodeCount() == 0);
        CHECK(list0.get_root()->next == nullptr);

        LinkedList list2;
        list2.build_node_list(2);
        CHECK(list2.get_NodeCount() == 2);
        CHECK(list2.get_root()->next != nullptr);
        CHECK(list2.get_root()->next.use_count() == 1);
        CHECK(list2.get_root()->next->next != nullptr);
        CHECK(list2.get_root()->next->next.use_count() == 1);
        CHECK(list2.get_root()->next->next->next == nullptr);        
        CHECK(list2.get_root()->next->next->next.use_count() == 0);   
        list2.print_node_list_shared_ptrs();
        auto list2_copyNodes = list2.build_copyNodes_weak_ptrs();


        auto current = list2.get_root()->next;
        while(current != nullptr) {
            CHECK(current.use_count() == 2);
            current = current->next;
        }

        list2.print_node_array_weak_ptrs(list2_copyNodes);
        for(int i = 0; i < list2.get_NodeCount(); i++) {
            CHECK(list2_copyNodes[i].weak_node_ptr.use_count() == 1);
        }

        list2.delete_node_shared_ptr_list();
        CHECK(list2.get_root() == nullptr);

        for(int i = 0; i < list2.get_NodeCount(); i++) {
            CHECK(list2_copyNodes[i].weak_node_ptr.use_count() == 0);
        }
    }
}