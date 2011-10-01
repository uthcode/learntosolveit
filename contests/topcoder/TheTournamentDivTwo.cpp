/* TopCoder SRM 453 Div2:
 * http://www.topcoder.com/stat?c=problem_statement&pm=10686&rd=13907
 */

#include<vector>
#include<iostream>
using namespace std;

class TheTournamentDivTwo {
	public:
		int find(vector<int> points)
		{
			int won = 0, draw = 0;
			for(vector<int>::iterator it=points.begin(); it!=points.end(); ++it)
			{
				won += (*it)/2;
				draw += (*it)%2;
			}
			if (draw%2 == 1) return -1;
			draw = draw/2;
			return won+draw;
		}
};

int main(int argc, char *argv[])
{
	TheTournamentDivTwo obj;
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(1);
	v1.push_back(1);
	cout<<obj.find(v1);
}
