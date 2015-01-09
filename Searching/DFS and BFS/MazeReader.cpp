/**
 * @file MazeReader.cpp Lab08
 * @author Kurt Slagle
 * @date November 21st, 2014
 * @due Novemer 21st, 2014
 *
 */


//#include "stdafx.h"
#include "MazeReader.h"
#include <fstream>
#include <iostream>


MazeReader::MazeReader(std::string file) throw (MazeCreationException)
{
	std::ifstream _IN;
	std::string failed = "Failed to find " + file;
    _IN.open(file.c_str());
	if (_IN.fail())
		throw MazeCreationException(failed.c_str());

	/** Else the file loaded successfully */

	int numRows, numCols, startRow, startCol;
	_IN >> numRows >> numCols >> startRow >> startCol;

	/** Check for valid positions */
	if (startRow > numRows || startRow < 0)
		throw MazeCreationException("Invalid starting row");
	else if (startCol > numCols || startCol < 0)
		throw MazeCreationException("Invalid starting column");

	/** The file passed tests - now we can begin to load the maze into an array */

	setCols(numCols);
	setRows(numRows);
	setStartCol(startCol);
	setStartRow(startRow);

	//char m;

	char **_MAZE = new char*[numRows];
	for (int i = 0; i < numCols; i++)
	{
		_MAZE[i] = new char[numCols];
	}

	
	//the array has been allocated
	//full up the array

	_IN.close();
	setMaze(_MAZE);
	readMaze(file);

}

void MazeReader::readMaze(std::string file) throw (MazeCreationException)
{
	std::ifstream _IN;
    _IN.open(file.c_str());
	if (_IN.fail())
	{
		std::cerr << "Failed to open file" << std::endl;
	}

	_IN >> m_rows >> m_cols >> m_startRow >> m_startCol;

	int numRows = m_rows;
	int numCols = m_cols;
	char m;

	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
		{
			_IN >> m;
			maze[i][j] = m;
		}
	}

	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
		{
			std::cout << maze[i][j];
		}
		std::cout << std::endl;
	}

	setMaze(maze);

	_IN.close();
}

int MazeReader::getStartRow() const
{
	return m_startRow;
}

int MazeReader::getStartCol() const
{
	return m_startCol;
}

int MazeReader::getRows() const
{
	return m_rows;
}

char** MazeReader::getMaze() const
{
	return maze;
}

int MazeReader::getCols() const
{
	return m_cols;
}

void MazeReader::setMaze(char **mazePtr)
{
	maze = mazePtr;
}

void MazeReader::setStartRow(int startRow)
{
	m_startRow = startRow;
}

void MazeReader::setStartCol(int startCol)
{
	m_startCol = startCol;
}

void MazeReader::setRows(int rows)
{
	m_rows = rows;
}

void MazeReader::setCols(int cols)
{
	m_cols = cols;
}

MazeReader::~MazeReader()
{

	for (int i = 0; i < m_rows; i++)
	{
		delete[] maze[i];
	}

	delete[] maze;
}
