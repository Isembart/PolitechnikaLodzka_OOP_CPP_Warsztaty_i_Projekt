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
    std::string getFirstName();
    std::string getLastName();
    int getPersonalID();
    void setFirstName(std::string);
    void setLastName(std::string);
    void setPersonalID(int);
    std::string getClientInfo();
    Client(std::string fName,std::string lName,int id);
    ~Client();
};

#endif