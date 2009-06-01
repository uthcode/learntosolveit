/**

Problem Statement
    
The problem statement contains the unicode symbols.

You are developing a new software calculator. A very important feature is the
auto-placing of the ? value by one click. The only problem is that you don't
know the required precision. That's why you decided to write a program that can
return ? with any reasonable precision.  You are given an int precision. You
should return the ? value with exactly precision digits after the decimal
point. The last digit(s) should be rounded according to the standard rounding
rules (less than five round down, more than or equal to five round up).
Definition
    
Class: PiCalculator
Method: calculate
Parameters: int
Returns: string
Method signature: string calculate(int precision) (be sure your method is public)
	    
	Notes
	-
	? equals 3.141592653589793238462643383279...
	Constraints
	-
	precision will be between 1 and 25, inclusive.
	Examples
	0)      2
	Returns: "3.14"

	1)      4
	Returns: "3.1416"

	The value should be rounded.
	2)      12
	Returns: "3.141592653590"
	Be careful with rounding.

This problem statement is the exclusive and proprietary property of TopCoder,
Inc. Any unauthorized use or reproduction of this information without the prior
written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder,
Inc. All rights reserved.

***/

/** TODO: Revisit this program after learning string, char *, const char* and other string handling methods in C++.
 * Program in the current form is very bad in the way it does string -> char -> int -> char -> string conversions.
 */

#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

class  PiCalculator {
	public: 
		string calculate(int precision) {
			string pistring ("3.141592653589793238462643383279");
			int dot = int(pistring.find('.'));
			string lastchar;
		        lastchar= pistring[dot+precision];
			int value = atoi(lastchar.c_str());
			if (value > 4) ++value;
			if (value == 10) 
			{
				// Special case for rounding two digits.
				// pistring does not have consecutive 9s so I am using this dumb method.
				string laststr("0");
				string last_but_one_char;
				last_but_one_char = pistring[dot+precision-1];
				int last_but_one_value = atoi(last_but_one_char.c_str());
				++last_but_one_value;

				char svalue[1];
				sprintf(svalue,"%d",last_but_one_value);
				string last_but_one_str;
				last_but_one_str = string(svalue);

				string slice;

				slice = pistring.substr(0,(dot+precision)-1);

				string result;

				result = slice + last_but_one_str + laststr;

				return result;

			}
			char svalue[1];
			sprintf(svalue,"%d",value);
			string lastchar_str;
			lastchar_str = string(svalue);
			string slice;
			slice = pistring.substr(0,(dot+precision));
			string result;
			result = slice + lastchar_str;
			return result;
		}
};

int main()
{
	PiCalculator piobj;
	cout<<piobj.calculate(12);
}
