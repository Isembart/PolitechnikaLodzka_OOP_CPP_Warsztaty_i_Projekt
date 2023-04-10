#include <iostream>
#include "math_helpers.h"
#include "Client.h"
#include <sstream>

using namespace std;

int main(int argc, char* argv[]) {

    Address* smolna22 = new Address();
    Client* client1 = new Client("Jonasz","Wasilak",4123,smolna22);
    Client* client2 = new Client("Maryla","Wasilak",5555,smolna22);
    
    Address* nowowiejska30 = new Address("Warszawa","Nowowiejska","30");
    // client1->getAddress()->setCity("Grudziadz");
    client1->setAddress(nowowiejska30);

    cout<< client1->getClientInfo() << endl << client2->getClientInfo()<<endl;
    return 0;
}