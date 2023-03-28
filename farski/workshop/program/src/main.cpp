#include <iostream>
#include "math_helpers.h"
#include "Client.h"
#include <sstream>

using namespace std;

int main(int argc, char* argv[]) {
    cout << "hello world!"<<endl;  
    cout << factorial(5) << endl;

    //konstruktor z lista inicjalizacyjną pozwala na ustawienie pustego imienia lub nazwiska!
    Client client1 = Client("Marcus", "Statyczny",0);
    Client *client2 = new Client("Marcus", "Dynamiczny", 151231);

    cout<<client1.getClientInfo()<<endl;
    cout<<client2->getClientInfo()<<endl;

    client2->setFirstName("Jonasz");
    client2->setFirstName(""); //setter nie pozwala na ustawienie pustego imienia, imie będzie równe "Jonasz"

    cout<<client2->getClientInfo()<<endl;

    delete client2;
    return 0;
}