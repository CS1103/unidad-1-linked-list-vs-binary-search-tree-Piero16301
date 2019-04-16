#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <vector>
#include <fstream>
#include "LinkedList.h"
#include "BinarySearchTree.h"

// Nombres de archivos
const std::string LOCATION_FILE = "../Locations.csv";
const std::string SEARCH_FILE = "../Search.txt";

using namespace UTEC;

int main() {

    // Declarando variables
    LinkedList ll;
    BinarySearchTree bst;
    std::vector<int> vsearch;

    // Grabar Datos del archivo "Locations.csv" en ll

    load_locations(&ll, LOCATION_FILE);

    // Grabar Datos del archivo "Locations.csv" en bst

    load_locations(&bst, LOCATION_FILE);

    // Leer los datos del archivo "Search.txt" y grabarlos en vsearch
    std::ifstream search(SEARCH_FILE);
    if (search.is_open()) {
        std::string searching;
        while (!search.eof()) {
            if (!search.eof()) {
                std::getline(search, searching);
                vsearch.push_back(stoi(searching));
            }
        }
    }
    search.close();

    double start_ll = clock();
    for (const auto &nueva: vsearch) {
        ll.search(nueva);
    }
    double end_ll = clock();

    std::cout << "Tiempo de busqueda en lista enlazada: " << (end_ll - start_ll) << " ms" << '\n';

    double start_bst = clock();
    for (const auto &nueva: vsearch) {
        bst.search(nueva);
    }
    double end_bst = clock();

    std::cout << "Tiempo de busqueda en Arbol Binario: " << (end_bst - start_bst) << " ms" << '\n';

    return 0;
}