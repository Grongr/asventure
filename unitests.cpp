//
// Created by grongr on 2/20/21.
//

#include "unitests.h"
#include "character.h"
#include "dialogue.h"
#include "geometricvector.h"
#include "pirateship.h"
#include "policeship.h"
#include "spaceship.h"

#include <cmath>
#include <ios>

//-----------------------------------------------------------------------------------------------------------//
//! Testing move_ship
#define TEST(TestNum, R_0, V_0, AVec, Builder, Mass, FuelCost, TIME, RRes)     \
    {                                                                          \
        SpaceShip sps(Builder, Mass, FuelCost, R_0, V_0, AVec);                \
                                                                               \
        sps.toggle_engine();                                                   \
        sps.move_ship(TIME);                                                   \
        check_unit_test(TestNum, sps.get_position(), RRes);                    \
    }

bool check_unit_test(int test_num, Vector const& R0, Vector const& R) {
    if (R0 != R) {
        std::cout << "#######################" << std::endl;
        std::cout << "Test number " << test_num << " not passed!" << std::endl;

        std::cout << "The vector that we got" << std::endl;
        R0.print_vector();
        std::cout << "The vector we needed" << std::endl;
        R.print_vector();

        return false;
    } else {
        /* std::cout << "Test number " << test_num << " passed correctly :)" << std::endl; */
        return true;
    }
}

void sps_move_unit_test() {
    {
        EnergyFuelSystemBuilder builder;
        builder.set_size_of_bat_arr(10);
        builder.set_bat_energy(1000);
        builder.set_fu(1);
        builder.set_fQ(1);
        builder.set_fmv(10000);
        
        SpaceShipBuilder sbuilder;
        sbuilder.set_R(Vector(0, 20));
        sbuilder.set_V(Vector(10, 0));
        sbuilder.set_AVec(Vector(0, -10));
        sbuilder.set_mass(10000);
        sbuilder.set_fuel_cost(1.0);
        sbuilder.set_is_engine_active(true);

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

        auto ptr = pbl.make_pirate_ship(builder);
        PirateShip psh = *ptr;
        TEST(4, psh, 3, Vector(1, 2))
    }
    // Test 5
    {
        EnergyFuelSystemBuilder builder{0, 0, 0, 0, 0};
        PirateShipBuilder pbl;
        make_default_psh(pbl);

        pbl.add_point(Vector(0, 5));
        pbl.add_point(Vector(0, 0));

        auto ptr = pbl.make_pirate_ship(builder);
        PirateShip psh = *ptr;
        TEST(5, psh, 6, Vector(0, 4))
    }
    // Test 6
    {
        EnergyFuelSystemBuilder builder{0, 0, 0, 0, 0};
        PirateShipBuilder pbl;
        make_default_psh(pbl);

        pbl.add_point(Vector(0, 5));
        pbl.add_point(Vector(0, 0));

        auto ptr = pbl.make_pirate_ship(builder);
        PirateShip psh = *ptr;
        TEST(6, psh, 10, Vector(0, 0))
    }
    // Test 7
    {
        EnergyFuelSystemBuilder builder{0, 0, 0, 0, 0};
        PirateShipBuilder pbl;
        make_default_psh(pbl);

        pbl.add_point(Vector(0, 5));
        pbl.add_point(Vector(0, 1));

        auto ptr = pbl.make_pirate_ship(builder);
        PirateShip psh = *ptr;
        TEST(7, psh, 11, Vector(0, 1))
    }
    // Test 8 - 10
    {
        EnergyFuelSystemBuilder builder{0, 0, 0, 0, 0};
        PirateShipBuilder pbl;
        make_default_psh(pbl);

        pbl.add_point(Vector(0, 5));
        pbl.add_point(Vector(0, 1));

        
        auto ptr = pbl.make_pirate_ship(builder);
        PirateShip psh = *ptr;
        TEST( 8, psh, 4, Vector(0, 4))
        TEST( 9, psh, 4, Vector(0, 2))
        TEST(10, psh, 4, Vector(0, 2))
    }
}

#undef TEST

#define TEST(test_num, polsh, time, RRes)                       \
    {                                                           \
        polsh->move_along_circle(time);                         \
                                                                \
        check_unit_test(test_num, polsh->get_position(), RRes); \
    }

void make_standart_police_ship(PoliceShipBuilder &builder) {
    builder.set_fuel_cost(0);
    builder.set_is_engine_active(true);
    builder.set_AVec(Vector(0, 0));
    builder.set_mass(0);
    builder.set_V(Vector(0, 0));
}

