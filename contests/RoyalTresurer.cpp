/***
Problem Statement
    
Once upon a time, there was a kingdom where math was always a big problem. When
the post of the royal treasurer needed to be filled, applicants were presented
with the following problem:  "We have two arrays of integers, A and B. A and B
each contain exactly N elements. Let's define a function S over A and B: 

	S = A0*B0 + … + AN-1*BN-1

Rearrange the numbers in A in such a way that the value of S is as small as
possible. You are not allowed to rearrange the numbers in B.”  The problem
writers need a program to check the correctness of the applicants' answers.
Given vector <int>s A and B, return the smallest possible value for S.
Definition
    
Class:
RoyalTreasurer
Method:
minimalArrangement
Parameters:
vector <int>, vector <int>
Returns:
int
Method signature:
int minimalArrangement(vector <int> A, vector <int> B)
(be sure your method is public)
    

Constraints
- A will contain between 1 and 50 elements, inclusive.
- A and B will contain the same number of elements.
- Each element of A will be between 0 and 100, inclusive.
- Each element of B will be between 0 and 100, inclusive.

Examples
0)
    
{1,1,3}
{10,30,20}
Returns: 80
If you move the number 3 to the beginning of A, you get the minimal possible
sum.

1)

    
{1,1,1,6,0}
{2,7,8,3,1}
Returns: 18
The best option would be to rearrange the numbers in A this way: {1,1,0,1,6}.

2)

    
{5,15,100,31,39,0,0,3,26}
{11,12,13,2,3,4,5,9,1}
Returns: 528

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
