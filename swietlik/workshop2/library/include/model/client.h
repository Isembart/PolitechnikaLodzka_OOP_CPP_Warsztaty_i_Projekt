#include <string>
#include <iostream>

using namespace std;

class Client
{
private:
    string firstName;
    string lastName;
    string personalID;
    string address;
public:
    Client();
    Client(string imie, string nazwisko, string id);
    ~Client();
    string clientInfo();
    void setLastName(string newLastName);
    void setAddress(string newAddress);
};
