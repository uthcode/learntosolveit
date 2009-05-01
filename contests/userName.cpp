/***

Problem Statement
    
You are implementing the member registration system of an online dating site.
When a new member signs up, it is possible that she initially chooses the same
username as an existing member. The system must then inform the new member of
the conflict and suggest a variant of the chosen name with a number attached to
the end.
If an existing member is named "FunkyMonkey", for example, and a new member
wants the same username, the simplest suggestion the system can make is
"FunkyMonkey1". If there is already a member by that name, the system must
suggest "FunkyMonkey2", unless that variant is also taken. If all names from
"FunkyMonkey1" through "FunkyMonkey9" are taken as well as the original
"FunkyMonkey", the system moves on to consider "FunkyMonkey10", and so on. The
goal is to use the smallest possible number in the variant. Note that each
username consists of letters (the characters from 'a' to 'z' and from 'A' to
'Z') and numerals ('0' to '9').

You are given a vector <string>, existingNames, containing all usernames that
have already been registered in the system. You are also given a single string,
newName, containing the username that a new member wants to use. In the event
of a conflict, this member will accept the suggestion offered by your system in
accordance with the principles above. Return a string containing the username
finally assigned to the new member.

Definition
    
Class:
UserName
Method:
newMember
Parameters:
vector <string>, string
Returns:
string
Method signature:
string newMember(vector <string> existingNames, string newName)
(be sure your method is public)
    

Notes
-
The constraints rule out names that end in a number with a leading zero, such as "grokster006" and "bart0".
Constraints
-
existingNames contains between 1 and 50 elements, inclusive
-
each element of existingNames is between 1 and 50 characters long, inclusive
-
the only characters permitted in elements of existingNames are 'a' to 'z', 'A' to 'Z', and '0' to '9'
-
no element of existingNames ends in a number that has a leading zero
-
newName is between 1 and 50 characters long, inclusive
-
the only characters permitted in newName are 'a' to 'z' and 'A' to 'Z'
Examples
0)

    
{"MasterOfDisaster", "DingBat", "Orpheus", "WolfMan", "MrKnowItAll"}
"TygerTyger"
Returns: "TygerTyger"
"TygerTyger" is available.
1)

    
{"MasterOfDisaster", "TygerTyger1", "DingBat", "Orpheus", 
 "TygerTyger", "WolfMan", "MrKnowItAll"}
"TygerTyger"
Returns: "TygerTyger2"
"TygerTyger" and "TygerTyger1" are taken.
2)

    
{"TygerTyger2000", "TygerTyger1", "MasterDisaster", "DingBat", 
 "Orpheus", "WolfMan", "MrKnowItAll"}
"TygerTyger"
Returns: "TygerTyger"
There are higher-numbered variants of "TygerTyger", but the base name is available.
3)

    
{"grokster2", "BrownEyedBoy", "Yoop", "BlueEyedGirl", 
 "grokster", "Elemental", "NightShade", "Grokster1"}
"grokster"
Returns: "grokster1"
Note that "Grokster1" is not the same as "grokster1".
4)

    
{"Bart4", "Bart5", "Bart6", "Bart7", "Bart8", "Bart9", "Bart10",
 "Lisa", "Marge", "Homer", "Bart", "Bart1", "Bart2", "Bart3",
 "Bart11", "Bart12"}
"Bart"
Returns: "Bart13"

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.

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


