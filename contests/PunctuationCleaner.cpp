/***

Definition
    
Class: PunctuationCleaner
Method: clearExcess
Parameters: string
Returns: string
Method signature: string clearExcess(string document)
(be sure your method is public)

***/

#include<iostream>
#include<string>
using namespace std;

class PunctuationCleaner {
	public:
		string clearExcess(string document) {
			string::iterator it;
			string output, c, d;
			int count;
			for(it = document.begin(); it < document.end();it++)
			{
				c = *it;
				d = "";
				count = 0;
				while ((c == "!") || (c == "?"))
				{
					if (c == "?")
						d = c = "?";
					it++;
					c = *it;
					count++;
				}
				if (d == "?")
					output += d;
				else if (count > 0)
					output += "!";
				output += c;
			}
			return output;
		}
};

int main(int argc, char *argv[]) {
	PunctuationCleaner obj;
	cout<<obj.clearExcess("This cheese is really great!!!!!");
}

