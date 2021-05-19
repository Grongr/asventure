#include <random>
#include "character.h"

//------------------------------------------CharacterMethods-------------------------------------------------//

[[nodiscard]] int  Character::ammo_count() const { return _ammo_count; }

[[nodiscard]] int  Character::damage()     const { return _damage; }

[[nodiscard]] int  Character::armor()      const { return _armor; }

[[nodiscard]] int  Character::money()      const { return _money; }

[[nodiscard]] int  Character::BFG()        const { return _BFG; }

[[nodiscard]] int  Character::hp()         const { return _hp; }

[[nodiscard]] bool Character::is_alive()   const { return _is_alive; }


void Character::die_mf_die() { this->_is_alive = false; }


void Character::attack(Character& enemy) const {
    std::random_device rd; 

    int attack = ( rd() % 20 + 1 ) + this->BFG();

    // If attack is bigger then enemy defence
    if (enemy.armor() < attack) {
        int result_damage = 0;

        result_damage += rd() % 6 + 1;
        result_damage += rd() % 6 + 1;
        result_damage += rd() % 6 + 1;

        result_damage += this->damage();

        enemy._hp -= result_damage;
        
        if (enemy.hp() <= 0)
            enemy.die_mf_die();
    }

    return;
}

//-------------------------------------------CharacterBuilder------------------------------------------------//

void CharacterBuilder::set_ammo_count(int ammo_count) { this->ammo_count = ammo_count; ++count_of_params; }

void CharacterBuilder::set_damage(int damage)         { this->damage = damage; ++count_of_params; }

void CharacterBuilder::set_armor(int armor)           { this->armor = armor; ++count_of_params; }

void CharacterBuilder::set_money(int money)           { this->money = money; ++count_of_params; }

void CharacterBuilder::set_BFG(int BFG)               { this->BFG = BFG; ++count_of_params; }

void CharacterBuilder::set_hp(int hp)                 { this->hp = hp; ++count_of_params; }

//-----------------------------------------------------------------------------------------------------------//
