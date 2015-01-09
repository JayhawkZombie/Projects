//#include "stdafx.h"
#include "MazeCreationException.h"
#include <string>
#include <stdexcept>



MazeCreationException::MazeCreationException(const char* message) : std::runtime_error(message)
{
	//std::runtime_error(*message);
}
