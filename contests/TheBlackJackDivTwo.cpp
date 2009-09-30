#include<iostream>
#include<vector>
#include<cstdlib>
#include<stdio.h>

using namespace std;

class TheBlackJackDivTwo
{
	public:
		int score(vector<string> cards)
		{
			int score=0;
			int type;
			for (int i=0; i<cards.size(); i++)
			{
				type = cards[i][0];
				if (50 <= type && type <= 57)
					score = score + (type-48);
				else if (type == 84)
					score = score + 10;
				else if (type == 65)
					score = score + 11;
				else if (type == 74 || type == 75 || type == 81)
					score = score + 10;
			}
			
			return score;
		}
};

int main(int argc, char *argv[])
{
	TheBlackJackDivTwo obj;
	vector<string> v1;
	v1.push_back("4S");
	v1.push_back("7D");
	cout<<obj.score(v1);
}
