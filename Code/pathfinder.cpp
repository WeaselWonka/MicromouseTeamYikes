
#include "pathfinder.hpp"
#include "maze.hpp"
#include "mouse.hpp"
#include "direction.hpp"

PathFinder::PathFinder(Mouse& mouse)
: Mouse(0,MazeSize - 1,0), bestPath(mouse)
{

}

void PathFinder::moveForward(int blocks)
{
	shiftDirection(xPos,yPos,direction);
	bestPath.pushMovement('f');
}

void PathFinder::turnClockwise(int amount)
{
	direction = shiftClockwise(direction);
	bestPath.pushMovement('r');
}

void PathFinder::turnCounterClockwise(int amount)
{
	direction = shiftCounterClockwise(direction);
	bestPath.pushMovement('l');
}	

void PathFinder::runPath()
{
	bestPath.runList();
}

void RunPathFinder(PathFinder& pathfinder, Maze& maze)
{
    while (!maze.inGoal(pathfinder.getXpos(), pathfinder.getYpos()))
    {
        maze.moveMouse(pathfinder);
    }
}