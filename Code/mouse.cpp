
#include <Arduino.h>
#include "mouse.hpp"
#include "direction.hpp"

Mouse::Mouse(short x, short y, short dir)
: xPos{x}, yPos{y}, direction{dir}, leftMotor{5, 3, 2, 7, 6, 0}, rightMotor{4, 1, 0, 8, 9, 0}
{
    pinMode(rightMotor.encoderPinA, INPUT);
    pinMode(rightMotor.encoderPinB, INPUT);
    attachInterrupt(rightMotor.encoderPinA, [&](){++rightMotor.encoderValue;}, CHANGE);
    attachInterrupt(rightMotor.encoderPinB, [&](){++rightMotor.encoderValue;}, CHANGE);

    pinMode(leftMotor.encoderPinA, INPUT);
    pinMode(leftMotor.encoderPinB, INPUT);
    attachInterrupt(leftMotor.encoderPinA, [&](){++leftMotor.encoderValue;}, CHANGE);
    attachInterrupt(leftMotor.encoderPinB, [&](){++leftMotor.encoderValue;}, CHANGE);

    pinMode(rightMotor.motorEN, OUTPUT);
    pinMode(rightMotor.motorForward, OUTPUT);
    pinMode(rightMotor.motorReverse, OUTPUT);

    pinMode(leftMotor.motorEN, OUTPUT);
    pinMode(leftMotor.motorForward, OUTPUT);
    pinMode(leftMotor.motorReverse, OUTPUT);
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

// TODO

void Mouse::initialize()
{

}

void Mouse::runForward()
{
	shiftDirection(xPos,yPos,direction,1);
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
	std::array<bool,3> walls = std::array<bool,3>{false,false,false};
	// get walls from emitters
	return walls;
}

void Mouse::stopAtNextBlock()
{
    while(leftMotor.encoderValue < encoderToBlock)
    {
    }
    leftMotor.encoderValue -= encoderToBlock;
    rightMotor.encoderValue -= encoderToBlock;
    // Stop motors
}

void Mouse::waitForSDelta()
{
    while(leftMotor.encoderValue < encoderToSDelta)
    {
    }
}