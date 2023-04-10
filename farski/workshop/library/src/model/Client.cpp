#include <iostream>
#include "Client.h"
#include <string>



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

void Client::setAddress(Address* _address)
{
    if(_address != nullptr)
    {
        address = _address;
    }
}

Address* Client::getAddress() {
    return address;
}

// void Client::setPersonalID(int id)
//{
// personalID = id;
//}

std::string Client::getClientInfo()
{   
    return firstName + " "+ lastName + " " + std::to_string(personalID) + ", " + address->getAdressInfo();
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

Client::Client(std::string fName, std::string lName, int id, Address* adr) : firstName(fName) , lastName(lName) , personalID(id), address(adr){
    //std::cout<<this<<": Uzylem konstruktora parametrowego!"<<std::endl;
    //std::cout<<getClientInfo()<<std::endl;
}

Client::~Client(){
    // delete address;
    //std::cout<<"Zniszczono instancje klasy client! adres: "<<this<<std::endl;
}