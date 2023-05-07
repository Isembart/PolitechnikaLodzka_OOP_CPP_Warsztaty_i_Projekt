#ifndef ClientType4
#define ClientType4
#include "model/ClientType.h"

class Platinum : public ClientType
{
private:
    int maxVehicles=5; 
public:
    Platinum();
    virtual ~Platinum();
    double applyDiscount(double price)final;
    std::string getTypeInfo()final;
};

#endif
