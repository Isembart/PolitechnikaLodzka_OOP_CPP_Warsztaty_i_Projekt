#include "Rent.h"
#include "Client.h"
#include "Vehicle.h"

Rent::Rent(const unsigned int &_id, Client *_client, Vehicle *_vehicle)
{
    id = _id;
    client = _client;
    vehicle = _vehicle;

    client->getCurrentRents().push_back(this); //Dodajemy nowo utworzony obiekt Rent do listy wypożyczeń odpowiedniego klienta
}

const int Rent::getId() const
{
    return id;
}

const Client *Rent::getClient()
{
    return client;
}

const Vehicle *Rent::getVehicle()
{
    return vehicle;
}

std::string Rent::getRentInfo()
{
    return std::to_string(id) + ": " + client->getClientInfo() + " -> " + vehicle->getVehicleInfo();
}
