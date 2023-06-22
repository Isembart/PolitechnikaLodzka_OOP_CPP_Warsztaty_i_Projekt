#include <boost/test/unit_test.hpp>
#include "model/VirtualMachine.hpp"
#include "model/ClientTypes/Default.hpp"
#include "model/Repositories/Mainframe.hpp"
#include <memory>
struct TestSuiteMainframeFixture {
    const int testphysicalMemory = 89;
    const int testremainingMemory  = 91;

    TestSuiteMainframeFixture() {
    }

    ~TestSuiteMainframeFixture() {
    }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteMainframeFixture)

//test getterów

    BOOST_AUTO_TEST_CASE(GettersTests) {
        Mainframe mainframe1(testphysicalMemory,testremainingMemory,std::make_shared<Default>());
        BOOST_TEST_REQUIRE(mainframe1.getPhysicalMemory() == testphysicalMemory);
        BOOST_TEST_REQUIRE(mainframe1.getFreePhysicalMemory() == testremainingMemory);
    }

//
//
//    BOOST_AUTO_TEST_CASE(reportTest)
//
//    {
//        Mainframe mainframe1(testphysicalMemory,testremainingMemory,std::make_shared<Default>());
//        std::string info = mainframe1.repo.at()->get(0)->getVirtualMachineInfo() + "\n" + mainframe1.repo.at()->get(1)->getVirtualMachineInfo() + "\n";
//        BOOST_TEST(mainframe1.repo.at()->report() == info);
//    }
//

BOOST_AUTO_TEST_SUITE_END()