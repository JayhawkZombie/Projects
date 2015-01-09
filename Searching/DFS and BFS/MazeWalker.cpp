/**
 * @file MazeWalker.cpp Lab08
 * @author Kurt Slagle
 * @date November 21st, 2014
 * @due Novemer 21st, 2014
 *
 */


//#include "stdafx.h"
#include "MazeWalker.h"
#include <stack>
#include <queue>
#include "Position.h"
#include <iostream>

MazeWalker::MazeWalker(char **mazePtr, int startRow, int startCol, int rows, int cols, bool dfs)
{
	m_startPos.setCol(startCol);
	m_startPos.setRow(startRow);

	m_rows = rows;
	m_cols = cols;
	
	if (dfs)
	{
		m_isDFS = true;
		m_moveStack.push(m_startPos);

		int i = m_startPos.getRow();
		int j = m_startPos.getCol();

		Position pos;

		visited = new bool*[rows];
		for (int i = 0; i < cols; i++)
		{
			visited[i] = new bool[cols];
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				visited[i][j] = false;
				std::cout << visited[i][j];
			}
			std::cout << std::endl;
		}
	}
	else
	{
		m_isDFS = false;
		m_moveQueue.push(m_startPos);

		int i = m_startPos.getRow();
		int j = m_startPos.getCol();

		Position pos;

		visited = new bool*[rows];
		for (int i = 0; i < cols; i++)
		{
			visited[i] = new bool[cols];
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				visited[i][j] = false;
				std::cout << visited[i][j];
			}
			std::cout << std::endl;
		}
	}
	
	maze = mazePtr;
}

void MazeWalker::move(Position &pos)
{
	m_curPos = pos;
	std::cerr << "Current position is: " << pos.getRow() << ", " << pos.getCol() << std::endl;
	int i = m_curPos.getRow();
	int j = m_curPos.getCol();
	visited[i][j] = 1;
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_cols; j++)
		{
			std::cout << visited[i][j];
		}
		std::cout << std::endl;
	}
}

void MazeWalker::storeValidMoves()
{
	int i = m_curPos.getRow();
	int j = m_curPos.getCol();

	//std::cerr << "i is " << i << " j is " << j << std::endl;
	//std::cerr << "numRows is " << m_rows << " numCols is " << m_cols << std::endl;

	Position pos = m_curPos;

	if (m_isDFS)
	{
		if (i - 1 >= 0)
		{
			if (maze[i - 1][j] == 'P' || maze[i - 1][j] == 'E')
			{
				pos.setCol(j);
				pos.setRow(i - 1);
				if (visited[i - 1][j] == 0)
				{
					m_moveStack.push(pos);
					std::cerr << "Pushed (" << pos.getRow() << ", " << pos.getCol() << ")" << std::endl;
				}
			}
		}

		if (i + 1 < m_rows)
		{
			if (maze[i + 1][j] == 'P' || maze[i + 1][j] == 'E')
			{
				pos.setCol(j);
				pos.setRow(i + 1);
				if (visited[i + 1][j] == 0)
				{
					m_moveStack.push(pos);
					std::cerr << "Pushed (" << pos.getRow() << ", " << pos.getCol() << ")" << std::endl;
				}
			}
		}

		if (j - 1 >= 0)
		{
			if (maze[i][j - 1] == 'P' || maze[i][j - 1] == 'E')
			{
				pos.setCol(j - 1);
				pos.setRow(i);
				if (visited[i][j - 1] == 0)
				{
					m_moveStack.push(pos);
					std::cerr << "Pushed (" << pos.getRow() << ", " << pos.getCol() << ")" << std::endl;
				}
			}
		}


		if (j + 1 < m_cols)
		{
			if (maze[i][j + 1] == 'P' || maze[i][j + 1] == 'E')
			{
				pos.setCol(j + 1);
				pos.setRow(i);
				if (visited[i][j + 1] == 0)
				{
					m_moveStack.push(pos);
					std::cerr << "Pushed (" << pos.getRow() << ", " << pos.getCol() << ")" << std::endl;
				}
			}
		}
	}
	else
	{
		if (i - 1 >= 0)
		{
			if (maze[i - 1][j] == 'P' || maze[i - 1][j] == 'E')
			{
				pos.setCol(j);
				pos.setRow(i - 1);
				if (visited[i - 1][j] == 0)
				{
					m_moveQueue.push(pos);
					std::cerr << "Pushed (" << pos.getRow() << ", " << pos.getCol() << ")" << std::endl;
				}
			}
		}

		if (i + 1 < m_rows)
		{
			if (maze[i + 1][j] == 'P' || maze[i + 1][j] == 'E')
			{
				pos.setCol(j);
				pos.setRow(i + 1);
				if (visited[i + 1][j] == 0)
				{
					m_moveQueue.push(pos);
					std::cerr << "Pushed (" << pos.getRow() << ", " << pos.getCol() << ")" << std::endl;
				}
			}
		}

		if (j - 1 >= 0)
		{
			if (maze[i][j - 1] == 'P' || maze[i][j - 1] == 'E')
			{
				pos.setCol(j - 1);
				pos.setRow(i);
				if (visited[i][j - 1] == 0)
				{
					m_moveQueue.push(pos);
					std::cerr << "Pushed (" << pos.getRow() << ", " << pos.getCol() << ")" << std::endl;
				}
			}
		}


		if (j + 1 < m_cols)
		{
			if (maze[i][j + 1] == 'P' || maze[i][j + 1] == 'E')
			{
				pos.setCol(j + 1);
				pos.setRow(i);
				if (visited[i][j + 1] == 0)
				{
					m_moveQueue.push(pos);
					std::cerr << "Pushed (" << pos.getRow() << ", " << pos.getCol() << ")" << std::endl;
				}
			}
		}
	}
	
}

void MazeWalker::walkMaze()
{
	Position pos = m_curPos;
	char n('n');

	if (m_isDFS)
	{
		//storeValidMoves();
		while (m_moveStack.empty() == false)
		{
			storeValidMoves();
			move(m_moveStack.top());
			if (isGoalReached())
			{
				std::cerr << "FOUND EXIT" << std::endl;
				break;
			}
			m_moveStack.pop();
			if (m_moveStack.empty() == true && !isGoalReached())
			{
				std::cout << "No way out!" << std::endl;
				break;
			}
		}
	}
	else
	{
		//storeValidMoves();
		while (m_moveQueue.empty() == false)
		{
			storeValidMoves();
			move(m_moveQueue.front());
			if (isGoalReached())
			{
				std::cerr << "FOUND EXIT" << std::endl;
				break;
			}
			if (m_moveQueue.empty() && !isGoalReached())
			{
				std::cout << "No way out!" << std::endl;
				break;
			}
			m_moveQueue.pop();
		}
	}
	
	for (int i = 0; i < m_rows; i++)
	{
		delete[] visited[i];
	}
	delete[] visited;
}

bool MazeWalker::isGoalReached() const
{
	return (maze[m_curPos.getRow()][m_curPos.getCol()] == 'E');
}
