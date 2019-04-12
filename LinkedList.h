#ifndef LINKEDLISTVSBINARYTREE_LINKEDLIST_H
#define LINKEDLISTVSBINARYTREE_LINKEDLIST_H
#include "Location.h"

namespace UTEC {

    struct Node {
        Location data;
        Node* right;
        Node* left;
        explicit Node(const Location&);
    };

    class LinkedList {
        Node* head;
        Node* tail;

    public:
        LinkedList();
        ~LinkedList();
        int size();
        bool is_empty();
        Node* get_head();
        Node* get_tail();
        void add_head(const Location& data);
        void add_tail(const Location& data);
        void print();
        void insert(int posicion, const Location& data);
        void search(int position_id);
    };
    void load_locations(LinkedList* linked_list, std::string file_name);
}

#endif //LINKEDLISTVSBINARYTREE_LINKEDLIST_H
