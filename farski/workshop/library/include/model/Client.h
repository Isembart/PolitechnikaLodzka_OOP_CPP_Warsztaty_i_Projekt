#ifndef ClientHH
#define ClientHH
#include <string>
#include "Address.h"
#include <vector>

class Rent{}; //deklarujemy klase rent aby vector currentRents działał

class Client {
private:
    std::string firstName;
    std::string lastName;
    const int personalID;
    Address* address;
    std::vector<Rent*> currentRents;
public:
    Client();
    Client(const std::string &fName, const std::string &lName, const int &id, Address *adr);
    ~Client();
    const Address *getAddress() const;
    std::vector<Rent*> getCurrentRents();
    void setFirstName(const std::string &_firsName);
    void setLastName(const std::string &_lastName);
    void setAddress(Address *_address);
    std::string getClientInfo();
};

#endif