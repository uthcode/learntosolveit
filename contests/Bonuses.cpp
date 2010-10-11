/**

Problem Statement
    
You have a certain amount of money to give out as a bonus to employees. The
trouble is, who do you pick to receive what bonus? You decide to assign a
number of points to each employee, which corresponds to how much they helped
the company in the last year. You are given an vector <int> points, where each
element contains the points earned by the corresponding employee (i.e.
points[0] is the number of points awarded to employee 0). Using this, you are
to calculate the bonuses as follows:

- First, add up all the points, this is the pool of total points awarded. -
Each employee gets a percentage of the bonus money, equal to the percentage of
the point pool that the employee got. 

- Employees can only receive whole percentage amounts, so if an employee's cut
of the bonus has a fractional percentage, truncate it. 

- There may be some percentage of bonus left over (because of the fractional
truncation). If n% of the bonus is left over, give the top n employees 1% of
the bonus. There will be no more bonus left after this. If two or more
employees with the same number of points qualify for this "extra" bonus, but
not enough bonus is left to give them all an extra 1%, give it to the employees
that come first in points.

The return value should be a vector <int>, one element per employee in the
order they were passed in. Each element should be the percent of the bonus that
the employee gets.

Definition
    
Class: Bonuses
Method: getDivision
Parameters: vector <int>
Returns: vector <int>
Method signature: vector <int> getDivision(vector <int> points)
(be sure your method is public)
    
Constraints
- points will have between 1 and 50 elements, inclusive.
- Each element of points will be between 1 and 500, inclusive.

Examples
0)

{1,2,3,4,5}
Returns: { 6,  13,  20,  27,  34 }

The total points in the point pool is 1+2+3+4+5 = 15. Employee 1 gets 1/15 of
the total pool, or 6.66667%, Employee 2 gets 13.33333%, Employee 3 gets 20%
(exactly), Employee 4 gets 26.66667%, and Employee 5 gets 33.33333%. After
truncating, the percentages look like: {6,13,20,26,33} Adding up all the
fractional percentages, we see there is 2% in extra bonuses, which go to the
top two scorers. These are the employees who received 4 and 5 points.

1)

    
{5,5,5,5,5,5}
Returns: { 17,  17,  17,  17,  16,  16 }

The pool of points is 30. Each employee got 1/6 of the total pool, which
translates to 16.66667%. Truncating for all employees, we are left with 4% in
extra bonuses. Because everyone got the same number of points, the extra 1%
bonuses are assigned to the four that come first in the array.

2)

    
{485, 324, 263, 143, 470, 292, 304, 188, 100, 254, 296,
 255, 360, 231, 311, 275,  93, 463, 115, 366, 197, 470}

Returns: 
{ 8,  6,  4,  2,  8,  5,  5,  3,  1,  4,  5,  4,  6,  3,  5,  4,  1,  8,
  1,  6,  3,  8 }

This problem statement is the exclusive and proprietary property of TopCoder,
     Inc. Any unauthorized use or reproduction of this information without the
     prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003,
     TopCoder, Inc. All rights reserved.

**/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Bonuses {
	public:
		vector <int> getDivision(vector <int> points)
		{
			int count;
			int i;
			int total = 0;
			count = (int)points.size();
			for(i=0; i< count; ++i)
				total = total + points[i];

			vector <int> ans;
			for(i = 0; i < count ; ++i)
			{
				int share = ((points[i] * 1.0)/ total) * 100;
				ans.push_back(share);
			}

			int distributed = 0;

			for(i = 0; i< count ; ++i)
				distributed += ans[i];

			int remaining = 100 - distributed;

			//cout<<remaining<<"points remaining"<<endl;

			vector <int> sortedans;
			sortedans = ans;
			stable_sort(sortedans.begin(), sortedans.end());

			int topscorers[remaining];
			int j =0;
			int scoredistribution = remaining;

			for(i=int(sortedans.size())-1;scoredistribution>=0; --i, --scoredistribution)
				topscorers[j++] = sortedans[i];

			//for(i=0; i<remaining;++i)
				//cout<<topscorers[i]<<endl;
			int toassign = 0;

			for(i=0; i< remaining;++i)
			{
				toassign = topscorers[i];
				for(j=0;j < (int)ans.size();++j)
					if (ans[j] == toassign)
					{
						ans[j] += 1;
						break;
					}
			}
			return ans;
		}

};

int main()
{
	Bonuses bon;
	vector <int> pointstopass;
	vector <int> answer;
	pointstopass.push_back(5);
	pointstopass.push_back(5);
	pointstopass.push_back(5);
	pointstopass.push_back(5);
	pointstopass.push_back(5);
	pointstopass.push_back(5);
	/**
	pointstopass.push_back(5);
	pointstopass.push_back(4);
	pointstopass.push_back(3);
	pointstopass.push_back(4);
	pointstopass.push_back(2);
	pointstopass.push_back(4);
	pointstopass.push_back(1);
	**/
	answer = bon.getDivision(pointstopass);
	for(int i=0; i<(int)answer.size(); ++i)
		cout<<answer[i]<<endl;
}
