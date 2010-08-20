/**

Problem Statement
    
In documents, it is frequently necessary to write monetary amounts in a
standard format. We have decided to format amounts as follows:

the amount must start with '$'
the amount should have a leading '0' if and only if it is less then 1 dollar.
the amount must end with a decimal point and exactly 2 following digits.
the digits to the left of the decimal point must be separated into groups of three by commas (a group of one or two digits may appear on the left).

Create a class FormatAmt that contains a method amount that takes two int's,
dollars and cents, as inputs and returns the properly formatted string.

Definition
    
Class: FormatAmt
Method: amount
Parameters: int, int
Returns: string
Method signature: string amount(int dollars, int cents)
(be sure your method is public)
    

Notes
- One dollar is equal to 100 cents.  

Constraints
- dollars will be between 0 and 2,000,000,000 inclusive
- cents will be between 0 and 99 inclusive
Examples

0)
    
123456
0
Returns: "$123,456.00"
Note that there is no space between the $ and the first digit.

1)

49734321
9
Returns: "$49,734,321.09"

2)

    
0
99
Returns: "$0.99"
Note the leading 0.
3)

    
249
30
Returns: "$249.30"

4)

    
1000
1
Returns: "$1,000.01"

This problem statement is the exclusive and proprietary property of TopCoder,
Inc. Any unauthorized use or reproduction of this information without the prior
written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder,
Inc. All rights reserved.

**/

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class FormatAmt {

	public:
		string amount(int dollars, int cents)
		{
			string result;
			string reversedstr;
			string centsval = ".";
			string finalresult;
			int digit;
			char c;
			int count=0;
			while(dollars > 9)
			{
				digit = dollars - ((dollars/10) * 10);
				c = (char) (48 + digit);
				result += c;
				dollars /= 10;
				count++;
				if (count %3 == 0) result += ",";
			}
			c = (char) (48 + dollars);
			result += c;
			result += "$";
			for(string::iterator it = result.end();
					it != result.begin();
					it--)
			{
				c = *it;
				reversedstr.push_back(c);
			}
			c = result[0];
			reversedstr.push_back(c);
			if (cents == 0)
			{
				centsval += "00";
				finalresult = reversedstr + centsval;
				return finalresult;
			}
			if (cents < 10)
			{
				c = (char) (48 + cents);
				centsval += "0";
				centsval += c;
				finalresult = reversedstr + centsval;
				return finalresult;
			}
			string centsdigits;
			while (cents > 0)
			{
				digit = cents - ((cents/10) * 10);
				c = (char) (48 + digit);
				centsdigits += c;
				cents /= 10;
			}
			centsval += centsdigits[1];
			centsval += centsdigits[0];
			finalresult = reversedstr + centsval;
			return finalresult;
		}

};

int main(int argc, char *argv[])
{
	FormatAmt obj;
	cout<<obj.amount(1000009,10)<<endl;
}
