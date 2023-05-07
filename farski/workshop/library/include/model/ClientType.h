#ifndef ClientTypeClass
#define ClientTypeClass
#include "model/Client.h"


class ClientType
{
private:
    int maxVehicles;
    
public:
    ClientType();
    virtual ~ClientType()=0;

    const int getMaxVehicles() const;
    virtual double applyDiscount(double price);
    virtual std::string getTypeInfo();
};

#endif