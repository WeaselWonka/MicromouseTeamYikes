
#ifndef TESTHELPER
#define TESTHELPER

#include "maze.hpp"
#include <string>
#include <array>

class TestMaze: public Maze
{
public:
    // Creates a new empty TestMaze
	TestMaze();
};

// Loads up the TestMaze testerMaze with input from the console
void setupTestMaze();

// Returns the TestMaze testerMaze
TestMaze& getTestMaze();

// Gets the walls a mouse would see if they were in position (<x>,<y>) and facing in direction <direction>
std::array<bool,3> getMouseWalls(short x, short y, short direction);

// Prints out the Maze <maze> with the position that Mouse <mouse> is in marked
void printMaze(Mouse& mouse, Maze& maze);

#endif