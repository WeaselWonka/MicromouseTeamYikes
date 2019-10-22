#import "followpath.hpp"
#import "mouse.hpp"
#include <deque>

FollowPath::FollowPath(Mouse& mouse)
: mouse{&mouse}
{

}

void FollowPath::pushMovement(char move)
{
    if(!pathlist.empty() && pathlist.back().movement == move)
    {
        ++pathlist.back().amount;
    }
    else
    {
        pathlist.push_back(command{move,1});   
    }
}

void FollowPath::runList()
{
    command currMove;
    while (!pathlist.empty())
    {
        currMove = pathlist.front();
        pathlist.pop_front();
        switch(currMove.movement)
        {
            case 'l':
                mouse->turnCounterClockwise(currMove.amount);
                break;
            case 'r':
                mouse->turnClockwise(currMove.amount);
                break;
            case 'f':
                mouse->moveForward(currMove.amount);
                break;
        }
    }
}