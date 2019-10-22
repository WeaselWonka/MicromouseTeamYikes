
#ifndef FOLLOWPATH
#define FOLLOWPATH

#include <deque>
#include "mouse.hpp"

struct command
{
    char movement;
    int amount;
};

class FollowPath
{
    public:
        // Creates a new FollowPath from the mouse reference <mouse>
        FollowPath(Mouse& mouse);

        // Adds a movement onto pathlist deque, <move> can be 'f' for forward, 'l' for turn left, and 'r' for turn right
        void pushMovement(char move);

        // Runs the current best path for the passed in mouse
        void runList();

    private:
        std::deque<command> pathlist;
        Mouse* mouse;

};

#endif