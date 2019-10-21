
#ifndef PATHFINDER
#define PATHFINDER

#include "mouse.hpp"
#include "followpath.hpp"

class PathFinder : public Mouse
{
public:

    // Creates a new pathfinder for Mouse <mouse>
	PathFinder(Mouse& mouse);

    // Pushes a forward movement onto the FollowPath
	virtual void moveForward(int blocks = 1) override;

	// Pushes a clockwise turn onto the FollowPath
	virtual void turnClockwise(int amount = 1) override;

	// Pushes a counterclockwise turn onto the FollowPath
	virtual void turnCounterClockwise(int amount = 1) override;	

	// Moves the inserted mouse along the found "best" path
	void runPath();

private:
	FollowPath bestPath;

};

#endif