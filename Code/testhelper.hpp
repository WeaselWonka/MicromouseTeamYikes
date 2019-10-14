
#ifndef TESTHELPER
#define TESTHELPER

#include "maze.hpp"
#include <string>
#include <array>

class TestMaze: public Maze
{
public:
	TestMaze();
};

void setupTestMaze();

TestMaze& getTestMaze();

std::array<bool,3> getMouseWalls(short x, short y, short direction);

void printMaze(Mouse& mouse, Maze& maze);

#endif