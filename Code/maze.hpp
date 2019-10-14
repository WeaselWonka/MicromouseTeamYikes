
#ifndef MAZE
#define MAZE

#include <array>
#include "mouse.hpp"

#define MazeSize 16

struct Point
{
	short x,y;
};

struct DirPoint
{
	Point position;
	short direction;
};     

class Maze
{
public:
	Maze();
	std::array<bool*,4> getBlockWalls(short x, short y);
	void printMaze(short x = -1, short y = -1);   
	void exploreMaze(Mouse& mouse); 
	void moveMouse(Mouse& mouse); 
	void fixMaze(short x, short y);
	void setWalls(short x, short y, bool up, bool right, bool down, bool left);

	bool inGoal(short x, short y);

	std::array<std::array<int,MazeSize>,MazeSize>& getBoard()
	{
		return board;
	}

	std::array<std::array<bool,MazeSize>,MazeSize+1>& getVertical()
	{
		return vertical;
	}

	std::array<std::array<bool,MazeSize+1>,MazeSize>& getHorizontal()
	{
		return horizontal;
	}

	bool checkPath();

private:
	// Store the maze
	std::array<std::array<int,MazeSize>,MazeSize> board; // Keeps track of blocks distances from the center
	std::array<std::array<bool,MazeSize>,MazeSize+1> vertical; // Keeps track of the vertical walls
	std::array<std::array<bool,MazeSize+1>,MazeSize> horizontal; // Keeps track of the horizontal walls

	// Optimizations
	std::array<std::array<bool,MazeSize>,MazeSize> explored; // Keeps track of previously explored blocks 

	bool finalPath;
};

#endif