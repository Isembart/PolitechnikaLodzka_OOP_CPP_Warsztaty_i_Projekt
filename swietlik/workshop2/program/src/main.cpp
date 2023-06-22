#include <iostream>
#include "math_helpers.h"
#include "model/client.h"


using namespace std;

int main() {
    cout << "Witam" << endl;
    cout << factorial(5) << endl;

    Client klient1, klient2("Adam", "Mickiewicz", "6666");
    Client *klient3 = new Client("Juliusz", "Slowacki", "999");
    cout << klient1.clientInfo() << endl;
    cout << klient2.clientInfo() << endl;
    cout << (*klient3).clientInfo() << endl;
    Client klient4("","","");
    cout << klient4.clientInfo() << endl;
//klient1.firstName = "Ahmed";
    delete klient3;

    return 0;
}
