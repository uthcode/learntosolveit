/* TopCoder Problem Statement:
 * http://www.topcoder.com/stat?c=problem_statement&pm=2868&rd=5075
 *
 * Definition      
   Class: NoOrderOfOperations
   Method: evaluate
   Parameters: string
   Returns: int
   Method signature: int evaluate(string expr)
   (be sure your method is public)

 *
 */

#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

class NoOrderOfOperations {
	public:
		int evaluate(string expr)
		{
			int value=0;
			string c;
			for(string::iterator it=expr.begin(); it !=expr.end(); ++it)
			{
				switch(*it)
				{
					case '+':
						++it;
						c = *it;
						value += atoi(c.c_str());
						break;
					case '-':
						++it;
						c = *it;
						value -= atoi(c.c_str());
						break;
					case '*':
						++it;
						c = *it;
						value *= atoi(c.c_str());
						break;
					default:
						c = *it;
						value += atoi(c.c_str());

				}
			}
			return value;

		}


};

int main(int argc, char *argv[])
{
	NoOrderOfOperations obj;
	cout<<obj.evaluate("2+2");
}
