#include "quests.h"

class Player
{
    private:
        int money;   // Money for quests 
        int guns;    // Guns' state
        int health;  // Ship's state
        Quest quest; // Current quest

    public:
        int GetMoney();
        int GetGuns();
        int GetHealth();
        void NewQuest();
}
