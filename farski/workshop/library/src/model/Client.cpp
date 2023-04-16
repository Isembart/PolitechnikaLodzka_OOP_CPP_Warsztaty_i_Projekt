#include <iostream>
#include "model/Client.h"
#include <string>

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

void Client::setFirstName(std::string fName)
{
    if(fName.length() > 0)
    {
        firstName = fName;
    }
}

void Client::setLastName(std::string lName)
{
    if(lName.length() > 0)
    {
        lastName = lName;
    }
}

//void Client::setPersonalID(int id)
//{
    //personalID = id;
//}

std::string Client::getClientInfo()
{   
    return firstName + lastName + std::to_string(personalID);
}

//Nie używamy konstruktora domyślnego
//Client::Client()
//{
    //firstName = "Test";
    //lastName = "Test";
    //personalID = 0;
    //std::cout<<this<<": Uzylem konstruktora domyslnego!"<<std::endl;
    //std::cout<<getClientInfo()<<std::endl;
//}

Client::Client(std::string fName, std::string lName, int id) : firstName(fName) , lastName(lName) , personalID(id) {
    //std::cout<<this<<": Uzylem konstruktora parametrowego!"<<std::endl;
    //std::cout<<getClientInfo()<<std::endl;
}

Client::~Client(){
    //std::cout<<"Zniszczono instancje klasy client! adres: "<<this<<std::endl;
}