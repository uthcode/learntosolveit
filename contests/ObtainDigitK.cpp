/**
 
Problem Statement.

SRM 367. DIV I
    
**/

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

class ObtainDigitK {
	public:
		int minNumberToAdd(string s, int i)
		{
			string lastchar;
			string i_str;
			stringstream out;
			out << i;
			i_str = out.str();
			size_t found;
			found = s.find(i_str);
			if (found != string::npos)
				return 0;

			lastchar = s[s.length()-1];
			int lastchar_int = atoi(lastchar.c_str());
			if (lastchar_int <= i)
				return (i-lastchar_int);
			else
				return ((i+10) - lastchar_int);

		}
};

int main(int argc, char *argv[])
{
	ObtainDigitK obj;
	cout<<obj.minNumberToAdd("44",1)<<endl;
}
