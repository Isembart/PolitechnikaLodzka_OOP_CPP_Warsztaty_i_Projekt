#ifndef ClientType1
#define ClientType1

#include "model/ClientType.h"

class Bronze : public ClientType
{
private:
    int maxVehicles=2; 
public:
    Bronze();
    virtual ~Bronze();
    double applyDiscount(double price)final;
    std::string getTypeInfo()final;
};

#endif