/* TopCoder Problem Statement:
 * http://www.topcoder.com/stat?c=problem_statement&pm=2923&rd=5854
 *     
 * Class: TallPeople
 * Method: getPeople
 * Parameters: vector <string>
 * Returns: vector <int>
 * Method signature: vector <int> getPeople(vector <string> people)
 * (be sure your method is public)
 *
 */

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<sstream>

using namespace std;

class TallPeople {
	public:
		vector<int> getPeople(vector<string> people)
		{
			vector<int> heights,result;
			vector<vector<int> > p;
			string joined,heights_str;
			int i,j,n,r,c, tallest,shortest;
			vector<int> tallest_in_col, shortest_in_row;

			vector<string>::iterator iter;

			r = people.size();

			for(iter=people.begin(); iter!=people.end(); ++iter)
			{
				heights_str = *iter;
				
				joined.clear();
				for(i=0; i < heights_str.size(); i++)
					joined += heights_str[i];

				istringstream str_of_numbers(joined);

				heights.clear();
				while(str_of_numbers >> n)
				{
					heights.push_back(n);
				}
				
				p.push_back(heights);
				c = heights.size();
			}

			/* just operate on p */
			for (i = 0; i < r ; i++)
			{
				shortest = 1000000;
				for (j = 0; j < c; j++)
					if (p[i][j] < shortest)
						shortest = p[i][j];
				shortest_in_row.push_back(shortest);
			}
			sort(shortest_in_row.begin(), shortest_in_row.end());
			result.push_back(shortest_in_row[shortest_in_row.size()-1]);

			for (j = 0; j < c; j++)
			{
				tallest = 0;
				for (i = 0; i < r ; i++)
					if (p[i][j] > tallest)
						tallest = p[i][j];
				tallest_in_col.push_back(tallest);
			}
			sort(tallest_in_col.begin(), tallest_in_col.end());
			result.push_back(tallest_in_col[0]);

			return result;
		
		}
};

int main(int argc, char *argv[])
{
	TallPeople obj;
	vector<string> rc;
	vector<int> v1;
	rc.push_back("9 2 3");
	rc.push_back("4 8 7");
	v1 = obj.getPeople(rc);

	for (int i=0; i < v1.size(); i++)
		cout<<v1[i]<<endl;
}
