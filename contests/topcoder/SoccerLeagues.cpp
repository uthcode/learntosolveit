/**

Class: SoccerLeagues

**/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class SoccerLeagues{
	public:
		vector <int> points(vector <string> matches)
		{
			int number_of_leagues,i,j;
			number_of_leagues = matches.size();
			i= j=number_of_leagues;
			vector<int> points(number_of_leagues);
			for (i = 0; i < number_of_leagues; i++)
				for (j = 0; j < number_of_leagues; j++)
				{
					if (matches[i][j] == 'W')
						points[i] += 3;
					if (matches[i][j] == 'D')
					{
						points[i] += 1;
						points[j] += 1;
					}
					if (matches[i][j] == 'L')
						points[j] += 3;

				}

			return points;
		}


};

int main(int argc, char *argv[])
{
	SoccerLeagues sl;
	vector<string> v1;
	vector<int> res;
	v1.push_back("-DD");
	v1.push_back("L-L");
	v1.push_back("WD-");
	res = sl.points(v1);
	for (int i =0; i< res.size(); i++)
		cout<<res[i]<<endl;

}
