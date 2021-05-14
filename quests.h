#ifndef QUEST_H
#define QUEST_H

/*
 * Class that describes quest's current state. 
 */

 class Quest
 {
     private:
        bool deal;
        bool active;
     public:
        Quest()
        {
            this->active = false;
            this->deal = false;
        }
        bool is_deal() { return deal; }
        bool is_active() { return active; }
        void make_active() { active = true; }
        void make_deal() { deal = true; }
 };
 
 #endif // QUEST_H
