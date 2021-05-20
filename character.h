#ifndef CHARACTER_HEADER_INCLUDED
#define CHARACTER_HEADER_INCLUDED

#include <memory>
#include <string>

#include "sps_errors.h"

//-----------------------------------------------------------------------------------------------------------//
class Character {
public:

    /*!
     * Constructor with no params.
     */
    Character() : _ammo_count{0}, _damage{0}, _armor{0},
                  _money{0},      _BFG{0},    _hp{0}     {}

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
           int money, int BFG, int hp) : 
           _ammo_count{ammo_count}, _damage{damage}, _armor{armor},
           _money{money}, _BFG{BFG}, _hp{hp}, _is_alive{true} {}
    
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
     * Methos which is needed to
     * attack character's enemy
     * @param enemy  -  character's enemy
     * @return damage or 0 if you cannot hit the target
     */
    int attack(Character& enemy) const;

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

private:
    int _ammo_count;
    int _damage;
    int _armor;
    int _money;
    int _BFG;
    int _hp;

    bool _is_in_maneuver;
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
     * Method that makes it possible to create character
     * from bulder class object
     */
    [[nodiscard]] std::shared_ptr<Character> make_char() const {
        if (count_of_params != 6)
            throw CharacterBParamCountError("Wrong param number. You set " + std::to_string(6) + ", but needed 6");
        std::shared_ptr<Character> chr(new Character(ammo_count, damage, armor, money, BFG, hp));

        return chr;
    }
    
private:
    int ammo_count;
    int damage;
    int armor;
    int money;
    int BFG;
    int hp;

    int count_of_params{0};
};

#endif // CHARACTER_HEADER_INCLUDED
