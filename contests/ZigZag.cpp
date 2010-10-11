/**
Problem Statement
    
A sequence of numbers is called a zig-zag sequence if the differences between
successive numbers strictly alternate between positive and negative. The first
difference (if one exists) may be either positive or negative. A sequence with
fewer than two elements is trivially a zig-zag sequence.

For example, 1,7,4,9,2,5 is a zig-zag sequence because the differences
(6,-3,5,-7,3) are alternately positive and negative. In contrast, 1,4,7,2,5 and
1,7,4,5,5 are not zig-zag sequences, the first because its first two
differences are positive and the second because its last difference is zero.

Given a sequence of integers, sequence, return the length of the longest
subsequence of sequence that is a zig-zag sequence. A subsequence is obtained
by deleting some number of elements (possibly zero) from the original sequence,
leaving the remaining elements in their original order.  Definition
    
Class: ZigZag
Method: longestZigZag
Parameters: vector <int>
Returns: int
Method signature: int longestZigZag(vector <int> sequence)
(be sure your method is public)
    
Constraints

- sequence contains between 1 and 50 elements, inclusive.
- Each element of sequence is between 1 and 1000, inclusive.

Examples

0){ 1, 7, 4, 9, 2, 5 }
Returns: 6
The entire sequence is a zig-zag sequence.

1){ 1, 17, 5, 10, 13, 15, 10, 5, 16, 8 }
Returns: 7
There are several subsequences that achieve this length. One is 1,17,10,13,10,16,8.

2){ 44 }
Returns: 1

3){ 1, 2, 3, 4, 5, 6, 7, 8, 9 }
Returns: 2

4){ 70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32 }

Returns: 8

5)
{ 374, 40, 854, 203, 203, 156, 362, 279, 812, 955, 
600, 947, 978, 46, 100, 953, 670, 862, 568, 188, 
67, 669, 810, 704, 52, 861, 49, 640, 370, 908, 
477, 245, 413, 109, 659, 401, 483, 308, 609, 120, 
249, 22, 176, 279, 23, 22, 617, 462, 459, 244 }
Returns: 36

This problem statement is the exclusive and proprietary property of TopCoder,
Inc. Any unauthorized use or reproduction of this information without the prior
written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder,
Inc. All rights reserved.
**/

#include<iostream>
#include<vector>
using namespace std;

class ZigZag
{
	public:
	int longestZigZag(vector <int> sequence)
	{
		int len;
		int prevsign=0;
		int sign;
		vector<int> resultseq;
		
		for (int i=0; i < sequence.size(); i++)
		{
			if (i == 0) 
			{
				resultseq.push_back(sequence[i]);
				continue;
			}
			if (i == 1)
			{
				resultseq.push_back(sequence[i]);
				if ((sequence[i] - sequence[i-1]) > 0)
					prevsign = 1;
				else
					prevsign = -1;
				continue;
			}
			if (sequence[i] == sequence[i-1])
				continue;

			if ((sequence[i] - sequence[i-1]) > 0)
				sign = 1;

			else
				sign = -1;

			if (prevsign != sign)
			{
				resultseq.push_back(sequence[i]);
			}
			else
			{
				resultseq[resultseq.size()-1] = sequence[i];
			}
			prevsign = sign;

		}

		len = resultseq.size();
		return len;
	}
};

int main(int argc, char *argv[])
{
	ZigZag obj;
	vector<int> sequence;
	sequence.push_back(1);
	sequence.push_back(17);
	sequence.push_back(5);
	sequence.push_back(10);
	sequence.push_back(13);
	sequence.push_back(15);
	sequence.push_back(10);
	sequence.push_back(5);
	sequence.push_back(16);
	sequence.push_back(8);
	cout<<obj.longestZigZag(sequence)<<endl;
}

