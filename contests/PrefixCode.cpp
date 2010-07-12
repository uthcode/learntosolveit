/**
Definition
    
Class: PrefixCode
Method: isOne
Parameters: vector <string>
Returns: string
Method signature: string isOne(vector <string> words)
(be sure your method is public)

0)

    
{"trivial"}
Returns: "Yes"
As there is only one word, no word can be the prefix of another, so this is a trivial example of a prefix code.
1)

{"10001", "011", "100", "001", "10"}
Returns: "No, 2"
"100" (at index 2) and "10" (at index 4) are both a prefix of "10001" and "10" is also a prefix of "100", therefore it is no prefix code. "100" is the prefix with the lowest index.

**/

#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

class PrefixCode {
	public:
		string isOne(vector <string> words)
		{
			int numofwords,i,j;
			string eachword;
			size_t found;
			string result;
			stringstream out;
			numofwords = (int) words.size();
			for( i = 0; i< numofwords; i++)
			{
				eachword = words[i];
				for (j = 0; j < numofwords; j++)
				{
					if (i == j)
						continue;
					found = words[j].find(eachword);
					if (found != string::npos)
						if ((int)found == 0)
						{
							out<< i;
							result = "No, " + out.str();
							return result;
						}
				}
			}
			return "Yes";
		}
};

int main(int argc, char *argv[])
{
	PrefixCode obj;
	vector <string> words;
	words.push_back("two");
	words.push_back("twosome");
	cout<<obj.isOne(words);
}
