#ifndef ClientType3
#define ClientType3

#include "model/ClientType.h"

class Gold : public ClientType
{
private:
    int maxVehicles=4; 
public:
    Gold();
    virtual ~Gold();
    double applyDiscount(double price)final;
    std::string getTypeInfo()final;
};

#endif