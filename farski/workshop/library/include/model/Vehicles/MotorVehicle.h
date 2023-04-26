#ifndef MotorVehicleClassHeader
#define MotorVehicleClassHeader

#include <string>
#include "model/Vehicle.h"


class MotorVehicle : public Vehicle
{
private:
    const int engineDisplacement;
public:
    MotorVehicle(const std::string &_plateNumber,const int &_basePrice, const int &_engineDisplacement);
    virtual ~MotorVehicle()=0;

    const int getEngineDisplacement() const;

    virtual  std::string getVehicleInfo();
    virtual const double getActualRentalPrice() const override;
};

#endif