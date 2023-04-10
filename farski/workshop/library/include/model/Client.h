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
    void setFirstName(std::string);
    void setLastName(std::string);
    void setAddress(Address *_address);
    Address *getAddress();
    std::string getClientInfo();
    Client(std::string fName, std::string lName, int id, Address *adr);
    ~Client();
};

#endif