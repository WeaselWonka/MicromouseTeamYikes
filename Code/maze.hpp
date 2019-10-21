
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

	// Returns an array representing the walls around point (<x>,<y>) in the format [Up,Right,Down,Left]
	std::array<bool*,4> getBlockWalls(short x, short y);

	// Prints a representation of the maze that has been discovered, marks the block on the maze at point (<x>,<y>)
	void printMaze(short x = -1, short y = -1);

	// General function that determines the walls around the mouse <mouse> and then fixes the distances from the center
	// of the various blocks in the maze
	void exploreMaze(Mouse& mouse);

	// Moves the mouse in the best direction based on the state of the maze
	void moveMouse(Mouse& mouse);

	// Fixes the distances from the center of the maze assuming new walls were placed at point (<x>,<y>)
	void fixMaze(short x, short y);

	// Sets the walls of the block at point (<x>,<y>) to the values of <up>, <right>, <down>, and <left>
	void setWalls(short x, short y, bool up, bool right, bool down, bool left);

	// Determines of point (<x>,<y>) is in the goal
	bool inGoal(short x, short y);

	// Returns the board containing the distances of blocks from the center
	std::array<std::array<int,MazeSize>,MazeSize>& getBoard()
	{
		return board;
	}

	// Returns an array representing the values of vertical walls in the maze
	std::array<std::array<bool,MazeSize>,MazeSize+1>& getVertical()
	{
		return vertical;
	}

    // Returns an array representing the values of horizontal walls in the maze
	std::array<std::array<bool,MazeSize+1>,MazeSize>& getHorizontal()
	{
		return horizontal;
	}

	// Returns if the current path is the "final path" or the most optimal path, should only be called once between explorations
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