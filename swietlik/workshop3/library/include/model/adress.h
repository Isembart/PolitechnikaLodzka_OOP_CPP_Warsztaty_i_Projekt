//#ifndef address
//#define address
#include <string>
#include <iostream>

using namespace std;

class Address
{
private:
    string street;
    int houseNumber;
public:
    Address(string ulica, int numerDomu);
    ~Address();
    void setUlica(string newStreet);
    void setNumerDomu(int newHouseNumber);
    string getUlica();
    int getNumerDomu();
};
//#endif