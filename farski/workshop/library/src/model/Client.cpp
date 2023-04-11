#include <iostream>
#include "Client.h"
#include <string>



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

Client::Client(const std::string &fName, const std::string &lName, const int &id, Address* adr) : firstName(fName) , lastName(lName) , personalID(id), address(adr){
}

Client::~Client(){
}