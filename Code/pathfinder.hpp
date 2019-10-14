
#ifndef PATHFINDER
#define PATHFINDER

#include "mouse.hpp"
#include "followpath.hpp"

class PathFinder : public Mouse
{
public:
	PathFinder(Mouse& mouse);

	virtual void moveForward(int blocks = 1) override;

	virtual void turnClockwise(int amount = 1) override;

	virtual void turnCounterClockwise(int amount = 1) override;	

	void runPath();

private:
	FollowPath bestPath;

};

#endif