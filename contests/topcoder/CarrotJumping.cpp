/**

Problem Statement: CarrotJumping
    
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
