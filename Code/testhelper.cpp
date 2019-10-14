
#include "testhelper.hpp" 
#include "maze.hpp"
#include "direction.hpp"

#include <iostream>
#include <fstream>
#include <array>
#include <limits>

TestMaze* testerMaze;

void setupTestMaze()
{
	testerMaze = new TestMaze{};
}

TestMaze& getTestMaze()
{
	return *testerMaze;
}

template <class arrayType, int height, int width>
void fillArrayFromFile(std::array<std::array<arrayType,width>,height>& array)
{
	for(int row = 0; row < height; ++row)
	{
		for(int col = 0; col < width; ++col)
		{
			std::cin >> array[row][col];

		}
	}
}

TestMaze::TestMaze()
{

	fillArrayFromFile<bool,MazeSize+1,MazeSize>(this->getVertical());

	fillArrayFromFile<bool,MazeSize,MazeSize+1>(this->getHorizontal());

}

void printMaze(Mouse& mouse, Maze& maze)
{
	maze.printMaze(mouse.getXpos(),mouse.getYpos());
}

std::array<bool,3> getMouseWalls(short x, short y, short direction)
{
	std::array<bool*,4> block = testerMaze->getBlockWalls(x,y);
	std::array<bool,3> walls{{*(block[shiftCounterClockwise(direction)]),*(block[direction]),*(block[shiftClockwise(direction)])}};
	return walls;
}