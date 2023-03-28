#ifndef ClientHH
#define ClientHH
#include <string>

class Client {
private:
    std::string firstName;
    std::string lastName;
    const int personalID;
    Client();
public:
    void setFirstName(std::string);
    void setLastName(std::string);
    void setPersonalID(int);
    std::string getClientInfo();
    Client(std::string,std::string ,int);
    ~Client();
};

#endif