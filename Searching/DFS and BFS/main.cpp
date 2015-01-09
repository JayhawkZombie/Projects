/**
 * @file main.cpp Lab08
 * @author Kurt Slagle
 * @date November 21st, 2014
 * @due Novemer 21st, 2014
 *
 */


// Maze.cpp : Defines the entry point for the console application.
//

#include "MazeReader.h"
#include "MazeWalker.h"
#include <iostream>
#include <string>


int main(int argc, char* argv[])
{

	if (argc != 3)
	{
		std::cout << "Oops!  Invalid number of arguments.  You must supply 2 arguments (the file name, and -dfs or -bfs)" << std::endl;
		return -1;
	}

	std::string fileName = argv[1];
	std::string DFS = argv[2];
	if (DFS != "-dfs" && DFS != "-bfs")
	{
		std::cout << "Could not parse line. " << DFS << " was not recognized" << std::endl;
		return -2;
	}

	bool dfs(DFS == "-dfs");

	try
	{
		MazeReader reader(fileName);
		char** maze = reader.getMaze();
		for (int i = 0; i < reader.getRows(); i++)
		{
			for (int j = 0; j < reader.getCols(); j++)
			{
				std::cout << maze[i][j];
			}
			std::cout << std::endl;
		}
		MazeWalker walker(maze, reader.getStartRow(), reader.getStartCol(), reader.getRows(), reader.getCols(), dfs);
		walker.walkMaze();
	}
	catch (MazeCreationException &error)
	{
		std::cout << error.what() << std::endl;
	}
	return 0;
}

