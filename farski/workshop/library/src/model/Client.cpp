#include <iostream>
#include <string>
#include "model/Client.h"
#include "model/Rent.h"
#include "model/ClientType.h"
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

void Client::setClientType( ClientTypePtr _ClientType)
{
    clientType = _ClientType;
}

const int Client::getMaxVehicles() const
{
    return clientType->getMaxVehicles();
}

const double Client::applyDiscout(double price) const
{
    return clientType->applyDiscount(price);
}

const AddressPtr Client::getAddress() const
{
    return address;
}

std::string Client::getClientInfo()
{   
    return firstName + " "+ lastName + " " + std::to_string(personalID) + ", " + address->getAdressInfo() + " Client Type: " + clientType->getTypeInfo();
}

const bool Client::isArchive() const
{
    return archive;
}

void Client::setArchive(const bool &_archive)
{
    archive = _archive;
}

Client::Client(const std::string &fName, const std::string &lName, const int &id, AddressPtr adr, ClientTypePtr type) : firstName(fName), lastName(lName), personalID(id), address(adr)
{
    clientType = type;
    archive = false;
}

Client::~Client(){
}