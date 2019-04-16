#ifndef LINKEDLISTVSBINARYTREE_LINKEDLIST_H
#define LINKEDLISTVSBINARYTREE_LINKEDLIST_H
#include "Location.h"

namespace UTEC {
    //Declarando el nodo
    struct Node {
        Location data; //Dato tipo location que almacena los campos
        Node* right; //Nodo de la derecha
        Node* left; //Nodo de la izquierda
        explicit Node(const Location&); //Nodo constante
    };
    //Creando clase LinkedList
    class LinkedList {
        Node* head; //Crea el head
        Node* tail; //Crea el tail

    public:
        LinkedList(); //Constructor
        ~LinkedList(); //Destructor
        int size(); //Tamaño de la lista
        bool is_empty(); //True si esta vacia
        Node* get_head(); //Extrae el head de tipo Node*
        Node* get_tail(); //Extrae el tail de tipo Node*
        void add_head(const Location& data); //Agrega un head
        void add_tail(const Location& data); //Agrega un tail
        void print(); //Imprime los nodos de la lista
        void insert(int posicion, const Location& data); //Inserta un nodo en una posicion especifica
        Node* search(int position_id); //Busqueda binaria en la lista
    };

    void load_locations(LinkedList* linked_list, std::string file_name); //Carga los datos del archivo csv
}

#endif //LINKEDLISTVSBINARYTREE_LINKEDLIST_H
