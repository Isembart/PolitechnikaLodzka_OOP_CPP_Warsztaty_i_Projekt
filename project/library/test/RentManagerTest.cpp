#include <boost/test/unit_test.hpp>
#include "model/Managers/RentManager.hpp"
#include "model/VirtualMachine.hpp"
#include "typedefs.hpp"
#include "model/ClientTypes/Pro.hpp"
#include <memory>

BOOST_AUTO_TEST_SUITE()

BOOST_AUTO_TEST_CASE(RentVirtualMachine_Test)
{

    //Ten sam kod w mainie działa bez zarzutów...
    RentManager rentManager;
    ClientTypePtr proType = std::make_shared<Pro>();
    ClientPtr client = std::make_shared<Client>("Mariusz","pudzian",12,proType);
    VirtualMachinePtr vm1 = std::make_shared<VirtualMachine>(1,"Ubuntu",4000);
    boost::posix_time::ptime startTime = boost::posix_time::second_clock::local_time();

    RentPtr rent = rentManager.rentVirtualMachine(client, vm1, startTime);

    BOOST_TEST(rent != nullptr);
    BOOST_CHECK(rent->getClient() == client);
    BOOST_CHECK(rent->getVirtualMachine() == vm1);
    BOOST_CHECK(rent->getBeginTime() == startTime);

}

BOOST_AUTO_TEST_SUITE_END()
