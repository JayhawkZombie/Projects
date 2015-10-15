// BigInt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "BigInt.h"

#include <iostream>
#include <ostream>

std::string intToString(int i)
{
	return(std::to_string(i));
}


int _tmain(int argc, _TCHAR* argv[])
{

	BIGINT::BigInt myInt("12345");

	std::cout << myInt << std::endl;

	for (int i = 0; i < myInt.length(); i++)
	{
		std::cout << "INDEX: " << i << "| " << myInt[i] << std::endl;
	}

	std::cout << "==============================" << std::endl;

	std::cout << intToString(12345) << std::endl;
	std::cout << "==============================" << std::endl;
	
	std::cout << intToString(-12345) << std::endl;

	BIGINT::BigInt myInt2(-12345);

	std::cout << myInt2 << std::endl;

	for (int i = 0; i < myInt2.length(); i++)
	{
		std::cout << "INDEX: " << i << "| " << myInt2[i] << std::endl;
	}

	std::cout << "BEGINNING COPYING" << std::endl;

	BIGINT::BigInt copied(myInt2);

	std::cout << "==============================" << std::endl;

	std::cout << copied << std::endl;

	return 0;
}

