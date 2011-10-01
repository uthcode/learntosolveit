/**

Problem Statement: FormatAmt
    
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
