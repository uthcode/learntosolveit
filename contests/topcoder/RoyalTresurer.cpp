/***
    
Class: RoyalTreasurer

**/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class RoyalTreasurer{
	public:
		int minimalArrangement(vector <int> A, vector <int> B)
		{
			int sum = 0;
			sort(A.begin(),A.end());
			sort(B.begin(),B.end(),greater<int>());
			for (int i=0; i < A.size(); ++i)
				sum = sum + A[i] * B[i];
			return sum;
		}

};

int main(int argc, char* argv[])
{
	RoyalTreasurer rt;
	vector<int> A;
	vector<int> B;
	A.push_back(1);A.push_back(1);A.push_back(1);
	A.push_back(6);A.push_back(0);
	B.push_back(2);B.push_back(7);B.push_back(8);
	B.push_back(3);B.push_back(1);
	cout<<rt.minimalArrangement(A,B);
}
