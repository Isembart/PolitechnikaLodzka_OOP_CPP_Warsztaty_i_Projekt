#include "model/Client.h"
#include <iostream>
#include "Client.h"
#include <string>



void Client::setFirstName(std::string fName)
{
    firstName = fName;
}

void Client::setLastName(std::string lName)
{
    lastName = lName;
}

void Client::setPersonalID(int id)
{
    personalID = id;
}

std::string Client::getClientInfo()
{   
    return firstName + lastName + std::to_string(personalID);
}

Client::Client()
{
    std::cout<<"Utworzono instancje klasy client! adres: "<< this<<std::endl;
}

Client::~Client(){
    std::cout<<"Zniszczono instancje klasy client! adres: "<<this<<std::endl;
}