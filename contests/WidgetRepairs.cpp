/**

Problem Statement
    
When a widget breaks, it is sent to the widget repair shop, which is capable of
repairing at most numPerDay widgets per day. Given a record of the number of
widgets that arrive at the shop each morning, your task is to determine how
many days the shop must operate to repair all the widgets, not counting any
days the shop spends entirely idle.

For example, suppose the shop is capable of repairing at most 8 widgets per
day, and over a stretch of 5 days, it receives 10, 0, 0, 4, and 20 widgets,
respectively. The shop would operate on days 1 and 2, sit idle on day 3, and
operate again on days 4 through 7. In total, the shop would operate for 6 days
to repair all the widgets.

Create a class WidgetRepairs containing a method days that takes a sequence of
arrival counts arrivals (of type vector <int>) and an int numPerDay, and
calculates the number of days of operation.

Definition
    
Class: WidgetRepairs
Method: days
Parameters: vector <int>, int
Returns: int
Method signature: int days(vector <int> arrivals, int numPerDay)

(be sure your method is public)
    
Constraints

- arrivals contains between 1 and 20 elements, inclusive.
- Each element of arrivals is between 0 and 100, inclusive.
- numPerDay is between 1 and 50, inclusive.

Examples

0)      
{ 10, 0, 0, 4, 20 }
8
Returns: 6
The example above.

1)

    
{ 0, 0, 0 }
10
Returns: 0

2)

    
{ 100, 100 }
10
Returns: 20

3)

    
{ 27, 0, 0, 0, 0, 9 }
9
Returns: 4

4)

    
{ 6, 5, 4, 3, 2, 1, 0, 0, 1, 2, 3, 4, 5, 6 }
3
Returns: 15

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.

**/
#include<vector>
#include<iostream>
using namespace std;

class WidgetRepairs {
	public:
		int days(vector <int> arrivals, int numPerDay)
		{
			int days=0,remainder=0,towork=0;
			vector<int>::iterator iter;
			for(iter=arrivals.begin(); iter!=arrivals.end();++iter)
			{
				towork = *iter + remainder;
				if (towork == 0) continue;
				remainder = towork - numPerDay;
				if (remainder < 0)
					remainder = 0;
				days++;
			}
			while (remainder > 0)
			{
				days++;
				remainder = remainder - numPerDay;
			}
			return days;
		}
};

int main(int argc, char *argv[])
{
	vector <int> arrivals;
	int numPerday=8;
	arrivals.push_back(10);
	arrivals.push_back(0);
	arrivals.push_back(0);
	arrivals.push_back(4);
	arrivals.push_back(20);
	WidgetRepairs obj;
	cout<<obj.days(arrivals,numPerday)<<endl;
}
