#include "Location.h"

UTEC::Location::Location(): position_id{0},state_code{""},country{""},latitude{0},longitude{0},line{""},construction{""} {} //Inicializa los valores de los atributos de la clase

UTEC::Location::Location(int position_id, std::string state_code, std::string country, double latitude, double longitude, //Asigna los atributos a cada parámetro
                         std::string line, std::string construction) {
    Location::position_id=position_id;
    Location::state_code=state_code;
    Location::country=country;
    Location::latitude=latitude;
    Location::longitude=longitude;
    Location::line=line;
    Location::construction=construction;
}

int UTEC::Location::get_position_id() { //Retorna la posición del ID
    return position_id;
}

void UTEC::Location::printLocation() { //Imprime los campos que se han guardado en la clase
    std::cout << "Position_Id: " << position_id << '\n';
    std::cout << "State_Code: " << state_code << '\n';
    std::cout << "Country: " << country << '\n';
    std::cout << "Latitude: " << latitude << '\n';
    std::cout << "Longitude: " << longitude << '\n';
    std::cout << "Line: " << line << '\n';
    std::cout << "Construction: " << construction << '\n' << '\n';
}