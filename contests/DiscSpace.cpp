/***

Definition
    
Class: DiskSpace
Method: minDrives
Parameters: vector <int>, vector <int>
Returns: int
Method signature: int minDrives(vector <int> used, vector <int> total)
(be sure your method is public)
***/
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

class DiskSpace {
	public:
		int minDrives(vector<int> used, vector<int> total)
		{
			sort(used.begin(),used.end());
			sort(total.begin(), total.end());
			reverse(total.begin(), total.end());
			int i,j,ts;
			ts = total.size();
			int capacity;
			capacity = accumulate(used.begin(),used.end(),0);

			for(i=0;i<ts;i++)
			{
				capacity -= total[i];
				if (capacity <= 0) break;
			}
			return i+1;
		}
};
int main(int argc, char *argv[])
{
	DiskSpace obj;
}
