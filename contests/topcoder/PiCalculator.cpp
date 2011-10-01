/**

Class: PiCalculator

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
