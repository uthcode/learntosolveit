/***
  SRM 474, Round 1.

Class: RouteIntersection

**/


#include<iostream>
#include<vector>
#include<set>

using namespace std;

class RouteIntersection {
	public:
		string isValid(int N, vector <int> coords, string moves)
		{
			vector<int> start(N,0);
			set<vector<int> > setofvectors;
			int length = moves.length();
			int i;
			setofvectors.insert(start);
			for(i=0;i<length;i++)
			{
				if (moves[i] == '+')
				{
					start[coords[i]-1] = start[coords[i]-1] + 1;
					cout<<start[0]<<start[1]<<endl;
				}
				if (moves[i] == '-')
				{
					start[coords[i]-1] = start[coords[i]-1] - 1;
					cout<<start[0]<<start[1]<<endl;
				}
				if (setofvectors.count(start) > 0)
					return "INVALID";
				setofvectors.insert(start);
			}
			return "VALID";
			//if (setofvectors.size() == length)
			//	return "VALID";
			//else
			//	return "INVALID";
		}
};

int main(int argc, char *argv[])
{
	int N=2;
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(1);
	v1.push_back(2);
	string s="++--";
	RouteIntersection obj;
	cout<<obj.isValid(N,v1,s)<<endl;
}
