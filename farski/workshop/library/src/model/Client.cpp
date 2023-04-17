#include <iostream>
#include <string>
#include "model/Client.h"
#include "model/Rent.h"

std::string Client::getFirstName()
{
    return firstName;
}

std::string Client::getLastName()
{
    return lastName;
}

int Client::getPersonalID()
{
    return personalID;
}

void Client::setFirstName(const std::string &fName)
{
    if(fName.length() > 0)
    {
        firstName = fName;
    }
}

void Client::setLastName(const std::string &lName)
{
    if(lName.length() > 0)
    {
        lastName = lName;
    }
}

void Client::setAddress(Address* _address)
{
    if(_address != nullptr)
    {
        address = _address;
    }
}

const Address* Client::getAddress() const {
    return address;
}

std::vector<Rent *> Client::getCurrentRents()
{
    return currentRents;
}

std::string Client::getClientInfo()
{   
    return firstName + " "+ lastName + " " + std::to_string(personalID) + ", " + address->getAdressInfo();
}

std::string Client::getFullClientInfo()
{   
    std::string rentInfo;
    for (int i = 0; i < currentRents.size(); i++)
    {
       rentInfo+=currentRents.at(i)->getRentInfo() + " "; 
    }
    
    return firstName + " "+ lastName + " " + std::to_string(personalID) + ", " + address->getAdressInfo() + "\n" + "Wypozyczenia: " + rentInfo;
}

Client::Client(const std::string &fName, const std::string &lName, const int &id, Address* adr) : firstName(fName) , lastName(lName) , personalID(id), address(adr){
}

Client::~Client(){
}