/**
 * @file MazeCreationException.h Lab08
 * @author Kurt Slagle
 * @date November 21st, 2014
 * @due Novemer 21st, 2014
 *
 */

#ifndef MAZE_CR_EX_H
#define MAZE_CR_EX_H

#include <stdexcept>
#include <string>

class MazeCreationException : public std::runtime_error
{
public:
    /**
     * @brief MazeCreationException constructor
     * @param message
     * @pre none
     * @post constructs exception
     * @return none
     */
	MazeCreationException(const char* message);
};

#endif
