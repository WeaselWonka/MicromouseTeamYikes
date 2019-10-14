
#include "pathfinder.hpp"
#include "maze.hpp"
#include "mouse.hpp"

PathFinder::PathFinder(Mouse& mouse)
: Mouse(0,MazeSize - 1,0), bestPath(mouse)
{

}

virtual void PathFinder::moveForward(int blocks = 1) override
{
	shiftDirection(xPos,yPos,direction);
	bestPath.pushMovement('f');
}

virtual void PathFinder::turnClockwise(int amount = 1) override
{
	direction = shiftClockwise(direction);
	bestPath.pushMovement('r');
}

virtual void PathFinder::turnCounterClockwise(int amount = 1) override
{
	direction = shiftCounterClockwise(direction);
	bestPath.pushMovement('l');
}	

void PathFinder::runPath()
{
	bestPath.runList();
}