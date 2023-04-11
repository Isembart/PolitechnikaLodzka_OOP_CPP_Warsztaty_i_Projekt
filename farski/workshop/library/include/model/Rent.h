#ifndef rentClassHeader
#define rentClassHeader
#include "Client.h"
#include "Vehicle.h"
#include <string>

class Rent
{
private:
    unsigned int id;
    Client* client;
    Vehicle* vehicle; 
public:
    Rent(const unsigned int &_id, Client* _client, Vehicle* _vehicle);
    ~Rent();

    const int getId() const;
    const Client* getClient();
    const Vehicle* getVehicle();

    std::string getRentInfo();


};

#endif