#include <iostream>
#include "model/Client.hpp"
#include "typedefs.hpp"
#include "model/Managers/ClientManager.hpp"
#include "model/Managers/MainframeManager.hpp"
#include "model/Managers/RentManager.hpp"
#include "model/ClientTypes/Default.hpp"
#include "model/ClientTypes/Pro.hpp"
#include <memory> //sharedptr

using namespace std;

void printWholeInfo(ClientManager cMan, RentManager rMan, MainframeManager mMan) {
   
   cout << "ClientManager info:\n"<< cMan.info()<<endl;
   cout << "RentManger info:\n"<< rMan.info()<<endl;
   cout << "MainframeManager info:\n"<< mMan.info();
}

int main() {
   // ClientTypePtr proType = std::make_shared<Pro>();
   // ClientTypePtr defType = std::make_shared<Default>();
   ClientManager cMan;
   MainframeManager mMan(16000);
   RentManager rMan;

   ClientPtr c1 = cMan.registerClient("Maurycy","Farski",247653, std::make_shared<Pro>());
   // cout << cMan.info();
   ClientPtr c2 = cMan.registerClient("Agata","Swietlik",19,std::make_shared<Default>());

   VirtualMachinePtr v1 = mMan.registerVirtualmachine(1,"Ubuntu",1024);
   mMan.registerVirtualmachine(2,"Windows 11",10000);
   mMan.registerVirtualmachine(3,"Arch",2048);
   mMan.registerVirtualmachine(4,"Arch",9048); //brak ramu, nie doda się

   printWholeInfo(cMan,rMan,mMan);

   cout <<endl<<  "################renting machine################" << endl;
   rMan.rentVirtualMachine(cMan.getClient(247653),mMan.getVirtualMachine(3),boost::posix_time::not_a_date_time);
   

   VirtualMachinePredicate isUbuntu = [](VirtualMachinePtr vm) {
      return vm->getOperatingSystem() == "Ubuntu"; 
   };
   ClientPredicate isWoman = [](ClientPtr ct) { //xDDD przepraszam
      return ct->getFirstName() == "Agata";
   };
   auto r1 = rMan.rentVirtualMachine(cMan.findClients(isWoman).front(),mMan.findVirtualMachines(isUbuntu).front(),boost::posix_time::not_a_date_time);
   auto r2 = rMan.rentVirtualMachine(cMan.findClients(isWoman).front(),mMan.getVirtualMachine(2),boost::posix_time::not_a_date_time); //default nie wypozyczy dwoch maszyn na raz 
   auto r3 = rMan.rentVirtualMachine(cMan.getClient(247653),mMan.getVirtualMachine(2),boost::posix_time::not_a_date_time); //ale uzytkownik pro moze

   printWholeInfo(cMan,rMan,mMan);

   cout <<endl<<  "####################ending all rents###############" << endl;

   rMan.returnVirtualMachine(v1);
   rMan.returnVirtualMachine(mMan.getVirtualMachine(2));
   rMan.returnVirtualMachine(mMan.getVirtualMachine(3));

   printWholeInfo(cMan,rMan,mMan);

   
}
