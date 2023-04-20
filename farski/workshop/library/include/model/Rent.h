#ifndef rentClassHeader
#define rentClassHeader
#include <string>
#include <boost/date_time.hpp>
#include "model/Client.h"
#include "model/Vehicle.h"

#include "typyedefs.h"

class Rent
{
private:
    unsigned int id;
    ClientPtr client;
    VehiclePtr vehicle; 
    boost::posix_time::ptime beginTime;
    boost::posix_time::ptime endTime;;
    unsigned int rentCost=0;
public:
    Rent(const unsigned int &_id, ClientPtr _client, VehiclePtr _vehicle, const boost::posix_time::ptime &beginTime);
    ~Rent();

    const int getId() const;
    const ClientPtr getClient();
    VehiclePtr getVehicle() const;
    const boost::posix_time::ptime getBeginTime() const;
    const boost::posix_time::ptime getEndTime() const;
    std::string getRentInfo();

    void endRent(boost::posix_time::ptime _endTime);
    int getRentDays();
    const unsigned int getRentCost()const;
};

#endif