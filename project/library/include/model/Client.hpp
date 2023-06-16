#ifndef ClientHH
#define ClientHH
#include <string>
#include <vector>
#include "typedefs.hpp"
#include "model/ClientType.hpp"


class Rent; //deklarujemy klase rent aby vector currentRents działał

// class Client {
// private:
//     std::string firstName;
//     std::string lastName;
//     const int personalID;
//     AddressPtr address;
//     ClientTypePtr clientType;
//     bool archive;
// public:
//     Client(const std::string &fName, const std::string &lName, const int &id, AddressPtr adr, ClientTypePtr type);
//     virtual ~Client();

//     std::string getFirstName();
//     std::string getLastName();
//     int getPersonalID();

//     void setFirstName(const std::string &_firsName);
//     void setLastName(const std::string &_lastName);
//     void setAddress(AddressPtr _address);
//     void setClientType(ClientTypePtr _ClientType);

//     const int getMaxVehicles() const;
//     const double applyDiscout(double price) const;

    
//     const AddressPtr getAddress() const; 
//     std::string getClientInfo();

//     const bool isArchive() const;
//     void setArchive(const bool &archive);
// };

#endif