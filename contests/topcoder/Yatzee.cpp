/* TopCoder Problem Statement:
 * http://www.topcoder.com/stat?c=problem_statement&pm=1692&rd=4535
 *

   Class: YahtzeeScore
   Method: maxPoints
   Parameters: vector <int>
   Returns: int
   Method signature: int maxPoints(vector <int> toss)
 *
 * Solution:
 * Use count and unique from algorithm
 *
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;


class YahtzeeScore {
	public:
		int maxPoints(vector <int> toss)
		{
			set<int> elements(toss.begin(), toss.end());
			set<int>::iterator set_iter;
			int value,count_times;
			int max = 0;
			for (set_iter = elements.begin(); set_iter != elements.end(); ++set_iter)
			{
				value = *set_iter;
				count_times = (int)count(toss.begin(), toss.end(), value);
				if ((count_times * value) > max)
					max = count_times * value;
			}

			return max;

		}
};

int main(int argc, char *argv[])
{
	YahtzeeScore obj;
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(10);
	v1.push_back(10);
	cout<<obj.maxPoints(v1);
}


