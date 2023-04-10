#include "Address.h"
#include <string>

Address::Address(){
    city="test";
    street = "test";
    number = "0";
}

Address::Address(const std::string &_city, const std::string &_street, const std::string &_number)
{
    city = _city;
    street = _street;
    number = _number;
}

Address::~Address()
{
}

//Gettery
const std::string Address::getCity() const{
    return city;  
}
const std::string Address::getStreet() const {
    return street;  
}
const std::string Address::getNumber() const{
    return number;  
}

//settery
// void Address::setCity(std::string _city) {
//     city = _city;
// }

// void Address::setStreet(std::string _street) {
//     street = _street;
// }

// void Address::setNumber(std::string _number) {
//     number = _number;
// }


const std::string Address::getAdressInfo() const{
    return city + " " + street + " " + number;
}