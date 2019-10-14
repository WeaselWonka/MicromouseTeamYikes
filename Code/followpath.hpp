
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
        FollowPath(Mouse& mouse);
        void pushMovement(char move);
        void runList();

    private:
        std::deque<char> pathlist;
        Mouse mouse;

};

#endif