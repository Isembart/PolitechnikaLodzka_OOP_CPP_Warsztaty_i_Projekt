#ifndef vehicleClass
#define vehicleClass
#include <string>
#include <iostream>

using namespace std;

class Vehicle
{
private:
    float price;
    string registrationNumber;
public:
    Vehicle(float price, string registrationNumber);
    ~Vehicle();
    string vehicleInfo();
    float getPrice();
};
#endif