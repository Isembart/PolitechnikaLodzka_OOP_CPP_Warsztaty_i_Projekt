#include "Address.h"
#include <string>

Address::Address(){
    city="test";
    street = "test";
    number = "0";
}

Address::Address(std::string _city, std::string _street, std::string _number)
{
    city = _city;
    street = _street;
    number = _number;
}

Address::~Address()
{
}

//Gettery
std::string Address::getCity(){
    return city;  
}
std::string Address::getStreet(){
    return street;  
}
std::string Address::getNumber(){
    return number;  
}

//settery
void Address::setCity(std::string _city) {
    city = _city;
}

void Address::setStreet(std::string _street) {
    street = _street;
}

void Address::setNumber(std::string _number) {
    number = _number;
}


std::string Address::getAdressInfo(){
    return city + " " + street + " " + number;
}