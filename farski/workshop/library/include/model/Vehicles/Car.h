#ifndef carHeader
#define carHeader

// #include "model/Vehicle.h"
#include "model/Vehicles/MotorVehicle.h"

enum Segment {
    A=0,
    B=1,
    C=2,
    D=3,
    E=5
};

class Car : public MotorVehicle
{
private:
    const Segment segment;
public:
    Car(const std::string &_plateNumber,const int &_basePrice, const int &_engineDisplacement, const Segment &_segment);
    virtual ~Car();

    virtual const double getActualRentalPrice() const override;
    virtual std::string getVehicleInfo() override;
};

#endif