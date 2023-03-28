#ifndef ClientHH
#define ClientHH
#include <string>

class Client {
private:
    std::string firstName;
    std::string lastName;
    int personalID;
public:
    void setFirstName(std::string);
    void setLastName(std::string);
    void setPersonalID(int);
    std::string getClientInfo();
    Client();
    ~Client();
};

#endif