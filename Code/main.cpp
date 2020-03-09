#include "maze.hpp"
#include "mouse.hpp"

bool WaitForSignal(Maze& maze)
{
    // Wait till some signal/button is pressed
    return !maze.checkPath();
}

int main()
{

	Maze maze{};
	Mouse mouse{0,MazeSize - 1,0};

	while(WaitForSignal(maze))
	{
	    mouse.initialize();
		mouse = Mouse{0,MazeSize - 1,0};
		while(!maze.inGoal(mouse.getXpos(),mouse.getYpos()))
		{
			maze.exploreMaze(mouse);
			maze.moveMouse(mouse);
		}
	}


    return 0;
}

