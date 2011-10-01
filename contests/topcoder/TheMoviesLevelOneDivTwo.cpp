/**

Problem Statement
    
Class: TheMoviesLevelOneDivTwo
**/

#include<vector>
#include<iostream>

using namespace std;

class TheMoviesLevelOneDivTwo
{
	public:
		int find(int n, int m, vector<int> row, vector<int> seat)
		{
			int length=0;
			int i=0;
			int j=0;
			int k=0;
			int cinema[n][m];
			int r;
			int s;
			length = row.size();
			for (i=0;i<n;i++)
				for (j=0;j<m;j++)
					cinema[i][j] = 0;
			for (k=0;k<length;k++)
			{
				r=row[k];
				s=seat[k];
				cinema[r-1][s-1] = -1;
			}
			int count=0;
			for(i=0;i<n;i++)
				for(j=0;j<m-1;j++)
				{
					if((cinema[i][j] == 0 ) && (cinema[i][j+1] == 0))
						count++;
				}
			return count;
		}
};

int main(int argc, char *argv[])
{
	TheMoviesLevelOneDivTwo obj;
	vector<int> r;
	vector<int> s;
	r.push_back(1);
	s.push_back(1);
	cout<<obj.find(4,7,r,s)<<endl;
}
