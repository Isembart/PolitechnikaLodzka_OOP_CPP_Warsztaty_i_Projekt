#include <boost/test/unit_test.hpp>
#include "model/VirtualMachine.hpp"
#include "typedefs.hpp"
#include "model/ClientTypes/Pro.hpp"
#include <memory>
#include "model/Managers/MainframeManager.hpp"

BOOST_AUTO_TEST_SUITE()

    BOOST_AUTO_TEST_CASE(MainframeManager_Test_id)
    {
        // MainframeManager manager(4000);
        MainframeManager manager(4000);
        manager.registerVirtualmachine(2, "Linux", 512);
        manager.registerVirtualmachine(666, "Linux", 1024);
        manager.registerVirtualmachine(3, "Kocham", 1024);
        manager.registerVirtualmachine(4, "Fedore", 512);

        // Sprawdzenie czy mamy maszyne Linux
        VirtualMachinePredicate linuxPredicate = [](VirtualMachinePtr vm) {
            return vm->getOperatingSystem() == "Linux";
        };

        std::vector<VirtualMachinePtr> TestVMs = manager.findVirtualMachines(linuxPredicate);

        BOOST_TEST(TestVMs.size() == 2); // Sprawdzenie, czy zwrócono poprawną liczbę maszyn
        BOOST_TEST(manager.findAllVirtualMachines().size() == 4); // Sprawdzenie, czy zwrócono poprawną liczbę maszyn
        BOOST_TEST(TestVMs[0]->getId() == 2); // Sprawdzenie, czy pierwsza zwrócona maszyna ma poprawne ID
        BOOST_TEST(TestVMs[1]->getId() == 666); // Sprawdzenie, czy druga zwrócona maszyna ma poprawne ID
    };

BOOST_AUTO_TEST_SUITE_END()