void police_ship_move_unit_test() {
    // Test 11, 12, 13, 14
    {
        EnergyFuelSystemBuilder builder{0, 0, 0, 0, 0};
        PoliceShipBuilder pbl;
        make_standart_police_ship(pbl);

        pbl.set_R(Vector(0, 0));
        Vector cr(1, 0);
        pbl.set_center_coords(cr);
        pbl.set_radius(cr.length());
        pbl.set_angV(pi() / 2);

        auto polsh = pbl.make_police_ship(builder);
        TEST(11, polsh, 1, Vector(1,  1))       
        TEST(12, polsh, 1, Vector(2,  0))       
        /* TEST(13, polsh, 1, Vector(1, -1)) */       
        /* TEST(14, polsh, 1, Vector(0,  0)) */       
    }
    // Test 15
    {
        EnergyFuelSystemBuilder builder{0, 0, 0, 0, 0};
        PoliceShipBuilder pbl;
        make_standart_police_ship(pbl);
        pbl.set_R(Vector(-1, 0));
        pbl.set_center_coords(Vector(0, 0));
        pbl.set_radius(1);
        pbl.set_angV(pi() / 2);

        auto polsh = pbl.make_police_ship(builder);
        TEST(15, polsh, 1, Vector(0, 1))
    }
    // Test 16
    {
        EnergyFuelSystemBuilder builder{0, 0, 0, 0, 0};
        PoliceShipBuilder pbl;
        make_standart_police_ship(pbl);
        pbl.set_R(Vector(-1, 0));
        pbl.set_center_coords(Vector(0, 0));
        pbl.set_radius(1);
        pbl.set_angV(pi() / 4);

        auto polsh = pbl.make_police_ship(builder);
        TEST(16, polsh, 1, Vector(-1 / std::sqrt(2), 1 / std::sqrt(2)))
    }
}

void character_method_unit_test() {
    // Test 17
    CharacterBuilder chb1;
    CharacterBuilder chb2;

    chb1.set_ammo_count(10000);
    chb1.set_BFG(9);
    chb1.set_damage(3);
    chb1.set_armor(15);
    chb1.set_money(0);
    chb1.set_hp(40);

    chb2.set_ammo_count(50);
    chb2.set_BFG(13);
    chb2.set_damage(5);
    chb2.set_armor(18);
    chb2.set_money(10000);
    chb2.set_hp(40);

    
    // This spaceship will be able to fly from top left to the
    // bottom right angles of map, when it has a full fuel tank

    EnergyFuelSystemBuilder builder{10, 10, 1, 60, 6000};
    SpaceShipBuilder spb;
    spb.set_fuel_cost(1);
    spb.set_AVec(Vector(0, 0));
    spb.set_R(Vector(0, 0));
    spb.set_V(Vector(0, 0));
    spb.set_mass(1000);
    spb.set_is_engine_active(false);
       
    chb1.set_ship(spb.make_spaceship(builder));

    auto player = chb1.make_char();

    EnergyFuelSystemBuilder builder2{1, 100000, 1, 60, 10000000};
    chb2.set_ship(spb.make_spaceship(builder2));

    auto enemy = chb2.make_char();

    std::cout << "################################" << std::endl;

    std::cout << "Player  Enemy" << std::endl;
    std::cout << player->hp() << " " << enemy->hp() << std::endl;

    std::cout << "################################" << std::endl;

    int damage = player->attack(*enemy);
    std::cout << "Player Attacks Enemy. Damage: " << damage << std::endl;
    std::cout << player->hp() << " " << enemy->hp() << std::endl;

    std::cout << "################################" << std::endl;

    damage = enemy->attack(*player);
    std::cout << "Enemy attacks player. Damage: " << damage << std::endl;
    std::cout << player->hp() << " " << enemy->hp() << std::endl;

    std::cout << "################################" << std::endl;

    player->active_defence();
    std::cout << "Player Attacks Enemy. Damage: " << damage << std::endl;
    std::cout << player->hp() << " " << enemy->hp() << std::endl;

    std::cout << "################################" << std::endl;

    damage = enemy->attack(*player);
    std::cout << "Enemy attacks player. Damage: " << damage << std::endl;
    std::cout << player->hp() << " " << enemy->hp() << std::endl;

    std::cout << "################################" << std::endl;

    std::cout << "Player make a maneuver" << std::endl;
    damage = player->maneuver(*enemy);
    std::cout << std::boolalpha;
    std::cout << "Is in maneuver: " << player->is_in_maneuver() << std::endl;

    std::cout << "################################" << std::endl;

    damage = enemy->maneuver(*player);
    std::cout << std::boolalpha;
    std::cout << "Is in maneuver: " << player->is_in_maneuver() << std::endl;
    std::cout << "Enemy maneuver to player. Damage: " << damage << std::endl;
    std::cout << player->hp() << " " << enemy->hp() << std::endl;

    std::cout << "################################" << std::endl;

    damage = player->attack(*player);
    std::cout << std::boolalpha;
    std::cout << "Is in maneuver: " << player->is_in_maneuver() << std::endl;
    std::cout << "Player attack enemy. Damage: " << damage << std::endl;
    std::cout << player->hp() << " " << enemy->hp() << std::endl;
}

// Dialogue class test
void dio_test() {
    Dialogue dlg("../dialogues/pirate0.dlg");
    dlg.print_dialogues(std::cout);
}

#undef TEST
