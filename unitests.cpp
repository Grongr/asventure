//
// Created by grongr on 2/20/21.
//

#include "unitests.h"

//-----------------------------------------------------------------------------------------------------------//
//! Testing move_ship
#define TEST(TestNum, R_0, V_0, AVec, Builder, Mass, FuelCost, TIME, RRes)     \
    {                                                                          \
        SpaceShip sps(Builder, Mass, FuelCost, R_0, V_0, AVec);                \
                                                                               \
        sps.toggle_engine();                                                   \
        sps.move_ship(TIME);                                                   \
        sps_move_check_unit_test(TestNum, sps.get_position(), RRes);           \
    }

bool sps_move_check_unit_test(int test_num, Vector const& R0, Vector const& R) {
    if (R0 != R) {
        std::cout << "Spaceship move method test number " << test_num << " not passed!" << std::endl;

        std::cout << "The vector that we got" << std::endl;
        R0.print_vector();
        std::cout << "The vector we needed" << std::endl;
        R.print_vector();

        return false;
    } else {
        std::cout << "Spaceship move method test number " << test_num << " passed correctly :)" << std::endl;
        return true;
    } }

void sps_move_unit_test() {
    {
        EnergyFuelSystemBuilder builder(10, 1000.0, 1, 1, 10000);
        TEST(1, Vector(0, 20), Vector(10, 0), Vector(0, -10),
             builder, 10000, 1.0, 2.0, Vector(20, 0))
    }

    {
        EnergyFuelSystemBuilder builder(10, 0.2, 1, 1, 100000);
        TEST(2, Vector(0, 20), Vector(10, 0), Vector(0, -10),
             builder, 10000, 1.0, 4.0, Vector(40, -40))
    }

    {
        EnergyFuelSystemBuilder builder(10, 10000, 1, 1, 10000);
        TEST(3, Vector(0, 20), Vector(10, 0), Vector(0, -10),
             builder, 10000, 10000, 4.0, Vector(40, -15))
    }
}

#undef TEST

#define TEST(TEST_NUM, psh, TIME, RRes)                                       \
    {                                                                         \
        psh.move_ship_forward(TIME);                                                  \
        pirate_ship_move_check_unit_test(TEST_NUM, psh.get_position(), RRes); \
    }

bool pirate_ship_move_check_unit_test(int tn, Vector const& R, Vector const& RRes) {
    if (R != RRes) {
        std::cout << "PirateShip move forward func test number " << tn << " not passed!!!" << std::endl;
        std::cout << "The Vector we got: ";
        R.print_vector();
        std::cout << "The Vector we needed: ";
        RRes.print_vector();

        return false;
    } else {
        std::cout << "PirateShip move forward func test number " << tn << " passed correctly" << std::endl;
        return true;
    }
}

void make_default_psh(PirateShipBuilder& pbl) {
    pbl.set_fuel_cost(0);
    pbl.set_is_engine_active(true);
    pbl.set_AVec(Vector(0, 0));
    pbl.set_R(Vector(0, 0));
    pbl.set_V(Vector(0, 0));
    pbl.set_mass(0);
    pbl.set_head_cost(0);
}

void pirate_ship_move_unit_test() {
    // Test 1
    {
        EnergyFuelSystemBuilder builder{0, 0, 0, 0, 0};
        PirateShipBuilder pbl;
        make_default_psh(pbl);

        pbl.add_point(Vector(0, 1));
        pbl.add_point(Vector(0, 2));
        pbl.add_point(Vector(1, 2));

        PirateShip psh = *(pbl.make_pirate_ship(builder));
        TEST(1, psh, 3, Vector(1, 2))
    }
    // Test 2
    {
        EnergyFuelSystemBuilder builder{0, 0, 0, 0, 0};
        PirateShipBuilder pbl;
        make_default_psh(pbl);

        pbl.add_point(Vector(0, 5));
        pbl.add_point(Vector(0, 0));

        PirateShip psh = *(pbl.make_pirate_ship(builder));
        TEST(2, psh, 6, Vector(0, 4))
    }
    // Test 3
    {
        EnergyFuelSystemBuilder builder{0, 0, 0, 0, 0};
        PirateShipBuilder pbl;
        make_default_psh(pbl);

        pbl.add_point(Vector(0, 5));
        pbl.add_point(Vector(0, 0));

        PirateShip psh = *(pbl.make_pirate_ship(builder));
        TEST(3, psh, 10, Vector(0, 0))
    }
    // Test 4
    {
        EnergyFuelSystemBuilder builder{0, 0, 0, 0, 0};
        PirateShipBuilder pbl;
        make_default_psh(pbl);

        pbl.add_point(Vector(0, 5));
        pbl.add_point(Vector(0, 1));

        PirateShip psh = *(pbl.make_pirate_ship(builder));
        try {
            TEST(4, psh, 11, Vector(0, 1))
        } catch(ZeroSpeedError& err) {
            std::cout << "In test 4: " << err.what() << std::endl;
        }
    }
    // Test 5 - 7
    {
        EnergyFuelSystemBuilder builder{0, 0, 0, 0, 0};
        PirateShipBuilder pbl;
        make_default_psh(pbl);

        pbl.add_point(Vector(0, 5));
        pbl.add_point(Vector(0, 1));

        PirateShip psh = *(pbl.make_pirate_ship(builder));
        TEST(5, psh, 4, Vector(0, 4))
        TEST(6, psh, 4, Vector(0, 2))
        TEST(7, psh, 4, Vector(0, 2))
    }
}

#undef TEST
