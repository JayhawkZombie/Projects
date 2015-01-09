/**
 * @file Position.cpp Lab08
 * @author Kurt Slagle
 * @date November 21st, 2014
 * @due Novemer 21st, 2014
 *
 */


//#include "stdafx.h"
#include "Position.h"

Position::Position(int row, int col)
{

}

Position::Position()
{
	m_col = 0;
	m_row = 0;
}

void Position::setCol(int col)
{
	m_col = col;
}

void Position::setRow(int row)
{
	m_row = row;
}

int Position::getRow() const
{
	return m_row;
}

int Position::getCol() const
{
	return m_col;
}
