/**
Class: PrefixCode

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
