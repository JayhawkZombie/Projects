/**
 * @file MazeReader.h Lab08
 * @author Kurt Slagle
 * @date November 21st, 2014
 * @due Novemer 21st, 2014
 *
 */


#ifndef MAZE_RE_H
#define MAZE_RE_H

#include <string>
#include"MazeCreationException.h"

class MazeReader
{
public:
    /**
     * @brief MazeReader
     * @param str
     * @pre MazeWalker successfully created
     * @post creates MazeReader object
     * @post throws exception if can't open file "STR"
     * @return none
     */
	MazeReader(std::string str) throw (MazeCreationException);
    /**
      *@brief MazeReader destructor
      *@pre MazeReader successfully created
      *@post deallocated arrays
      *@return none
      */
	~MazeReader();
    /**
     * @brief getMaze
     * @pre MazeReader successfully created
     * @post returns pointer to the maze
     * @return char** maze
     */
	char **getMaze() const;
    /**
     * @brief setMaze
     * @param maze
     * @pre MazeReader successfully created
     * @post sets the maze pointer
     * @return none
     */
	void setMaze(char** maze);
    /**
     * @brief getCols
     * @param none
     * @pre MazeReader successfully created
     * @post returns number of columns
     * @return number of columns
     */
	int getCols() const;
    /**
     * @brief getRows
     * @param none
     * @pre MazeReader successfully created
     * @post returns number of rows
     * @return number of rows
     */
	int getRows() const;
    /**
     * @brief setCols
     * @param int columns
     * @pre MazeReader successfully created
     * @post sets m_col
     * @return none
     */
	void setCols(int cols);
    /**
     * @brief setRows
     * @param int rows
     * @pre MazeReader successfully created
     * @post sets m_rows
     * @return none
     */
	void setRows(int rows);
    /**
     * @brief getStartRow
     * @param none
     * @pre MazeReader successfully created
     * @post returns m_startRow
     * @return m_startRow
     */
	int getStartRow() const;
    /**
     * @brief getStartCol
     * @param none
     * @pre MazeReader successfully created
     * @post returns m_startCol
     * @return m_startCol
     */
	int getStartCol() const;
    /**
     * @brief setStartRow
     * @param int ROWS
     * @pre MazeReader successfully created
     * @post sets m_startRow
     * @return none
     */
	void setStartRow(int row);
    /**
     * @brief setStartCol
     * @param col
     * @pre MazeReader successfully created
     * @post sets m_col
     * @return none
     */
	void setStartCol(int col);
protected:
    /**
     * @brief readMaze
     * @param file
     * @pre MazeReader successfully created
     * @post fills the maze array with the characters
     * @return none
     */
	void readMaze(std::string file) throw (MazeCreationException);
private:
	int m_cols;
	int m_rows;
	int m_startCol;
	int m_startRow;
	char **maze;

};

#endif
