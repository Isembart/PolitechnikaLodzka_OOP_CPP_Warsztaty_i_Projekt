#include <boost/test/unit_test.hpp>
#include "model/Managers/ClientManager.h"
#include "repositories/ClientRepository.h"
#include "typyedefs.h"
#include <memory>
#include "model/Client.h"

struct ClientManagerFixture {

    ClientManager manager;
    ClientManagerFixture() {
        
    }
    ~ClientManagerFixture() {

    }
};

BOOST_FIXTURE_TEST_SUITE(ClientManagerTests,ClientManagerFixture)

BOOST_AUTO_TEST_CASE(regsiterClient) {
    manager.registerClient("Mariusz","Pudzianowski",14,nullptr,nullptr);

    ClientPtr ptr = manager.registerClient("Mariusz","Pudzianowski",13,nullptr,nullptr);
    
    manager.registerClient("Mariusz","Pudzianowski",15,nullptr,nullptr);

    BOOST_TEST(manager.registerClient("Drugi","Pudzian LOL",13,nullptr,nullptr)==ptr);
}

BOOST_AUTO_TEST_CASE(getClient) {

    manager.registerClient("Mariusz","Pudzianowski",14,nullptr,nullptr);
    ClientPtr ptr = manager.registerClient("Mariusz","Pudzianowski",13,nullptr,nullptr);
    manager.registerClient("Mariusz","Pudzianowski",15,nullptr,nullptr);

    BOOST_TEST(ptr == manager.getClient(13));
}

BOOST_AUTO_TEST_CASE(findClients) {
    manager.registerClient("Pierwszy","test",14,nullptr,nullptr);
    manager.registerClient("Drugi","1",15,nullptr,nullptr);
    manager.registerClient("Trzeci","Pudzianowski",16,nullptr,nullptr);

    ClientPredicate isPudzianowski = [](ClientPtr ptr) {
        return ptr->getLastName() == "Pudzianowski";
    }; 
    BOOST_REQUIRE(manager.findClients(isPudzianowski).size() == 1);

    BOOST_TEST(manager.findAllClients().size() == 3);


    manager.unregisterClient(16);
    BOOST_TEST(manager.findClients(isPudzianowski).size() == 0);

    //FIND ALL
    BOOST_TEST(manager.findAllClients().size() == 2);
}



BOOST_AUTO_TEST_SUITE_END()