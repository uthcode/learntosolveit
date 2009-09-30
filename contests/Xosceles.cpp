/*
 * Problem Statement:
 * http://www.topcoder.com/stat?c=problem_statement&pm=10152&rd=13952&rm=&cr=22684375
 * */

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

class Xosceles{

	public:
		vector <string> draw(int xCount)
		{
			vector <string> ans;
			string st;
			int n = sqrt(xCount);
			int lastval=0;
			int i,j;
			if (pow(n, 2) == xCount)
				lastval = 2*n -1;
			else if ((n * (n+1)) == xCount)
					lastval = 2*n;
			for (i=0;i<n;i++)
			{
				st.assign(lastval, 'X');
				j = i;
				while (j)
				{
					st[j-1] = '.';
					st[lastval - j] =  '.';
					j--;
				}
				ans.push_back(st);
			}

			reverse(ans.begin(), ans.end());
			return ans;
		}
};

int main(int argc, char *argv[])
{
	Xosceles obj;
	vector<string> xosceles_tri;
	xosceles_tri = obj.draw(2550);	
	for (int i=0; i <xosceles_tri.size(); i++)
		cout<<xosceles_tri[i]<<endl;
}
