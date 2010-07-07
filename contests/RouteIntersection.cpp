/***
  SRM 474, Round 1.

Problem Statement
    
Little Dazdraperma likes to travel a lot. One day she made a route in an
N-dimensional space. In this space each point is represented by N coordinates.
The coordinates are indexed from 1 to N, inclusive. She started from the
origin, i.e., a point where each coordinate is 0. Then she did several moves of
the following type: First she chose a coordinate index, i.e., a number between
1 and N, inclusive.  Then she jumped to a point where the coordinate with the
chosen index is either increased or decreased by 1 and all other coordinates
remain the same.  
Now Dazdraperma wonders whether she has ever visited the same point twice. You
will be given a vector <int> coords and a string moves representing her route.
The i-th element of coords is the coordinate index she has chosen during her
i-th move. If the coordinate with this index was increased during the i-th
move, the i-th character of moves will be '+', and it will be '-' if this
coordinate was decreased.  Return "VALID" if all points of her route were
unique, including the first and the last points, and return "NOT VALID"
otherwise. Two points A and B in N-dimensional space are different if there's
an index i such that A's coordinate with index i and B's coordinate with index
i are different.

Definition
    
Class: RouteIntersection
Method: isValid
Parameters: int, vector <int>, string
Returns: string
Method signature: string isValid(int N, vector <int> coords, string moves)
(be sure your method is public)
    

Constraints
- N will be between 1 and 1000000000 (109), inclusive.
- coords will contain between 1 and 50 elements, inclusive.
- Each element of coords will be between 1 and N, inclusive.
- moves will contain the same number of characters as the number of elements in coords.
- Each character in moves will be either '+' or '-'.

Examples
0)
    
1
{1}
"+"
Returns: "VALID"
Dazdraperma starts at (0) and then jumps to (1). The answer is "VALID".

1)

2
{1,2,1,2}
"++--"
Returns: "NOT VALID"
The route goes through 5 points: (0,0) -> (1,0) -> (1,1) -> (0,1) -> (0,0). The point (0,0) was visited twice.

2)
    
3
{1,2,3,1,2}
"+++--"
Returns: "VALID"
(0,0,0) -> (1,0,0) -> (1,1,0) -> (1,1,1) -> (0,1,1) -> (0,0,1).
3)

    
344447
{132,51717,628,344447,628,51717,344447,2}
"+-++-+--"
Returns: "NOT VALID"
The repeated point doesn't have to be the first or the last point in the route.
4)

    
1
{1,1}
"+-"
Returns: "NOT VALID"

5)

    
990630
{833196,524568,361663,108056,28026,824639,269315,440977,440977,765458,
988451,242440,948414,130873,773990,765458,130873,28026,853121,553636,
581069,82254,735536,833196,898562,898562,940783,988451,540613,317306,
623194,940783,571384,988451,108056,514374,97664}
"--+---+-+++-+-+---++-++-+---+-+--+-++"
Returns: "NOT VALID"

This problem statement is the exclusive and proprietary property of TopCoder,
Inc. Any unauthorized use or reproduction of this information without the prior
written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder,
Inc. All rights reserved

**/


#include<iostream>
#include<vector>
#include<set>

using namespace std;

class RouteIntersection {
	public:
		string isValid(int N, vector <int> coords, string moves)
		{
			vector<int> start(N,0);
			set<vector<int> > setofvectors;
			int length = moves.length();
			int i;
			setofvectors.insert(start);
			for(i=0;i<length;i++)
			{
				if (moves[i] == '+')
				{
					start[coords[i]-1] = start[coords[i]-1] + 1;
					cout<<start[0]<<start[1]<<endl;
				}
				if (moves[i] == '-')
				{
					start[coords[i]-1] = start[coords[i]-1] - 1;
					cout<<start[0]<<start[1]<<endl;
				}
				if (setofvectors.count(start) > 0)
					return "INVALID";
				setofvectors.insert(start);
			}
			return "VALID";
			//if (setofvectors.size() == length)
			//	return "VALID";
			//else
			//	return "INVALID";
		}
};

int main(int argc, char *argv[])
{
	int N=2;
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(1);
	v1.push_back(2);
	string s="++--";
	RouteIntersection obj;
	cout<<obj.isValid(N,v1,s)<<endl;
}
