/***

Problem Statement
    
You may remember an old computer game called "The Incredible Machine". It was a
game where you could simulate simple processes like balls falling, lasers
shooting, or cats pursuing mice. Moreover, you were able to perform these
observations with different values for gravitational acceleration.  Imagine a
system with some unknown acceleration of gravity. There are N balls, each fixed
initially at some height above the ground. You are given a vector <int> height,
where the i-th element is the height of the i-th ball above the ground. At time
0, the first ball is set loose and it starts falling. When it reaches the
ground, the second ball is instantly set loose, and so on. This continues until
the last ball reaches the ground at time T.  Return the acceleration of gravity
in this system. Neglect air resistance and any other resisting factors. The
distance d travelled by an object falling for time t with no initial velocity
in a system with gravitational acceleration g and no resisting factors is equal
to d = 0.5 * g * t^2.

Definition
    
Class:
IncredibleMachineEasy
Method:
gravitationalAcceleration
Parameters:
vector <int>, int
Returns:
double
Method signature:
double gravitationalAcceleration(vector <int> height, int T)
	(be sure your method is public)
	    

	Constraints
	-
	height will contain between 1 and 50 elements, inclusive.
	-
	Each element of height will be between 1 and 100, inclusive.
	-
	T will be between 1 and 100, inclusive.
	Examples
	0)

	    
{16,23,85,3,35,72,96,88,2,14,63}
30
Returns: 9.803799620759717
That's an acceleration of gravity that might be somewhere on Earth's surface.
1)

    
{6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5}
12
Returns: 26.73924541044107
And this is likely on Jupiter.
2)

    
{8,8}
3
Returns: 7.111111111111111
That's a light one.
3)

    
{3,1,3,1,3}
12
Returns: 0.7192306901503684
You could nearly fly under such conditions.

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
***/

#include<math.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<iomanip>

using namespace std;

class IncredibleMachineEasy {

	public:

	double gravitationalAcceleration(vector <int> height, int T)
	{
		double gravity;
		double sumsq2ds=0.0;
		for (int i =0; i < height.size(); i++) {
			sumsq2ds = sumsq2ds + sqrt(2.0*height[i]);
		}
		gravity = (sumsq2ds * sumsq2ds) / (T*T);

		return gravity;

	}

};

int main()
{
	IncredibleMachineEasy gravity;
	vector<int> values;
	values.push_back(3);
	values.push_back(1);
	values.push_back(3);
	values.push_back(1);
	values.push_back(3);
	cout<<setprecision(12);
	cout << gravity.gravitationalAcceleration(values,12) <<endl;
}
