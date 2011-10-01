/**

Problem Statement: Bonuses.cpp
    
**/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Bonuses {
	public:
		vector <int> getDivision(vector <int> points)
		{
			int count;
			int i;
			int total = 0;
			count = (int)points.size();
			for(i=0; i< count; ++i)
				total = total + points[i];

			vector <int> ans;
			for(i = 0; i < count ; ++i)
			{
				int share = ((points[i] * 1.0)/ total) * 100;
				ans.push_back(share);
			}

			int distributed = 0;

			for(i = 0; i< count ; ++i)
				distributed += ans[i];

			int remaining = 100 - distributed;

			//cout<<remaining<<"points remaining"<<endl;

			vector <int> sortedans;
			sortedans = ans;
			stable_sort(sortedans.begin(), sortedans.end());

			int topscorers[remaining];
			int j =0;
			int scoredistribution = remaining;

			for(i=int(sortedans.size())-1;scoredistribution>=0; --i, --scoredistribution)
				topscorers[j++] = sortedans[i];

			//for(i=0; i<remaining;++i)
				//cout<<topscorers[i]<<endl;
			int toassign = 0;

			for(i=0; i< remaining;++i)
			{
				toassign = topscorers[i];
				for(j=0;j < (int)ans.size();++j)
					if (ans[j] == toassign)
					{
						ans[j] += 1;
						break;
					}
			}
			return ans;
		}

};

int main()
{
	Bonuses bon;
	vector <int> pointstopass;
	vector <int> answer;
	pointstopass.push_back(5);
	pointstopass.push_back(5);
	pointstopass.push_back(5);
	pointstopass.push_back(5);
	pointstopass.push_back(5);
	pointstopass.push_back(5);
	/**
	pointstopass.push_back(5);
	pointstopass.push_back(4);
	pointstopass.push_back(3);
	pointstopass.push_back(4);
	pointstopass.push_back(2);
	pointstopass.push_back(4);
	pointstopass.push_back(1);
	**/
	answer = bon.getDivision(pointstopass);
	for(int i=0; i<(int)answer.size(); ++i)
		cout<<answer[i]<<endl;
}
