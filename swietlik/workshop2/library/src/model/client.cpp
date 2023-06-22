#include <string>
#include "model/client.h"

using namespace std;

Client::Client()
{
}


Client::Client(string imie, string nazwisko, string id)
{
    firstName = imie;
    lastName = nazwisko;
    personalID = id;
}


Client::~Client()
{
}


string Client::clientInfo()
{
    string info;
    info = firstName + " " + lastName + " " + personalID;
    return info;
}

void Client::setLastName(string newLastName)
{
    lastName = newLastName;
}

void Client::setAddress(string newAddress)
{
    address = newAddress;
}