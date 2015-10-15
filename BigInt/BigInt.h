#pragma once

#include <string>
#include <iostream>

namespace BIGINT
{

#define BIGINT_MAX_LENGTH 4294967296

	class BigInt
	{
	public:
		BigInt();
		BigInt(std::string s);
		BigInt(int i);
		BigInt(const BIGINT::BigInt &toCopy);
		~BigInt();
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
		bool operator== (const BigInt equalTo);
		friend std::ostream &operator << (std::ostream &os, const BigInt &toPrint);

	private:
		char sign;
		char *digits;
		int numDigits;
		
	};

}
