#include <iostream>
#include "model/Client.h"
#include "model/Vehicle.h"
#include "model/Rent.h"
#include "repositories/ClientRepository.h"
#include "typyedefs.h"
#include "repositories/StorageContainer.h"

#include "model/ClientType.h"
#include "model/ClientTypes/Gold.h"

#include "model/Managers/ClientManager.h"
#include "model/Managers/VehicleManager.h"
#include "model/Managers/RentManager.h"

#include "model/Vehicles/Bicycle.h"
#include "model/Vehicles/Car.h"

#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

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


    // StorageContainer container;
    // cout << "Client Repo info: " <<endl << container.getClientRepo()->report() << endl;
    // cout << "Vehicle Repo info: " <<endl << container.getVehicleRepo()->report() << endl;
    // cout << "Rent Repo info: " <<endl << container.getRentRepo()->report() << endl;

    // ClientPtr client = container.getClientRepo()->findBy(isMariusz).at(0); 
    // VehiclePtr vehicle = container.getVehicleRepo()->get(0);
    // boost::posix_time::ptime now = boost::posix_time::second_clock::local_time();
    // container.getRentRepo()->add(std::make_shared<Rent>(1,client,vehicle,now));

    // cout << endl << "---PLAESE WORK---" << endl;
    
    // cout << "Client Repo info: " <<endl << container.getClientRepo()->report() << endl;
    // cout << "Vehicle Repo info: " <<endl << container.getVehicleRepo()->report() << endl;
    // cout << "Rent Repo info: " <<endl << container.getRentRepo()->report() << endl;

    ClientManager cMan;
    VehicleManager vMan;
    RentManager rMan;

    AddressPtr newAdr = std::make_shared<Address>("Warszawa","smolna","22a");
    std::shared_ptr<ClientType> newGold = std::make_shared<Gold>();
    cMan.registerClient("Mariusz","pudzianowski",12,newAdr,newGold);
    
    vMan.registerCar("WZY01",100,2000,Segment(A));
    vMan.registerBicycle("WZY02",20);

    rMan.rentVehicle(cMan.getClient(12),vMan.getVehicle("WZY01"),boost::posix_time::second_clock::local_time() - boost::gregorian::days(2));
    rMan.rentVehicle(cMan.getClient(12),vMan.getVehicle("WZY02"),boost::posix_time::second_clock::local_time() - boost::gregorian::days(3));

    VehiclePredicate tanie = [](VehiclePtr ptr) {
        return ptr->getActualRentalPrice() < 100;
    };

    VehiclePredicate drogie = [](VehiclePtr ptr) {
        return ptr->getActualRentalPrice() > 100;
    };
    cout << "Tanie: "<< vMan.findVehicles(tanie).begin()->get()->getVehicleInfo() <<" Cena: "<< vMan.findVehicles(tanie).begin()->get()->getActualRentalPrice() <<endl ;
    cout << "Drogie: "<< vMan.findVehicles(drogie).begin()->get()->getVehicleInfo() <<" Cena: "<<vMan.findVehicles(drogie).begin()->get()->getActualRentalPrice() <<endl ;

    cout << cMan.getClient(12)->getClientInfo() << endl;
    rMan.returnVehicle(vMan.getVehicle("WZY01"));
    rMan.returnVehicle(vMan.getVehicle("WZY02"));

    cout << cMan.getClient(12)->getClientInfo() << endl;
    return 0;
}