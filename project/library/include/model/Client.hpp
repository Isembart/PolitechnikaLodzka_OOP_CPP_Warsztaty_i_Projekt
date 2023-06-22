#ifndef ClientHH
#define ClientHH
#include <string>
#include <vector>
#include "typedefs.hpp"
#include "model/ClientType.hpp"


class Rent; //deklarujemy klase rent aby vector currentRents działał

class Client {
private:
    std::string firstName;
    std::string lastName;
    const int personalID;
    ClientTypePtr clientType;
    bool archive;
public:
    Client(const std::string &fName, const std::string &lName, const int &id, ClientTypePtr type);
    virtual ~Client();

    std::string getFirstName();
    std::string getLastName();
    const int getPersonalID()const;

    void setFirstName(const std::string &_firsName);
    void setLastName(const std::string &_lastName);
    void setClientType(ClientTypePtr _ClientType);

    const int getMaxComputers() const;
    const int getMaxRAM() const;


    std::string getClientInfo();

    const bool isArchive() const;
    void setArchive(const bool &archive);
};

#endif