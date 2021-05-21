#ifndef QUEST_H
#define QUEST_H

/*
 * Class that describes quest's current state. 
 */

 class Quest
 {
     private:
        bool done;
        bool active;
     public:
        Quest()
        {
            this->active = false;
            this->done = false;
        }
        bool is_done() { return done; }
        bool is_active() { return active; }
        void make_active() { active = true; }
        void make() { done = true; }
 };
 
 #endif // QUEST_H
