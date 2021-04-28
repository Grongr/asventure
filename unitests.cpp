//
// Created by grongr on 2/20/21.
//

#include "unitests.h"
#include "geometricvector.h"
#include "spaceship.h"

#include <cmath>

//-----------------------------------------------------------------------------------------------------------//
//! Testing move_ship
#define TEST(TestNum, R_0, V_0, AVec, Builder, Mass, FuelCost, TIME, RRes)     \
    {                                                                          \
        SpaceShip sps(Builder, Mass, FuelCost, R_0, V_0, AVec);                \
                                                                               \
        sps.toggle_engine();                                                   \
        sps.move_ship(TIME);                                                   \
        check_unit_test(TestNum, sps.get_position(), RRes);           \
    }

bool check_unit_test(int test_num, Vector const& R0, Vector const& R) {
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
        check_unit_test(TEST_NUM, psh.get_position(), RRes); \
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
    // Test 4
    {
        EnergyFuelSystemBuilder builder{0, 0, 0, 0, 0};
        PirateShipBuilder pbl;
        make_default_psh(pbl);

        pbl.add_point(Vector(0, 1));
        pbl.add_point(Vector(0, 2));
        pbl.add_point(Vector(1, 2));

        PirateShip psh = *(pbl.make_pirate_ship(builder));
        TEST(4, psh, 3, Vector(1, 2))
    }
    // Test 5
    {
        EnergyFuelSystemBuilder builder{0, 0, 0, 0, 0};
        PirateShipBuilder pbl;
        make_default_psh(pbl);

        pbl.add_point(Vector(0, 5));
        pbl.add_point(Vector(0, 0));

        PirateShip psh = *(pbl.make_pirate_ship(builder));
        TEST(5, psh, 6, Vector(0, 4))
    }
    // Test 6
    {
        EnergyFuelSystemBuilder builder{0, 0, 0, 0, 0};
        PirateShipBuilder pbl;
        make_default_psh(pbl);

        pbl.add_point(Vector(0, 5));
        pbl.add_point(Vector(0, 0));

        PirateShip psh = *(pbl.make_pirate_ship(builder));
        TEST(6, psh, 10, Vector(0, 0))
    }
    // Test 7
    {
        EnergyFuelSystemBuilder builder{0, 0, 0, 0, 0};
        PirateShipBuilder pbl;
        make_default_psh(pbl);

        pbl.add_point(Vector(0, 5));
        pbl.add_point(Vector(0, 1));

        PirateShip psh = *(pbl.make_pirate_ship(builder));
        try {
            TEST(7, psh, 11, Vector(0, 1))
        } catch(ZeroSpeedError& err) {
            std::cout << "In test 4: " << err.what() << std::endl;
        }
    }
    // Test 8 - 10
    {
        EnergyFuelSystemBuilder builder{0, 0, 0, 0, 0};
        PirateShipBuilder pbl;
        make_default_psh(pbl);

        pbl.add_point(Vector(0, 5));
        pbl.add_point(Vector(0, 1));

        
        PirateShip psh = *(pbl.make_pirate_ship(builder));
        TEST( 8, psh, 4, Vector(0, 4))
        TEST( 9, psh, 4, Vector(0, 2))
        TEST(10, psh, 4, Vector(0, 2))
    }
}

#undef TEST

#define TEST(test_num, polsh, time, RRes)

void make_standart_police_ship(PoliceShipBuilder &builder) {
    builder.set_fuel_cost(0);
    builder.set_is_engine_active(true);
    builder.set_AVec(Vector(0, 0));
    builder.set_R(Vector(0, 0));
    builder.set_mass(0);
}

void police_ship_move_unit_test() {
    // Test 11
    {
        EnergyFuelSystemBuilder builder{0, 0, 0, 0, 0};
        PoliceShipBuilder pbl;
        make_standart_police_ship(pbl);

        Vector cr(1, 0);
        pbl.set_center_coords(cr);
        pbl.set_radius(cr.length());
        pbl.set_V(Vector(0, 1));

        auto polsh = pbl.make_police_ship(builder);
        TEST(11, polsh, , Vector(1, 0))       
    }
}
