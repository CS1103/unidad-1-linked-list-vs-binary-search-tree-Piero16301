#include <iostream>
#include "LinkedList.h"

UTEC::Node::Node(const Location & data): data{data}, right{nullptr}, left{nullptr}{}

UTEC::LinkedList::LinkedList(): head{nullptr}, tail{nullptr}{};

UTEC::LinkedList::~LinkedList() {
    Node* temporal = head;
    while (temporal->right != nullptr) {
        delete temporal;
        temporal = temporal->right;
    }
    delete temporal;
}

int UTEC::LinkedList::size() {
    int count = 0;
    Node* actual = head;
    while(actual != nullptr) {
        count++;
        actual = actual->right;
    }
    return count;
}

bool UTEC::LinkedList::is_empty() {
    return head == nullptr;
}

UTEC::Node *UTEC::LinkedList::get_head() {
    return head;
}

UTEC::Node *UTEC::LinkedList::get_tail() {
    return tail;
}

void UTEC::LinkedList::add_head(const Location& data) {
    Node* temp = new Node(data);
    if (is_empty()) {
        tail = temp;
        head = temp;
    } else {
        temp->right = head;
        head->left = temp;
        head = temp;
    }
}

void UTEC::LinkedList::add_tail(const Location& data) {
    Node* temp = new Node(data);
    if (is_empty()) {
        tail = temp;
        head = temp;
    } else {
        tail->right = temp;
        temp->left = tail;
        tail = temp;
    }
}

void UTEC::LinkedList::print() {
    if (is_empty()) {
        std::cout << "La lista esta vacia." << '\n';
    } else {
        Node* temporal = head;
        while (temporal != nullptr) {
            temporal->data.printLocation();
            temporal = temporal->right;
        }
        delete temporal;
    }
}

void UTEC::LinkedList::insert(int posicion, const Location &data) {
    Node* insertado = new Node(data);
    Node* temporal = head;
    for (int i = 1; i < posicion; ++i) {
        temporal = temporal->right;
    }
    insertado->left = temporal;
    insertado->right = temporal->right;
    temporal->right = insertado;
}

void UTEC::LinkedList::search(int position_id) {
    Node* temporal = head;
    int contador = 1;
    while (temporal->data.get_position_id() != position_id) {
        temporal = temporal->right;
        contador++;
    }
    std::cout << "Posicion de " << position_id << " en la lista es: " << contador << '\n';
    temporal->data.printLocation();
}