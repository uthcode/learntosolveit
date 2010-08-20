/**
* Author: O.R.Senthil Kumaran.
*
**/



#include <vector>
#include <iostream>

using namespace std;

class TriFibonacci
{
	public:
		int complete(vector <int> A)
		{
			int i,total,value;
			total = A.size();
			if (A[0] == -1)
			{
			        A[0] = A[3] - (A[2] + A[1]);
				value = A[0];
			}
			if (A[1] == -1)
			{
				A[1] = A[3] - (A[2] + A[0]);
				value = A[1];
			}
			if (A[2] == -1)
			{
				A[2] = A[3] - (A[1] + A[0]);
				value = A[2];
			}
			for (i=3; i < total; i++)
			{
				if (A[i] == -1)
				{
					A[i] = A[i-1] + A[i-2] + A[i-3];
					value = A[i];
				}
				else
				{
					if (A[i] == A[i-1] + A[i-2] + A[i-3])
						continue;
					else
						return -1;
				}
			}
			if (i == total)
			{
				if (value > 0)
					return value;
				else
					return -1;
			}
		}
};

int main(int argc, char *argv[])
{
	TriFibonacci num;
	vector <int> anum;
	anum.push_back(-1);
	anum.push_back(7);
	anum.push_back(8);
	anum.push_back(1000000);
	cout<<num.complete(anum)<<endl;
}
