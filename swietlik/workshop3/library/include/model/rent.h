#ifndef rentClass
#define rentClass
#include <string>
#include <iostream>
#include "model/vehicle.h"
#include "model/client.h"
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>


using namespace std;
using namespace boost::local_time;
using namespace boost::posix_time;
using namespace boost::gregorian;
using namespace boost::uuids;

class Client;

class Rent
{
private:
    uuid ID;
    local_date_time *rentDateTime;
    local_date_time *endDateTime;
    float totalPrice;
    Vehicle *vehicle;
    Client *client;
    int rentalLength;
    time_zone_ptr *timeZone;
public:
    Rent(Client &klient, Vehicle &pojazd);
    ~Rent();
    void rentInfo();
    void endRent();
    int getPeriod();
    float getPrice();
    string getClient();
    string getVehicleRented();
    local_date_time getRentDate();
    local_date_time getEndDate();
    int getRentalLength();
};
#endif