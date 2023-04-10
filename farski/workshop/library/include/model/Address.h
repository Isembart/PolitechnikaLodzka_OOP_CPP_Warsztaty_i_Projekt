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
    Address(const std::string &_city, const std::string &_street, const std::string &_number);
    ~Address();
    const std::string getAdressInfo() const; 
    const std::string getCity() const;
    const std::string getStreet() const;
    const std::string getNumber() const;

    // void setCity(std::string);
    // void setStreet(std::string);
    // void setNumber(std::string);
};

#endif