/***
  TopCoder Problem Statment:
  http://www.topcoder.com/stat?c=problem_statement&pm=2913&rd=5849

  The interface definition of the problem statement is given in Java, it is
  different for C++ and correct one is available from the arena.

**/

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class UserName {
	public:
		string newMember(vector<string> existingNames,string newName) {
			// code implementing the logic
			vector<string>::iterator it = find(existingNames.begin(), existingNames.end(), newName);

			if (it!= existingNames.end())
				for(int i = 1; i < (50 - newName.length()); i++) {
					ostringstream oss;
					oss <<newName<<i;
					string check(oss.str());
					vector<string>::iterator it2 = find(existingNames.begin(), existingNames.end(), check);
					if (it2 == existingNames.end())
						return check;
				}
			else
				return newName;
		}
};

int main()
{
	UserName uname;
	vector<string> existingNames;
	string newName1,newName2,newName3;

	existingNames.push_back("senthil");
	existingNames.push_back("Kumaran");
	existingNames.push_back("Senthil2");
	existingNames.push_back("Senthil1");
	existingNames.push_back("Kumaran4");

	newName1 = "Senthil";
	newName2 = "Kumaran";
	newName3 = "OR";
	cout << uname.newMember(existingNames, newName1) <<"\n";
	cout << uname.newMember(existingNames, newName2) <<"\n";
	cout << uname.newMember(existingNames, newName3) <<"\n";

	return 0;
}


