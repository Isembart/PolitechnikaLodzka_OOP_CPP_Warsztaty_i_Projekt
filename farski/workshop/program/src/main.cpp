#include <iostream>
#include "math_helpers.h"
#include "Client.h"
#include <sstream>

using namespace std;

int main(int argc, char* argv[]) {
    // cout << "hello world!"<<endl;  
    // cout << factorial(5) << endl;

    // Address Smolna22 = Address("Warszawa","Smolna","22");
    // //konstruktor z lista inicjalizacyjną pozwala na ustawienie pustego imienia lub nazwiska!
    // Client client1 = Client("Marcus", "Statyczny",0,&Smolna22);
    // Client *client2 = new Client("Marcus", "Dynamiczny", 151231,&Smolna22);

    // cout<<client1.getClientInfo()<<endl;
    // cout<<client2->getClientInfo()<<endl;

    // client2->setFirstName("Jonasz");
    // client2->setFirstName(""); //setter nie pozwala na ustawienie pustego imienia, imie będzie równe "Jonasz"

    // cout<<client2->getClientInfo()<<endl;

    //delete client2;

    Client* client1 = new Client("Jonasz","Wasilak",4123,nullptr);
    Address* smolna22 = new Address();
    client1->setAddress(smolna22);
    cout <<client1->getClientInfo()<<endl;
    cout <<client1->getClientInfo()<<endl;
    delete client1;
    cout << smolna22->getAdressInfo()<<endl;
    return 0;
}