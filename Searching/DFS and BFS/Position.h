/**
 * @file Position Lab08
 * @author Kurt Slagle
 * @date November 21st, 2014
 * @due Novemer 21st, 2014
 *
 */


#ifndef POS_H
#define POS_H

class Position
{
public:

    /**
    * @brief Position
    * @pre constructor
    * @post constructs a Position object
    * @param int Rows, int Columns
    * @return returns nothing
    */
	Position(int row, int col);
    /**
    * @brief Position
    * @pre default constructor
    * @post constructs a Position object
    * @param none
    * @return returns nothing
    */
	Position();
    /**
    * @brief getRow
    * @pre position object correctly created
    * @post returns m_row
    * @param none
    * @return returns m_row
    */
	int getRow() const;
    /**
    * @brief getRow
    * @pre position object correctly created
    * @post returns m_col
    * @param none
    * @return returns m_col
    */
	int getCol() const;
    /**
    * @brief getRow
    * @pre position object correctly created
    * @post sets m_row
    * @param int Rows
    * @return returns nothing
    */
	void setRow(int row);
    /**
    * @brief setCol
    * @pre position object correctly created
    * @post sets m_col
    * @param int Cols
    * @return returns none
    */
	void setCol(int col);
private:
	int m_row;
	int m_col;
};

#endif
