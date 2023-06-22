#include "model/client.h"
#include "model/client.h"


Client::Client(string imie, string nazwisko, string id, string ulica, int nrDomu, string ulica2, int nrDomu2)
{
    firstName = imie;
    lastName = nazwisko;
    personalID = id;
    address = new Address(ulica, nrDomu);
    registeredAddress = new Address(ulica2, nrDomu2);
}


Client::~Client()
{
    address = nullptr;
    registeredAddress = nullptr;
    delete address;
    delete registeredAddress;
}


void Client::clientInfo()
{
    int var = 20;
    cout << "" <<endl;
    cout << "Client Info:"<<endl;
    cout.width(var); cout << left << "Name: ";
    cout << firstName + " " + lastName<<endl;
    cout.width(var); cout << left << "Personal ID: ";
    cout << personalID <<endl;
    if (address != nullptr)
    {
        cout.width(var); cout << left << "Address: ";
        cout << address->getUlica() + " " + to_string(address->getNumerDomu())<<endl;
    }
    if (registeredAddress != nullptr)
    {
        cout.width(20); cout << left << "Registered Address: ";
        cout << registeredAddress->getUlica() + " " + to_string(registeredAddress->getNumerDomu())<<endl;
    }
    allRents();
}

void Client::setLastName(string newLastName)
{
    lastName = newLastName;
}

void Client::setAddress(Address newAddress)
{
    *address = newAddress;
    address->setUlica(address->getUlica());
    address->setNumerDomu(address->getNumerDomu());
}

void Client::setRegisteredAddress(Address newAddress)
{
    *registeredAddress = newAddress;
    registeredAddress->setUlica(registeredAddress->getUlica());
    registeredAddress->setNumerDomu(registeredAddress->getNumerDomu());
}


string Client::getFirstName()
{
    return firstName;
}

string Client::getLastName()
{
    return lastName;
}

string Client::getPersonalID()
{
    return personalID;
}

string Client::getAddress()
{
    string adres;
    adres = address->getUlica() + to_string(address->getNumerDomu());
    return adres;
}

string Client::getRegisteredAddress()
{
    string adres;
    adres = registeredAddress->getUlica() + to_string(registeredAddress->getNumerDomu());
    return adres;
}

void Client::addRent(Rent *r)
{
    rentVector.push_back(r);
}

void Client::allRents()
{
    for(int i=0; i<rentVector.size(); i++)
    {
        rentVector[i]->rentInfo();
        cout<<endl;
    }
}
