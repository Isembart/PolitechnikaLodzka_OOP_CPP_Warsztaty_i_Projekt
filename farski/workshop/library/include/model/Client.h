#ifndef ClientHH
#define ClientHH
#include <string>
#include <vector>
#include "model/Address.h"
#include "typyedefs.h"


class Rent; //deklarujemy klase rent aby vector currentRents działał

class Client {
private:
    std::string firstName;
    std::string lastName;
    const int personalID;
    AddressPtr address;
public:
    Client(const std::string &fName, const std::string &lName, const int &id, AddressPtr adr);
    virtual ~Client();

    std::string getFirstName();
    std::string getLastName();
    int getPersonalID();

    void setFirstName(const std::string &_firsName);
    void setLastName(const std::string &_lastName);
    void setAddress(AddressPtr _address);
    
    const AddressPtr getAddress() const;
   
    std::string getClientInfo();
};

#endif