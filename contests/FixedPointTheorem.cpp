/**

One simple function that does this is the logistic function F(X)=R*X*(1-X) in
the interval [0,1] for certain values of R. For example, if you start with the
value X=.25 and feed it into F to get a new X, then feed that value into F to
get yet another X, and so on, the values of X that are produced will converge
to a small set of values that will eventually repeat forever, called a cycle.
Your program will be given a double R between 0.1 and 3.569 inclusive. Starting
with X=.25, generate the first 200,000 iterations of F using the given value of
R, which will stabilize values of X. Then generate 1000 more values, and return
the range of these values (highest value - lowest value). In other words, you
will be finding the range of the values produced between iterations 200,001 and
201,000 inclusive.

Definition
    
Class: FixedPointTheorem
Method: cycleRange
Parameters: double
Returns: double
Method signature: double cycleRange(double R)

- R will be a value between 0.1 and 3.569 inclusive.
- R will always be a value such that the process stated above will produce a result accurate to 1e-9 (absolute or relative).

Examples
0)
    
0.1
Returns: 0.0
At low numbers, there exists only one point in the cycle, so the answer is 0.0.

1)
    
3.05
Returns: 0.14754098360655865

**/

#include<iostream>
using namespace std;

class FixedPointTheorem {
	public:
		double cycleRange(double R)
		{
			int i;
			double X, high, low,result;
			X=0.25;
			for (i=0;i<200000;i++)
			{
				X = R*X*(1-X);
			}
			high = low = X;
			for(i=0;i<1000;i++)
			{
				X = R*X*(1-X);
				if (X < low) low = X;
				if (X > high) high = X;
			}
			result = (double)high-low;
			return result;
		}
};

int main(int argc, char *argv[])
{
	FixedPointTheorem obj;
	cout<<obj.cycleRange(0.1)<<endl;
	cout<<obj.cycleRange(3.05)<<endl;
}
