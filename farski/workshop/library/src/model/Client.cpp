#include <iostream>
#include <string>
#include "model/Client.h"
#include "model/Rent.h"

#include "typyedefs.h"

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

void Client::setAddress(AddressPtr _address)
{
    if(_address != nullptr)
    {
        address = _address;
    }
}

const AddressPtr Client::getAddress() const {
    return address;
}

std::string Client::getClientInfo()
{   
    return firstName + " "+ lastName + " " + std::to_string(personalID) + ", " + address->getAdressInfo();
}

Client::Client(const std::string &fName, const std::string &lName, const int &id, AddressPtr adr) : firstName(fName) , lastName(lName) , personalID(id), address(adr){
}

Client::~Client(){
}