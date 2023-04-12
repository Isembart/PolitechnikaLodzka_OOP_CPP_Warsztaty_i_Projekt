#ifndef ClientHH
#define ClientHH
#include <string>
#include <vector>
#include "model/Address.h"
#include "typedefs.h"


class Rent; //deklarujemy klase rent aby vector currentRents działał

class Client {
private:
    std::string firstName;
    std::string lastName;
    const int personalID;
    AddressPtr address;
    std::vector<RentPtr> currentRents;
public:
    Client();
    Client(const std::string &fName, const std::string &lName, const int &id, AddressPtr adr);
    ~Client();
    const AddressPtr getAddress() const;
    std::vector<RentPtr> getCurrentRents();
    void setFirstName(const std::string &_firsName);
    void setLastName(const std::string &_lastName);
    void setAddress(AddressPtr _address);
    std::string getClientInfo();
    std::string getFullClientInfo();
};

#endif