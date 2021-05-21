#ifndef CHARACTER_HEADER_INCLUDED
#define CHARACTER_HEADER_INCLUDED

#include <memory>
#include <random>
#include <string>

#include "sps_errors.h"
#include "spaceship.h"

#define max_enemy_hills 5

//-----------------------------------------------------------------------------------------------------------//
class Character {
public:

    /*!
     * Constructor with all the params of character class
     * @param ammo_count  -  number of shots
     * @param is_alive    -  true if character is alive, false if not
     * @param damage      -  attack skill of this character
     * @param armor       -  armor index of this character
     * @param money       -  are you rich and famous or are you a loser?
     * @param BFG         - Big Fucking Gun ( attack index of character ship )
     * @param hp          - Health Points of player ship
     */
    Character(int ammo_count, int damage, int armor,
           int money, int BFG, int hp, std::shared_ptr<SpaceShip> ship) : 
           _ammo_count{ammo_count}, _damage{damage}, _armor{armor},
           _money{money}, _BFG{BFG}, _hp{hp}, _max_hp{hp}, _is_alive{true},
           ship{ship}, _is_in_defence{false}, _is_in_maneuver{false} {}
    
    /*!
     * @return ammo_count param
     */
    [[nodiscard]] int ammo_count() const;

    /*!
     * @return armor param
     */
    [[nodiscard]] int damage() const;

    /*!
     * @return money param
     */
    [[nodiscard]] int armor() const;

    /*!
     * @return money param
     */
    [[nodiscard]] int money() const;

    /*!
     * @return BFG param
     */
    [[nodiscard]] int BFG() const;

    /*!
     * @return hp param
     */
    [[nodiscard]] int hp() const;

    /*!
     * @return is character alive or not
     */
    [[nodiscard]] bool is_alive() const;

    /*!
     * @return true if it is in maneuver
     */
    [[nodiscard]] bool is_in_maneuver() const;

    /*!
<<<<<<< HEAD
     * @return _is_in_defence param
     */
    [[nodiscard]] bool is_in_defence() const;

    /*!
     * @return ship param
     */
    [[nodiscard]] std::shared_ptr<SpaceShip> get_ship() const;

    /*!
=======
>>>>>>> origin/graphics
     * Methos which is needed to
     * attack character's enemy
     * @param enemy  -  character's enemy
     * @return damage or 0 if you cannot hit the target
     */
    int attack(Character& enemy);

    /*!
     * Method that makes character dead.
     */
    void die_mf_die();

    /*!
     * Method which should be called when 
     * character starts to maneuver
     * @return your param is_in_maneuver after running func
     */
    bool maneuver(Character& enemy);
    
    /*!
     * Changes maneuver param
     */
    void toggle_maneuver();

    /*!
     * makes _is_in_defence param opposite
     */
    void toggle_active_defence();

    /*!
     * Makes _is_in_defence param true;
     */
    void active_defence();

    /*!
     * You reward
     * @param  -  addition to your _money param
     */
    void reward(int money);

    /*!
     * Add 1d8 to hp param.
     * Uses battery energy.
     * @return result hp
     */
    int repair();

    /*!
     * If you wanna do a random shit with 
     * your character
     */
    void random_act(Character& player);

    /*!
     * Enemie's ai. In battle it uses
     * this as a brain. Maybe that's
     * the reason why all pirates are
     * stupid???
     * @param player  -  player character class instance
     * @param enemy   -  enemy character class instance
     */
    static void enemy_ai(Character& player, Character& enemy) {
        double persent = enemy._hp / enemy._max_hp * 100;

        std::random_device rd;

        if (rd() % 10 == 0) {
           enemy.random_act(player); 
           enemy.random_act(player); 
        }
        // if rd() % 10 != 0
        else {
            if (is_bigger(persent, 40.0)) {
                if (player.is_in_defence())
                    enemy.maneuver(player);

                enemy.attack(player);
            // -------------------------------------- //
            } else if (is_bigger(persent, 10.0)) {

                if (enemy._hill_count <= max_enemy_hills) {

                    enemy.repair();
                    ++enemy._hill_count;

                } else {
                    enemy.active_defence();
                }

                if (enemy._hill_count <= max_enemy_hills) {

                    enemy.repair();
                    ++enemy._hill_count;

                } else {
                    enemy.attack(player);
                }
            // -------------------------------------- //
            } else {
                enemy.attack(player);
                enemy.attack(player);
            }
        }
    }

private:
    std::shared_ptr<SpaceShip> ship;
    int _hill_count{0};
    int _ammo_count;
    int _damage;
    int _armor;
    int _money;
    int _BFG;
    int _hp;

    const int _max_hp;

    bool _is_in_maneuver{false};
    bool _is_in_defence{false};
    bool _is_alive{false};
};

//-----------------------------------------------------------------------------------------------------------//

class CharacterBuilder {
public:

    /*!
     * Default constructor without any params
     */
    CharacterBuilder() :
        ammo_count{0}, damage{0}, armor{0},
        money{0},      BFG{0},    hp{0}     {}

    /*!
     * Sets ammo_count param.
     * @param ammo_count
     */
    void set_ammo_count(int ammo_count);

    /*!
     * Sets armor param.
     * @param armor
     */
    void set_armor(int armor);
    
    /*!
     * Sets damage param
     * @param damage
     */
    void set_damage(int damage);

    /*!
     * Sets money param
     * @param money
     */
    void set_money(int money);

    /*!
     * Sets BFG param
     * @param BFG
     */
    void set_BFG(int BFG);

    /*!
     * Sets hp param
     * @param hp
     */
    void set_hp(int hp);

    /*!
<<<<<<< HEAD
     * Sets ship param
     * @param ship
     */
    void set_ship(std::shared_ptr<SpaceShip> ship);

    /*!
=======
>>>>>>> origin/graphics
     * Method that makes it possible to create character
     * from bulder class object
     */
    [[nodiscard]] std::shared_ptr<Character> make_char() const {
        if (count_of_params != 7)
            throw CharacterBParamCountError("Wrong param number. You set " + std::to_string(count_of_params) + ", but needed 7");
        std::shared_ptr<Character> chr(new Character(ammo_count, damage, armor, money, BFG, hp, ship));
        return chr;
    }
    
private:
    std::shared_ptr<SpaceShip> ship;

    int ammo_count;
    int damage;
    int armor;
    int money;
    int BFG;
    int hp;

    int count_of_params{0};
};

#endif // CHARACTER_HEADER_INCLUDED
