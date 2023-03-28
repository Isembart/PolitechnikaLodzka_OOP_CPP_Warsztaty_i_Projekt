#include <iostream>
#include "math_helpers.h"
#include "Client.h"
#include <sstream>

using namespace std;

int main(int argc, char* argv[]) {
    cout << "hello world!"<<endl;  
    cout << factorial(5) << endl;

    Client client1;
    Client *client2 = new Client;

    client1.setFirstName("john");
    client2->setFirstName("marcus");
    cout<<client1.getClientInfo()<<endl;
    cout<<client2->getClientInfo()<<endl;
    return 0;
}