#include <boost/test/unit_test.hpp>
#include "repositories/ClientRepository.h"
#include "repositories/StorageContainer.h"
#include "typyedefs.h"

struct TestSuiteClientRepoFixture {
    StorageContainer container;
    TestSuiteClientRepoFixture() {

    }
    ~TestSuiteClientRepoFixture() {

    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClientRepo,TestSuiteClientRepoFixture)

    
    BOOST_AUTO_TEST_CASE(getValidIndexTest) {
        BOOST_TEST(container.getClientRepo()->get(0)->getFirstName() == "Mariusz");
        BOOST_TEST(container.getClientRepo()->get(1)->getFirstName() == "Roman");
    }

    BOOST_AUTO_TEST_CASE(getInvalidIndextText) {
        BOOST_TEST(container.getClientRepo()->get(-100) == nullptr);
        BOOST_TEST(container.getClientRepo()->get(5000) == nullptr);
    }

    BOOST_AUTO_TEST_CASE(addTestValidArgument) {
        
        Client newTestClient("Teść","Testowy",0,nullptr);
        container.getClientRepo()->add(&newTestClient);
        BOOST_TEST(container.getClientRepo()->get(2)->getFirstName() == "Teść");
    }

    BOOST_AUTO_TEST_CASE(sizeTest) {
        BOOST_TEST_REQUIRE(container.getClientRepo()->size() == 2);
    }

    BOOST_AUTO_TEST_CASE(removeTestValidArgument) {    
        // Client newTestClient("Teść","Testowy",0,nullptr);
        // container.getClientRepo()->add(&newTestClient);
        BOOST_TEST_REQUIRE(container.getClientRepo()->size() == 2);
        container.getClientRepo()->remove(container.getClientRepo()->get(1));
        BOOST_TEST(container.getClientRepo()->size() == 1);
    }

    BOOST_AUTO_TEST_CASE(removeTestInvalidArgument) {    
        // Client newTestClient("Teść","Testowy",0,nullptr);
        // container.getClientRepo()->add(&newTestClient);
        BOOST_TEST_REQUIRE(container.getClientRepo()->size() == 2);
        container.getClientRepo()->remove(nullptr);
        BOOST_TEST(container.getClientRepo()->size() == 2);
    }
    

    BOOST_AUTO_TEST_CASE(reportTest) {    
        // Client newTestClient("Teść","Testowy",0,nullptr);
        // container.getClientRepo()->add(&newTestClient);
        std::string info = container.getClientRepo()->get(0)->getClientInfo() + "\n" + container.getClientRepo()->get(1)->getClientInfo() + "\n";
        BOOST_TEST(container.getClientRepo()->report() == info);
    }

BOOST_AUTO_TEST_SUITE_END()