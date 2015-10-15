#include "stdafx.h"
#include "BigInt.h"


#include <iostream>
#include <sstream>
#include <ostream>

#define USE_DEBUG_CODE true


BIGINT::BigInt::BigInt()
{
	digits = nullptr;
	sign = '+';
	numDigits = 0;
}

/*
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
|| For this constructor - we take the following steps                        ||
|| 1) Convert the int to a string and determine the sign of the number       ||
|| 2) Assign the length of the new BigInt accordingly - ignoring any '-' sign||
|| 3) Allocate storage for the new BigInt                                    ||
|| 3) Increment through it and assign the values of the BigInt accordingly   ||
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
*/

BIGINT::BigInt::BigInt(int i)
{
	if (USE_DEBUG_CODE)
	{

	}


	//Convert the integer to a string - better to just use a std function to do this
	std::string string = std::to_string(i);

	//Determine the sign of the number
	sign = (i >= 0 ? '+' : '-');

	//Determine how long we need the char array to be (it cannot unclude the '-' sign for negative numbers)
	numDigits = (i >= 0 ? string.length() : string.length() - 1);


	if (USE_DEBUG_CODE)
		std::cout << (i >= 0 ? "POSITIVE" : "NEGATIVE") << std::endl;

	//Allocate the storage
	digits = new char[i >= 0 ? string.length() : string.length() - 1];

	//Assign the values to the array
	int k = 0;
	for (int ind = (i >= 0 ? 0 : 1); ind < string.length(); ind++)
	{
		digits[k++] = string[ind];
	}


}

/*
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
|| For this constructor - we take the following steps                        ||
|| 1) Determine the sign of the string coming in (positive or negative)      ||
|| 2) Assign the length of the new BigInt accordingly - ignoring any '-' sign||
|| 3) Allocate storage for the new BigInt                                    ||
|| 3) Increment through it and assign the values of the BigInt accordingly   ||
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
*/

BIGINT::BigInt::BigInt(std::string s)
{
	//If the first character if '-' then they sent a negative num
	//Otherwise, they sent a positive number

	if (s[0] == '-')
		sign = '-';
	else
		sign = '+';


	if (USE_DEBUG_CODE)
		std::cout << (sign == '+' ? "POSITIVE" : "NEGATIVE") << std::endl;

	//Allocate storage - remember, we cannot include the '-' in the digits array
	//IF they sent a negative number, start copying from index 1 to ignore the '-' character
	digits = new char[sign == '+' ? s.length() : s.length() - 1];

	//Copy over the elements in the array
	int k = 0;

	for (int i = (sign == '+' ? 0 : 1); i < s.length(); i++)
	{
		digits[k++] = s[i];
	}
	if (USE_DEBUG_CODE)
		std::cout << "LENGTH: " << s.length() << std::endl;

	numDigits = (sign == '+' ? s.length() : s.length() - 1);
}

/*
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
|| For this constructor - we take the following steps                        ||
|| 1) Determine if the incoming BigInt is empty							     ||
|| 2) If it is, follow the default constructor, otherwise go to step 3		 ||
|| 3) Allocate storage for the new BigInt, if necessary                      ||
|| 3) Increment through it and assign the values of the BigInt accordingly   ||
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
*/
BIGINT::BigInt::BigInt(const BIGINT::BigInt &toCopy)
{
	if (toCopy.length() == 0)
	{
		digits = nullptr;
		numDigits = 0;
		sign = '+';
	}
	else
	{
		digits = new char[toCopy.length()];
		for (int i = 0; i < toCopy.length(); i++)
		{
			digits[i] = toCopy[i];
		}
		numDigits = toCopy.length();
		sign = toCopy.positive() ? '+' : '-';
	}
}

/*
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
|| For this function - we take the following steps                           ||
|| 1) return the value stored in numDigits - gives the number of digits      ||
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
*/
int BIGINT::BigInt::length() const
{
	return numDigits;
}


/*
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
|| For this function - we take the following steps                           ||
|| 1) Returns TRUE if the number is positive                                 ||
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
*/
bool BIGINT::BigInt::positive() const
{
	return (sign == '+');
}

/*
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
|| For this destructor we take the following steps                           ||
|| 1) deallocate the digits array IF TE STRING IS NOT EMPTY                  ||
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
*/
BIGINT::BigInt::~BigInt()
{
	if (length() >= 1)
		delete[] digits;
}


/*
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
|| For this function - we take the following steps                           ||
|| 1) return the character stored in index i                                 ||
|| -- The indexing is done from left to right                                ||
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
*/
char& BIGINT::BigInt::operator[] (const int index) const
{
	return (digits[index]);
}

BIGINT::BigInt BIGINT::BigInt::operator+(const BIGINT::BigInt toAdd)
{

	//for moment, assume both positive
	if (length() > toAdd.length())
	{
		/* The number we are adding is smaller in magnitude */
	}
	else
	{
		/* The number being added to it is smaller in magnitude */
	}

	return BIGINT::BigInt(0);
}

/*
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
|| For this function - we take the following steps                           ||
|| 1) output the elements in the digits arrat IF NOT EMPTY                   ||
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
*/
std::ostream& BIGINT::operator<< (std::ostream &os, const BigInt &toPrint)
{
	std::cout << "PRINTING: " << std::endl;
	std::cout << "Length of printing integer: " << toPrint.length() << std::endl;
	for (int i = 0; i < toPrint.length(); i++)
	{
		os << toPrint[(toPrint.length() - i - 1)];
	}

	return os;
}

/*
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
|| For this function - we take the following steps                           ||
|| 1) Return TRUE is every element in digits is equal to every element in    ||
||    equal.digits                                                           ||
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
*/
bool BIGINT::BigInt::operator== (const BIGINT::BigInt &equal)
{
	if (digits == nullptr && equal.isEmpty())
		return true;

	for (int i = 0; i < numDigits; i++)
	{
		if (digits[i] != equal[i])
			return false;
	}
	return true;
}

/*
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
|| For this function - we take the following steps                           ||
|| 1) return TRUE if numDigits == 0                                          ||
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
*/
bool BIGINT::BigInt::isEmpty() const
{
	return (numDigits == 0);
}

/* BROKEN - DO NOT USE */
void BIGINT::BigInt::operator= (const BIGINT::BigInt &IntToCopy)
{

	return;

	//delete[] digits;
	std::cerr << "INSIDE COPY FTN" << std::endl;
	digits = new char[IntToCopy.length()];

	for (int i = 0; i < IntToCopy.length(); i++)
	{
		digits[i] = IntToCopy[i];
	}

	numDigits = IntToCopy.length();
	sign = IntToCopy.positive() ? '+' : '-';

}
