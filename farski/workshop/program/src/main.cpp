#include <iostream>
#include "model/Client.h"
#include "model/Vehicle.h"
#include "model/Rent.h"
#include "repositories/ClientRepository.h"
#include "typyedefs.h"
#include "repositories/StorageContainer.h"

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


    StorageContainer container;
    cout << "Client Repo info: " <<endl << container.getClientRepo()->report() << endl;
    cout << "Vehicle Repo info: " <<endl << container.getVehicleRepo()->report() << endl;
    cout << "Rent Repo info: " <<endl << container.getRentRepo()->report() << endl;

    ClientPtr client = container.getClientRepo()->findBy(isMariusz).at(0); 
    VehiclePtr vehicle = container.getVehicleRepo()->get(0);
    boost::posix_time::ptime now = boost::posix_time::second_clock::local_time();
    container.getRentRepo()->add(new Rent(1,client,vehicle,now));

    cout << endl << "---PLAESE WORK---" << endl;
    
    cout << "Client Repo info: " <<endl << container.getClientRepo()->report() << endl;
    cout << "Vehicle Repo info: " <<endl << container.getVehicleRepo()->report() << endl;
    cout << "Rent Repo info: " <<endl << container.getRentRepo()->report() << endl;
    return 0;
}