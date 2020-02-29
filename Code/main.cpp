#include "maze.hpp"
#include "mouse.hpp"
#include "testhelper.hpp"
#include <iostream>

bool WaitForSignal(Maze& maze)
{
    // Wait till some signal/button is pressed
    return !maze.checkPath();
}

int main()
{
	setupTestMaze(); // not needed in final

	Maze maze{};
	Mouse mouse{0,MazeSize - 1,0};


	while(WaitForSignal(maze))
	{
		mouse = Mouse{0,MazeSize - 1,0};
		while(!maze.inGoal(mouse.getXpos(),mouse.getYpos()))
		{
			maze.exploreMaze(mouse);
			maze.moveMouse(mouse);
            std::cin.get();
			printMaze(mouse,maze); // Debug output
		}
	}


    return 0;
}

