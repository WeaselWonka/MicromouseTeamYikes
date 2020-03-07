
#include <Arduino.h>
#include "mouse.hpp"
#include "direction.hpp"

void Motor::runMotor(int enVal, int forVal, int revVal)
{
    analogWrite(this->motorEN, enVal);
    digitalWrite(this->motorForward, forVal);
    digitalWrite(this->motorReverse, revVal);
}

bool IRSensor::foundWall() {
    int receiverValue = analogRead(receiver);
    return receiverValue < upperWallRange && receiverValue > lowerWallRange;
}

Mouse::Mouse(short x, short y, short dir)
: xPos{x}, yPos{y}, direction{dir}, leftMotor{5, 3, 2, 7, 6, 0}, rightMotor{4, 1, 0, 8, 9, 0},
  lbSensor{22,23, -1, -1}, lfSensor{20,21, -1, -1}, rfSensor{17, 16, -1, -1}, rbSensor{15, 14, -1, -1}
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

    pinMode(lfSensor.emitter, OUTPUT);
    pinMode(lfSensor.receiver, INPUT);

    pinMode(lbSensor.emitter, OUTPUT);
    pinMode(lbSensor.receiver, INPUT);

    pinMode(rbSensor.emitter, OUTPUT);
    pinMode(rbSensor.receiver, INPUT);

    pinMode(rfSensor.emitter, OUTPUT);
    pinMode(rfSensor.receiver, INPUT);
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
	rightMotor.runMotor(forwardSpeed, 1, 0);
	leftMotor.runMotor(forwardSpeed, 1, 0);
}

void Mouse::turnClockwise(int amount)
{
	direction = shiftClockwise(direction);
    rightMotor.runMotor(forwardSpeed, 0, 1);
    leftMotor.runMotor(forwardSpeed, 1, 0);
    while(leftMotor.motorEN < degToEnc * amount)
    {

    }
    leftMotor.motorEN = 0;
    rightMotor.motorEN = 0;
}

void Mouse::turnCounterClockwise(int amount)
{
	direction = shiftCounterClockwise(direction);
    rightMotor.runMotor(forwardSpeed, 1, 0);
    leftMotor.runMotor(forwardSpeed, 0, 1);
    while(leftMotor.motorEN < degToEnc * amount)
    {

    }
    leftMotor.motorEN = 0;
    rightMotor.motorEN = 0;
}

std::array<bool,3> Mouse::getWalls()
{
    bool leftWall,rightWall,frontWall;
    digitalWrite(lfSensor.emitter,1);
    digitalWrite(rfSensor.emitter,1);
    delay(10)
    leftWall = lfSensor.foundWall();
    rightWall = rfSensor.foundWall();
    digitalWrite(rfSensor.emitter,0);
    digitalWrite(lfSensor.emitter,0);
    delay(100)

    digitalWrite(lbSensor.emitter,1);
    digitalWrite(rbSensor.emitter,1);
    delay(10)
    frontWall = lbSensor.foundWall() && rbSensor.foundWall();
    digitalWrite(lbSensor.emitter,0);
    digitalWrite(rbSensor.emitter,0);

	std::array<bool,3> walls = std::array<bool,3>{leftWall,frontWall,rightWall};

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