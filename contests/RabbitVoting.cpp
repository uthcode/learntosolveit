/**

Problem Statement
    
Rabbits often feel lonely, so one group of rabbits decided to get together and
hold a beauty contest to determine who among them has the most beautiful ears.
The rules are as follows. Each rabbit submits one vote. If a rabbit votes for
himself/herself, that vote is considered invalid and thrown away. In the end,
the rabbit who receives the most valid votes is the winner.  You are given a
vector <string> names and a vector <string> votes. The i-th rabbit is named
names[i], and he/she voted for the rabbit named votes[i]. All rabbits have
distinct names. Return the name of the rabbit who received the most valid
votes. If there is a tie for most votes, return an empty string instead.

Definition
    
Class: RabbitVoting
Method: getWinner
Parameters: vector <string>, vector <string>
Returns: string
Method signature: string getWinner(vector <string> names, vector <string> votes)
(be sure your method is public)
    

Notes

- Rabbit names are case-sensitive. See example 4 for clarification.

Constraints

- names will contain between 2 and 50 elements, inclusive.
- Each element of names will contain between 1 and 50 characters, inclusive.
- Each character in names will be a letter ('A'-'Z', 'a'-'z').
- All elements of names will be distinct.
- votes will contain the same number of elements as names.
- Each element of votes will be the same as one of the elements of names.

Examples
0)

    
{ "Alice", "Bill", "Carol", "Dick" }
{ "Bill", "Dick", "Alice", "Alice" }
Returns: "Alice"
2 votes for Alice, 1 for Bill, 0 for Carol, and 1 for Dick. Alice got the most.
1)

    
{ "Alice", "Bill", "Carol", "Dick" }
{ "Carol", "Carol", "Bill", "Bill" }
Returns: ""
Bill and Carol are tied with 2 votes each.
2)

    
{ "Alice", "Bill", "Carol", "Dick" }
{ "Alice", "Alice", "Bill", "Bill" }
Returns: "Bill"
Alice's vote for herself is invalid. 1 valid vote for Alice, 2 for Bill.
3)

    
{ "Alice", "Bill" }
{ "Alice", "Bill" }
Returns: ""
All votes are invalid.
4)

    
{ "WhiteRabbit", "whiterabbit", "whiteRabbit", "Whiterabbit" }
{ "whiteRabbit", "whiteRabbit", "whiteRabbit", "WhiteRabbit" }
Returns: "whiteRabbit"
These four are different names.
**/

#include <vector>
#include <iostream>
using namespace std;

class RabbitVoting {
	public:
		string getWinner(vector<string> names, vector<string> votes)
		{
			int number,i,j,vote,higgest;
			string winner;
			string name;
			number = (int)names.size();
			number = number -1;
			higgest = 0;
			for (i = 0; i <=number; i++)
			{
				name = names[i];
				vote =0;
				for(j = 0; j <=number;j++)
					if ((name.compare(votes[j]) == 0) && (i != j))
						vote++;

				if (vote == higgest)
					winner = "";
				if (vote > higgest)
				{
					winner = name;
					higgest = vote;
				}
			}
			return winner;
		}
		
};

int main(int argc, char *argv[])
{
	RabbitVoting obj;
	vector<string> names, votes;
	names.push_back("Alice");
	names.push_back("Bill");
	names.push_back("Carol");
	names.push_back("Dick");
	votes.push_back("Bill");
	votes.push_back("Dick");
	votes.push_back("Alice");
	votes.push_back("Alice");
	cout<<obj.getWinner(names,votes)<<endl;
}
