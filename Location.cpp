#include "Location.h"

UTEC::Location::Location(): position_id{0},state_code{""},county{""},latitude{0},longitude{0},line{""},construction{""}{}

UTEC::Location::Location(int position_id, std::string state_code, std::string county, double latitude, double longitude,
                         std::string line, std::string construction) {
    Location::position_id=position_id;
    Location::state_code=state_code;
    Location::county=county;
    Location::latitude=latitude;
    Location::longitude=longitude;
    Location::line=line;
    Location::construction=construction;
}

int UTEC::Location::get_position_id() {
    return position_id;
}

void UTEC::Location::printLocation() {
    std::cout << "PositionId: " << position_id << '\n';
    std::cout << "StateCode: " << state_code << '\n';
    std::cout << "Country: " << county << '\n';
    std::cout << "Latitude: " << latitude << '\n';
    std::cout << "Longitude: " << longitude << '\n';
    std::cout << "Line: " << line << '\n';
    std::cout << "Construction: " << construction << '\n' << '\n';
}