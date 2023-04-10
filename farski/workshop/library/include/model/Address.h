#ifndef addressClass
#define adressClass

#include <string>

class Address
{
private:
    std::string city;
    std::string street;
    std::string number;
    
public:
    Address();
    Address(std::string _city, std::string _street, std::string _number);
    ~Address();
    std::string getAdressInfo(); 
    std::string getCity();
    std::string getStreet();
    std::string getNumber();

    void setCity(std::string);
    void setStreet(std::string);
    void setNumber(std::string);
};

#endif