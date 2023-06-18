#ifndef rentClassHeader
#define rentClassHeader
#include <string>
#include <boost/date_time.hpp>
#include "model/Client.hpp"
#include "model/VirtualMachine.hpp"

#include "typedefs.hpp"

class Rent
{
private:
    unsigned int id;
    ClientPtr client;
    VirtualMachinePtr virtualMachine; 
    boost::posix_time::ptime beginTime;
    boost::posix_time::ptime endTime;;
public:
    Rent(const unsigned int &_id, ClientPtr _client, VirtualMachinePtr _virtualMachine, const boost::posix_time::ptime &beginTime);
    virtual ~Rent();

    const int getId() const;
    const ClientPtr getClient();
    VirtualMachinePtr getVirtualMachine() const;
    const boost::posix_time::ptime getBeginTime() const;
    const boost::posix_time::ptime getEndTime() const;
    std::string getRentInfo();

    void endRent(boost::posix_time::ptime _endTime);
    int getRentHours();
};

#endif