
#ifndef MOUSE
#define MOUSE

#include <array>
#include "PID.hpp"

void shiftDirection(short& x, short& y, short direction, short amount = 1);

#define encoderToBlock 1000
#define encoderToSDelta (encoderToBlock * .6)

#define forwardSpeed 100
#define turnSpeed 70

#define degToEnc 1 // < idk

typedef struct{
    int motorEN, motorForward, motorReverse;
    int encoderPinA, encoderPinB, encoderValue;
    void runMotor(int enVal, int forVal, int revVal);
} Motor;

typedef struct{
    int emitter, receiver;
    int lowerWallRange, upperWallRange;
    bool foundWall();
} IRSensor;

class Mouse
{
public:

    // Creates a new mouse at point (<x>,<y>) with the direction <dir>
	Mouse(short x, short y, short dir);

    // Moves the mouse to the middle of the block from the starting position
    void initialize();

    // Stops mouse when it moves a block
    void stopAtNextBlock();

    // Waits until SDelta
    void waitForSDelta();

    void moveForward(int blocks = 1)
    {
        shiftDirection(xPos,yPos,direction,blocks);
    }

    // Moves the mouse forward <blocks> blocks
	virtual void runForward();

	// Turns the mouse clockwise (<amount> * 90) degrees
	virtual void turnClockwise(int amount = 1);

    // Turns the mouse counterclockwise (<amount> * 90) degrees
	virtual void turnCounterClockwise(int amount = 1);	

	// Returns array representing the walls surrounding the mouse in the form [Left,Forward,Right]
	std::array<bool,3> getWalls();

	// Returns the x position of the mouse
	short getXpos()
	{
		return xPos;
	}

	// Returns the y position of the mouse
	short getYpos()
	{
		return yPos;
	}

	// Sets the current position of the mouse to point (<x>,<y>)
	void setPosition(short x,short y)
	{
		xPos = x;
		yPos = y;
	}

	// Returns the direction the mouse is facing
	short getDirection()
	{
		return direction;
	}

	// Sets the direction of the mouse to direction <direction>
	void setDirection(short direction)
	{
		this->direction = direction;
	}

protected:
    short xPos;
    short yPos;
    short direction;
    Motor leftMotor;
    Motor rightMotor;
    IRSensor lbSensor;
    IRSensor lfSensor;
    IRSensor rfSensor;
    IRSensor rbSensor;
	PID leftPID = PID();
	PID rightPID = PID();
};

#endif