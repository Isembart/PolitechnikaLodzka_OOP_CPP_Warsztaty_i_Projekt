#include <iostream>
#include <string>
#include "model/Client.hpp"
#include "model/ClientType.hpp"
#include "typedefs.hpp"


std::string Client::getFirstName()
{
    return firstName;
}

std::string Client::getLastName()
{
    return lastName;
}

const int Client::getPersonalID() const
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

void Client::setClientType( ClientTypePtr _ClientType)
{
    clientType = _ClientType;
}

const int Client::getMaxComputers() const
{
    return clientType->getMaxComputers();
}

std::string Client::getClientInfo()
{   
    return firstName + " "+ lastName + " " + std::to_string(personalID) + ", " + "Client Type: " + clientType->getClientTypeInfo();
}

const bool Client::isArchive() const
{
    return archive;
}

void Client::setArchive(const bool &_archive)
{
    archive = _archive;
}

Client::Client(const std::string &fName, const std::string &lName, const int &id, ClientTypePtr type) : firstName(fName), lastName(lName), personalID(id)
{
    clientType = type;
    archive = false;
}

Client::~Client(){
}

const int Client::getMaxRAM() const {
    return clientType->getMaxRAM();

}