#pragma once

#include <string>
#include <iostream>

#include <windows.h>

namespace BIGINT
{

#define BIGINT_MAX_LENGTH 4294967296

	class BigInt
	{
	public:

		/* Constructors */
		/* Default Constructor */
		BigInt();
		/* Constructor accepting std::string */
		BigInt(std::string s);
		/* Constructor accepting a regular integer*/
		BigInt(int i);
		/* Constructor accepting another 
		BigInt - Copy constructor*/
		BigInt(const BIGINT::BigInt &toCopy);

		//Destructor
		~BigInt();

		/* Member functions - utility functions */
		bool positive() const;
		bool negative() const;
		int length() const;
		bool isEmpty() const;

		/** Operator Overloads */
		char& operator[] (const int index) const;
		BigInt operator+ (const BigInt toAdd);
		BigInt operator- (const BigInt toSub);
		BigInt operator* (const BigInt toMul);
		BigInt operator/ (const BigInt toDiv);

		/* = operator broken - DO NOT USE */
		void operator= (const BigInt &toEqual);
		bool operator== (const BigInt &equalTo);
		friend std::ostream &operator << (std::ostream &os, const BigInt &toPrint);

	private:
		char sign;
		char *digits;
		int numDigits;
		
	};

}
