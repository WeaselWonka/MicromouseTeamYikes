
#ifndef MOUSE
#define MOUSE

#include <array>

void shiftDirection(short& x, short& y, short direction);

class Mouse
{
public:
	Mouse(short x, short y, short dir);

	virtual void moveForward(int blocks = 1);

	virtual void turnClockwise(int amount = 1);

	virtual void turnCounterClockwise(int amount = 1);	

	std::array<bool,3> getWalls();
	
	short getXpos()
	{
		return xPos;
	}

	short getYpos()
	{
		return yPos;
	}

	void setPosition(short x,short y)
	{
		xPos = x;
		yPos = y;
	}

	short getDirection()
	{
		return direction;
	}

	void setDirection(short direction)
	{
		this->direction = direction;
	}


protected:
    short xPos;
    short yPos;
    short direction;
};

#endif