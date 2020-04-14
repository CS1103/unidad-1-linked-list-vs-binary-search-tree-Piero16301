#include "BinarySearchTree.h"

UTEC::Nodo::Nodo(const UTEC::Location &data): data{data}, right{nullptr}, left{nullptr} {} //Inicializa el nodo en nullptr

UTEC::BinarySearchTree::BinarySearchTree(): raiz{nullptr} {} //Constructor, inicializa la raiz

UTEC::BinarySearchTree::~BinarySearchTree() { //Destructor, elimina el nodo raiz. Si elimina la raiz, elimina el arbol
    clear(raiz);
}

void UTEC::BinarySearchTree::insert(UTEC::Location &data) { //Inserta un nuevo nodo en el arbol
    Nodo* nuevo = new Nodo(data);
    if (raiz == nullptr) { //Si la raiz es nula, asigna el parámetro a la raiz
        raiz = nuevo;
    } else { //Si no va asignando el nuevo nodo a la derecha si es mayor que la raiz, y a la izquierda si es menor
        Nodo* temporal = raiz;
        while (temporal != nullptr) {
            if (temporal->right == nullptr) {
                temporal->right = nuevo;
                break;
            } else if (temporal->right != nullptr) {
                temporal = temporal->right;
            } else {
                if (nuevo->data.get_position_id() <= temporal->data.get_position_id()) {
                    if (temporal->left == nullptr) {
                        temporal->left = nuevo;
                    } else if (temporal->left != nullptr) {
                        temporal = temporal->left;
                    }
                }
            }
        }
    }
}

void UTEC::BinarySearchTree::clear(UTEC::Nodo *) { //Elimina el nodo que le envía en el parámetro
    if (raiz != nullptr) {
        clear(raiz->left);
        clear(raiz->right);
        delete raiz;
    }
}

bool UTEC::BinarySearchTree::is_empty() { //Está vaacío si el right y left de la raiz son nulos
    return (raiz->right == nullptr) && (raiz->left == nullptr);
}

UTEC::Nodo* UTEC::BinarySearchTree::get_root() { //Retorna el nodo raiz
    return raiz;
}

UTEC::Nodo* UTEC::BinarySearchTree::search(int position_id) { //Busca el id del parámetro. Comienza en la raiz y va avanzando, dependiendo si es mayor o menor
    Nodo* temporal = raiz;
    while (temporal != nullptr) {
        int tempID = temporal->data.get_position_id();
        if (tempID == position_id) {
            return temporal;
        } else if (position_id < tempID) {
            temporal = temporal->left;
        } else if (position_id > tempID) {
            temporal = temporal->right;
        } else {
            return nullptr;
        }
    }
}

void UTEC::BinarySearchTree::print() { //Imprime los nodos del arbol
    print_Nodo(raiz);
}

void UTEC::load_locations(UTEC::BinarySearchTree *linked_list, std::string file_name) { //Carga los datos del archivo y hace el mismo procedimiento que el linked list, asignando los campos de cada nodo
    std::ifstream archivo(file_name);
    if (archivo.is_open()) {
        std::string campos[7], fila;
        std::getline(archivo, fila);
        while (!archivo.eof()) {
            std::getline(archivo, fila);
            std::istringstream stringStream(fila);
            unsigned int contador = 0;
            while (std::getline(stringStream, fila, ',')) {
                campos[contador] = fila;
                contador++;
            }
            Location valorNodo(std::stoi(campos[0]), campos[1], campos[2], std::stod(campos[3]), std::stod(campos[4]), campos[5], campos[6]);
            linked_list->insert(valorNodo);
        }
    }
    archivo.close();
}

void UTEC::print_Nodo(UTEC::Nodo *raiz) { //Imprime el nodo que se le envía en el parámetro
    if (raiz != nullptr) {
        print_Nodo(raiz->left);
        raiz->data.printLocation();
        print_Nodo(raiz->right);
    }
}
