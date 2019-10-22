#include "maze.hpp"
#include "mouse.hpp"
#include "testhelper.hpp"
#include "pathfinder.hpp"
#include <iostream>

int main()
{
	setupTestMaze();

	Maze maze{};
	Mouse mouse{0,MazeSize - 1,0};


	while(!maze.checkPath())
	{
		mouse = Mouse{0,MazeSize - 1,0};
		while(!maze.inGoal(mouse.getXpos(),mouse.getYpos()))
		{
			maze.exploreMaze(mouse);
			maze.moveMouse(mouse);
			//std::getchar();
			//printMaze(mouse,maze);
		}
	}

    mouse = Mouse{0,MazeSize - 1,0};
	PathFinder pathFinder{mouse};

	RunPathFinder(pathFinder,maze);

	pathFinder.runPath();

    std::cout << mouse.getXpos() << " " << mouse.getYpos();



    return 0;
}

