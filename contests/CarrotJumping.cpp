/**

Problem Statement
    
Rabbits often feel hungry, so when they go out to eat carrots, they jump as quickly as possible.  Initially, rabbit Hanako stands at position init. From position x, she can jump to either position 4*x+3 or 8*x+7 in a single jump. She can jump at most 100,000 times because she gets tired by jumping.  Carrots are planted at position x if and only if x is divisible by 1,000,000,007 (i.e. carrots are planted at position 0, position 1,000,000,007, position 2,000,000,014, and so on). Return the minimal number of jumps required to reach a carrot. If it's impossible to reach a carrot using at most 100,000 jumps, return -1.  
Definition
    
Class:
CarrotJumping
Method:
theJump
Parameters:
int
Returns:
int
Method signature:
int theJump(int init)
(be sure your method is public)
    

Constraints
-
init will be between 1 and 1,000,000,006, inclusive.
Examples
0)

    
125000000
Returns: 1
She can jump from 125000000 to 1000000007.
1)

    
281250001
Returns: 2
281250001 -> 1125000007 -> 9000000063
2)

    
18426114
Returns: 58

3)

    
4530664
Returns: 478

4)

    
705616876
Returns: 100000

5)

    
852808441
Returns: -1
She can't reach any carrot by making at most 100,000 jumps.
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.

**/
/*

Definition
    
Class: CarrotJumping
Method: theJump
Parameters: int
Returns: int
Method signature: int theJump(int init)
(be sure your method is public)

*/

#include<iostream>
using namespace std;

class CarrotJumping {
	public:
		int theJump(int init)
		{
			int n,np,a,b;
			np = init;
			if ((np % 1000000007) == 0)
				return n;
			for(n = 0; n < 100000; n++)
			{
				a = (4 * np) + 3;
				if ((a % 1000000007) == 0)
				{
					return n+1;
				}
				b = (8 * np) + 7;
				if (( b % 1000000007) == 0)
				{
					return n+1;
				}
				if ((a % 1000000007)< (b % 1000000007))
					np = a;
				else
					np = b;
			}

		}
};

int main(int argc, char *argv[])
{

}
