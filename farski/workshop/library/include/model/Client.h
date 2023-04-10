#ifndef ClientHH
#define ClientHH
#include <string>
#include "Address.h"

class Client {
private:
    std::string firstName;
    std::string lastName;
    const int personalID;
    Address* address;
    Client();
public:
    void setFirstName(const std::string &_firsName);
    void setLastName(const std::string &_lastName);
    void setAddress(Address *_address);
    const Address *getAddress() const;
    std::string getClientInfo();
    Client(const std::string &fName, const std::string &lName, const int &id, Address *adr);
    ~Client();
};

#endif