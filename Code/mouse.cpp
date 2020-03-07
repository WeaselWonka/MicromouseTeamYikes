
#include "mouse.hpp"
#include "direction.hpp"
#include "testhelper.hpp"

Mouse::Mouse(short x, short y, short dir)
: xPos{x},yPos{y},direction{dir}
{

}

void shiftDirection(short& x, short& y, short direction,short amount)
{
	switch(direction)
	{
		case 0:
			y-=amount;
			return;
		case 1:
			x+=amount;
			return;
		case 2:
			y+=amount;
			return;
		case 3:
			x-=amount;
			return;
	}
}

void Mouse::runForward(int blocks)
{
	shiftDirection(xPos,yPos,direction,blocks);
}

void Mouse::turnClockwise(int amount)
{
	direction = shiftClockwise(direction);
}

void Mouse::turnCounterClockwise(int amount)
{
	direction = shiftCounterClockwise(direction);
}

std::array<bool,3> Mouse::getWalls()
{
	//std::array<bool,3> walls = std::array<bool,3>{false,false,false};
	//return walls;
	return getMouseWalls(xPos,yPos,direction);
}