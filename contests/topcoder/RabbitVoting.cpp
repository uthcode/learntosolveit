/**

Class: RabbitVoting
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
					if (name.compare(votes[j]) == 0)
						vote++;
				if (vote > higgest)
				{
					winner = name;
					higgest = vote;
				}
				if (vote == higgest)
					winner = "";
			}
			return winner;
		}
		
};

int main(int argc, char *argv[])
{
	RabbitVoting obj;
	vector<string> names, votes;
	names.push_back("one");
	votes.push_back("one");
	cout<<obj.getWinner(names,votes)<<endl;
}
