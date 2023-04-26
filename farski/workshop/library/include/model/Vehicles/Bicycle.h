#ifndef bicycleClassHeader
#define bicycleClassHeader

#include <string>
#include "model/Vehicle.h"


class Bicycle : public Vehicle
{
private:
public:
    Bicycle(const std::string &_plateNumber,const int &_basePrice);
    ~Bicycle();
};

#endif