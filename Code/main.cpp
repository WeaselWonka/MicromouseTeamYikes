#include "maze.hpp"
#include "mouse.hpp"
#include "testhelper.hpp"
#include <iostream>

int main()
{
	setupTestMaze();

	Maze maze{};
	Mouse mouse{0,MazeSize - 1,0};


	while(true)
	{
		mouse = Mouse{0,MazeSize - 1,0};
		while(!maze.inGoal(mouse.getXpos(),mouse.getYpos()))
		{
			maze.exploreMaze(mouse);
			maze.moveMouse(mouse);
			std::getchar();
			printMaze(mouse,maze);
		}
	}

    return 0;
}

