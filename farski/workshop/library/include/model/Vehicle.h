#ifndef vehicleClassHeader
#define vehicleClassHeader

#include <string>


class Vehicle
{
private:
    std::string plateNumber;
    //cena za 1 dobę wypożyczenia
    bool rented = false;
protected:
    unsigned int basePrice;
public:
    Vehicle(const std::string &_plateNumber,const int &_basePrice);
    virtual ~Vehicle()=0;
    virtual std::string getVehicleInfo();
    const std::string getPlateNumber() const;
    //Base price of the vehicle
    const int getBasePrice() const;

    //Returns calculated price of the vehicle
    virtual const double getActualRentalPrice() const;
    void setPlateNumber(const std::string &_plateNumber);
    void setBasePrice(const int &_basePrice);

    const bool isRented() const;
    void setRented(const bool &_rented);
};

#endif