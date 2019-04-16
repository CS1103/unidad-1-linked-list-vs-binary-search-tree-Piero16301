#ifndef LINKEDLISTVSBINARYTREE_LOCATION_H
#define LINKEDLISTVSBINARYTREE_LOCATION_H
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

namespace UTEC {
    class Location { //Crea la clase Location para guardar los campos de los nodos de las clases LinkedList y BinarySearchTree
        int position_id;
        std::string state_code;
        std::string country;
        double latitude;
        double longitude;
        std::string line;
        std::string construction;
    public:
        Location();
        Location(int position_id, std::string state_code, std::string county, double latitude, double longitude, std::string line, std::string construction);
        int get_position_id(); //Obtiene la posición del ID
        void printLocation(); //Imprime la localización
    };
}

#endif //LINKEDLISTVSBINARYTREE_LOCATION_H