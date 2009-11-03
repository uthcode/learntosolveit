/* TopCoder Problem Statement:
   http://www.topcoder.com/tc?module=ProblemDetail&rd=4540&pm=1667

Class: CCipher
Method: decode
Parameters: string, int
Returns: string
Method signature: string decode(string cipherText, int shift)
 

*/

#include<iostream>
#include<string>
using namespace std;

class CCipher {
	public:
		string decode(string cipherText, int shift)
		{
			int c;
			string result;
			for(string::iterator it=cipherText.begin(); 
					it !=cipherText.end();
					++it)
			{
				c = *it;
				if ((c-shift) < 65)
					result.push_back(c-shift+26);
				else
					result.push_back(c-shift);
			}

			return result;
					
		}
};

int main(int argc, char *argv[])
{
	CCipher obj;
	cout<<obj.decode("VQREQFGT",2);

}

