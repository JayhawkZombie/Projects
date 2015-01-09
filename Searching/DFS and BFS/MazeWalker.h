/**
 * @file MazeWalker.h Lab08
 * @author Kurt Slagle
 * @date November 21st, 2014
 * @due Novemer 21st, 2014
 *
 */


#ifndef MAZE_WALK_H
#define MAZE_WALK_H

#include "Position.h"
#include <stack>
#include <queue>

class MazeWalker
{
public:
    /**
     * @brief MazeWalker
     * @param mazePtr
     * @param startRow
     * @param startCol
     * @param rows
     * @param cols
     * @param dfs
     * @pre constructs MazeWalker object
     * @post constructs MazeWalker object
     * @return none
     */
	MazeWalker(char **mazePtr, int startRow, int startCol, int rows, int cols, bool dfs);
    /**
     * @brief walkMaze
     * @pre MazeWalker successfully created
     * @post traverses the maze
     * @return none
     */
	void walkMaze();
protected:
    /**
     * @brief storeValidMoves
     * @pre MazeWalker successfully created
     * @post stores valid moves in Queue or Stack
     * @param none
     * @return none
     */
	void storeValidMoves();
    /**
    * @brief move
    * @pre MazeWalker object correctly created
    * @post moves Position
    * @param Position &p
    * @return none
    */
	void move(Position &p);
    /**
     * @brief isGoalReached
     * @pre MazeWalker correctly created
     * @post determines if an exit was found
     * @param none
     * @return bool true if exit found false otherwise
     */
	bool isGoalReached() const;
	bool m_isDFS;
	char **maze;
	bool **visited;
	int m_rows;
	int m_cols;
	Position m_curPos;
	Position m_startPos;
	std::stack<Position> m_moveStack;
	std::queue<Position> m_moveQueue;
};

#endif
