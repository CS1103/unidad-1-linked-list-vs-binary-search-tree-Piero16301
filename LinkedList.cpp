#include "LinkedList.h"

UTEC::Node::Node(const Location & data): data{data}, right{nullptr}, left{nullptr} {} //Inicializa el nodo con nullptr y el data estándar

UTEC::LinkedList::LinkedList(): head{nullptr}, tail{nullptr} {} //Constructor LinkedList

UTEC::LinkedList::~LinkedList() { //Destructor LinkedList
    Node* temporal = head;
    while (temporal->right != nullptr) { //Borra todos los nodos hasta que el tenporal sea nulo
        delete temporal;
        temporal = temporal->right;
    }
    delete temporal;
}

int UTEC::LinkedList::size() { //Tamaño de la lista
    int contador = 0; //Contador de tamaño
    Node* actual = head;
    while(actual != nullptr) { //Recorre la lista desde el head hacia la derecha hasta que el actual sea nulo
        contador++;
        actual = actual->right;
    }
    return contador;
}

bool UTEC::LinkedList::is_empty() { //Si el head es nulo, entonces la lista esta vacia
    return head == nullptr;
}

UTEC::Node *UTEC::LinkedList::get_head() { //Retorna el head tipo Node
    return head;
}

UTEC::Node *UTEC::LinkedList::get_tail() { //Retorna el tail tipo Node
    return tail;
}

void UTEC::LinkedList::add_head(const Location& data) { //Agrega un nuevo head
    Node* temp = new Node(data);
    if (is_empty()) { //Si está vacío, el head será el parámetro que se envia a la funcion
        tail = temp;
        head = temp;
    } else { //Si no sera el left del head actual
        temp->right = head;
        head->left = temp;
        head = temp;
    }
}

void UTEC::LinkedList::add_tail(const Location& data) { //Agrega un tail a la lista
    Node* temp = new Node(data);
    if (is_empty()) { //Si está vacía entonces asigna el tail al parámetro al tail
        tail = temp;
        head = temp;
    } else { //Si no sera el right del tail actual
        tail->right = temp;
        temp->left = tail;
        tail = temp;
    }
}

void UTEC::LinkedList::print() { //Imprime los nodos de la lista
    if (is_empty()) {
        std::cout << "La lista esta vacia, ingrese datos." << '\n'; //Si está vacía imprime...
    } else { //Si no recorre todos los nodos y va imprimiendo el location que son los campos de cada nodo
        Node* temporal = head;
        while (temporal != tail) {
            temporal->data.printLocation();
            temporal = temporal->right;
        }
        delete temporal;
    }
}

void UTEC::LinkedList::insert(int posicion, const Location &data) { //Inserta un nodo en una posicion específica
    Node* insertado = new Node(data);
    Node* temporal = head;
    for (int i = 1; i < posicion; ++i) { //Recorre la cantidad de la posicion
        temporal = temporal->right;
    }
    insertado->left = temporal; //El left será el temporal
    insertado->right = temporal->right; //El right será el temporal
    temporal->right = insertado;
}

UTEC::Node* UTEC::LinkedList::search(int position_id) { //Hace la busqueda binaria en la lista
    Node* temporal = head;
    while (temporal->data.get_position_id() != position_id) { //Mientras no encuentre pasa al siguiente
        temporal = temporal->right;
    }
    if (temporal->right == nullptr) {
        return nullptr; //Cuando llega al final de la lista
    } else {
        return temporal; //Cuando encuentra el nodo
    }
}

void UTEC::load_locations(UTEC::LinkedList *linked_list, std::string file_name) { //Carga el archivo con los datos
    std::ifstream archivo(file_name); //Se crea una nueva variable tipo ifstream
    if (archivo.is_open()) { //Abre el archivo
        std::string campos[7], fila; //Crea los campos (7) y las filas
        std::getline(archivo, fila); //Extrae cada fila del archivo
        while (!archivo.eof()) { //Hasta que no se termina el archivo
            std::getline(archivo, fila); //Extrae cada fila del archivo
            std::istringstream stringStream(fila); //Tipo de acceso al archivo
            unsigned int contador = 0; //Contador del numero de campos
            while (std::getline(stringStream, fila, ',')) { //Extrae los datos hasta que encuentre una coma
                campos[contador] = fila; //Lo agrega al campo correspondiente
                contador++; //Aumenta el contador de campo
            }
            Location valorNodo(std::stoi(campos[0]), campos[1], campos[2], std::stod(campos[3]), std::stod(campos[4]), campos[5], campos[6]); //Ingresa los valors del archivo en la clase Location, campo por campo
            linked_list->add_tail(valorNodo); //Agrega cada nodo con sus respectivos nodos
        }
    }
    archivo.close(); //Cierra el archivo
}