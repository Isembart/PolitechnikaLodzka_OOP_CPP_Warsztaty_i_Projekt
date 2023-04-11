#ifndef vehicleClassHeader
#define vehicleClassHeader

#include <string>


class Vehicle
{
private:
    std::string plateNumber;
    //cena za 1 dobę wypożyczenia
    unsigned int basePrice;
    bool rented = false;
public:
    Vehicle(/* args */);
    Vehicle(const std::string &_plateNumber,const int &_basePrice);
    ~Vehicle();
    std::string getVehicleInfo();
    const std::string getPlateNumber() const;
    const int getBasePrice() const;
    void setPlateNumber(const std::string &_plateNumber);
    void setBasePrice(const int &_basePrice);

    const bool isRented() const;
    void setRented(const bool &_rented);
};

#endif