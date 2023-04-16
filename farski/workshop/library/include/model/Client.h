#ifndef ClientHH
#define ClientHH
#include <string>
#include <vector>
#include "model/Address.h"


class Rent; //deklarujemy klase rent aby vector currentRents działał

class Client {
private:
    std::string firstName;
    std::string lastName;
    const int personalID;
    Address* address;
    std::vector<Rent*> currentRents;
public:
    Client(const std::string &fName, const std::string &lName, const int &id, Address *adr);
    ~Client();

    std::string getFirstName();
    std::string getLastName();
    int getPersonalID();

    void setFirstName(const std::string &_firsName);
    void setLastName(const std::string &_lastName);
    void setAddress(Address *_address);
    
    const Address *getAddress() const;
    std::vector<Rent*> getCurrentRents();
   
    std::string getClientInfo();
    std::string getFullClientInfo();
};

#endif