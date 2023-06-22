#include "model/adress.h"


Address::Address(string ulica, int numerDomu)
{
    street = ulica;
    houseNumber = numerDomu;
}

Address::~Address()
{
}


void Address::setUlica(string newStreet) {
    street = newStreet;
}

void Address::setNumerDomu(int newHouseNumber) {
    houseNumber = newHouseNumber;
}

string Address::getUlica() {
    return street;
}

int Address::getNumerDomu() {
    return houseNumber;
}

