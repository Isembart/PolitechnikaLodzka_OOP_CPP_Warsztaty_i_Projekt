#ifndef ClientType0
#define ClientType0

#include "model/ClientType.h"

class Default : public ClientType
{
private:
    int maxVehicles=1; 
public:
    Default();
    virtual ~Default();
    double applyDiscount(double price)final;
    std::string getTypeInfo()final;
};
#endif
