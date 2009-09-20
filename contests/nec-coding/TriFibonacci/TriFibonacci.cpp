/**
 *
Problem Statement
    
A TriFibonacci sequence begins by defining the first three elements A[0], A[1] and A[2]. The remaining elements are calculated using the following recurrence: 
A[i] = A[i-1] + A[i-2] + A[i-3]
  You are given a vector <int> A which contains exactly one element that is equal to -1, you must replace this element with a positive number in a way that the sequence becomes a TriFibonacci sequence. Return this number. If no such positive number exists, return -1.
  Definition
      
  Class:
  TriFibonacci
  Method:
  complete
  Parameters:
  vector <int>
  Returns:
  int
  Method signature:
  int complete(vector <int> A)
	(be sure your method is public)
	    

	Notes
	-
	The constraints for the elements of the input vector <int> A do not necessarily apply for the replacement to the missing element.
	Constraints
	-
	A will contain between 4 and 20 elements, inclusive.
	-
	Each element of A will be -1 or between 1 and 1000000, inclusive.
	-
	Exactly one element of A will be -1.
	Examples
	0)

	    
{1,2,3,-1}
Returns: 6

1)

    
{10, 20, 30, 60, -1 , 200}
Returns: 110

2)

    
{1, 2, 3, 5, -1}
Returns: -1
No replacement can make this sequence TriFibonacci as 5 is not equal to 1+2+3.
3)

    
{1, 1, -1, 2, 3}
Returns: -1
The missing element must be 0 for this sequence to be TriFibonacci. Since this is not a positive integer, return -1.
4)

    
{-1, 7, 8, 1000000}
Returns: 999985

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.

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
