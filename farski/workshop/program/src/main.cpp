#include <iostream>
#include "model/Client.h"
#include "model/Vehicle.h"
#include "model/Rent.h"
#include "repositories/ClientRepository.h"
#include "typyedefs.h"

using namespace std;


bool isMariusz(ClientPtr ptr){
    if(ptr->getFirstName() == "Mariusz") {
        return true;
    }
    else {
        return false;
    }
}

int main(int argc, char* argv[]) {

    // Address* smolna22 = new Address();
    // Client* client1 = new Client("Jonasz","Wasilak",4123,smolna22);
    // Client* client2 = new Client("Maryla","Wasilak",5555,smolna22);
    
    // Address* nowowiejska30 = new Address("Warszawa","Nowowiejska","30");
    // // client1->getAddress()->setCity("Grudziadz");
    // client1->setAddress(nowowiejska30);

    // cout<< client1->getClientInfo() << endl << client2->getClientInfo()<<endl;
    Vehicle* toyotaCorolla = new Vehicle("WZY000",10);
    Client* mariuszPudzianowski = new Client("Mariusz","Pudzianowski",0,new Address("Warszawa","Smolna","22"));
    Rent* rent1  = new Rent(1,mariuszPudzianowski,toyotaCorolla, boost::posix_time::ptime(boost::gregorian::date(2023,4,9)));

    cout << rent1->getRentInfo() << endl;
    rent1->endRent(boost::posix_time::ptime(boost::gregorian::date(2023,4,9),boost::posix_time::minutes(2)));

    cout << rent1->getRentInfo() << endl;
    cout << rent1->getRentDays() << endl;

    ClientRepository crepo;
    cout << crepo.size()<< endl;
    cout << crepo.size() << endl;
    Client Roman("roman","kostrzewski",123,new Address("grudziądz","armi krajowej","5A"));
    crepo.add(&Roman);
    crepo.add(mariuszPudzianowski);
    cout << crepo.size() << endl;
    cout << crepo.report();
    // crepo.remove(mariuszPudzianowski);
    
    cout << crepo.report();
    cout << crepo.size() << endl;
    cout << crepo.get(0)->getClientInfo();

    cout << endl <<crepo.findBy(isMariusz).at(0)->getClientInfo()<<endl;
    return 0;
}