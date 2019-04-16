#ifndef LINKEDLISTVSBINARYTREE_BINARYTREE_H
#define LINKEDLISTVSBINARYTREE_BINARYTREE_H
#include "Location.h"

namespace UTEC {

    struct Nodo { //Se crea el nodo con sus parámetros
        Location data;
        Nodo* right;
        Nodo* left;
        explicit Nodo(const Location&);
    };

    class BinarySearchTree { //Crea la clase BinarySearchTree
        Nodo* raiz; //Crea el nodo raiz que va a estar en la cima
    public:
        BinarySearchTree(); //Constructor
        ~BinarySearchTree(); //Destructor
        void insert(Location& data); //Insterta un nuevo nodo
        void clear(Nodo*); //Elimina el nodo
        bool is_empty(); //Esta vacio
        Nodo* get_root(); //Obtener raiz
        Nodo* search(int position_id); //Buscar en el arbol
        void print(); //Imprime los nodos
    };

    void load_locations(BinarySearchTree* linked_list, std::string file_name); //Carga los datos del archivo
    void print_Nodo(Nodo *raiz); //Imprime el nodo del parámetro
}

#endif //LINKEDLISTVSBINARYTREE_BINARYTREE_H
