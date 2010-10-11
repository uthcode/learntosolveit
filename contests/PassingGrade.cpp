/* TopCoder Problem Statement:
 * http://www.topcoder.com/stat?c=problem_statement&pm=1962&rd=4745
 * Definition
    
   Class: PassingGrade
   Method: pointsNeeded
   Parameters: vector <int>, vector <int>, int
   Returns: int
   Method signature: int pointsNeeded(vector <int> pointsEarned, 
                                      vector <int> pointsPossible, int finalExam)
 *  
 *  Algorithm:
 *  1. Addup all pointsPossible and finalExam.
 *  2. Take 0.65 of that total.
 *  3. Subtract pointsEarned from it. Upper of it and return it if less the
 *  value is less than finalExam else return -1
 *
 */

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class PassingGrade {
	public:
		int pointsNeeded(vector<int> pointsEarned, vector<int> pointsPossible,
				int finalExam)
		{
			int total=0,earned=0,required,value;
			vector<int>::iterator iter;
			for(iter=pointsPossible.begin(); iter!=pointsPossible.end(); ++iter)
				total += *iter;
			total += finalExam;
			for(iter=pointsEarned.begin(); iter != pointsEarned.end(); ++iter)
				earned += *iter;
			/* The below is a good way to try idempotency with
			 * float operations. Compare it both ways and settle */
			required = (65*total )/ 100 - earned;
			if (((earned+required) * 100) < (65 * total))
				required++;
			if (required > finalExam)
				return -1;
			else if (required <= 0)
				return 0;
			else
				return required;

		}
};

int main(int argc, char *argv[])
{
	PassingGrade obj;
	vector<int> v1,v2;
	v1.push_back(55);
	v1.push_back(77);
	v1.push_back(82);
	v1.push_back(60);
	v2.push_back(100);
	v2.push_back(100);
	v2.push_back(100);
	v2.push_back(100);
	cout<<obj.pointsNeeded(v1,v2,300);
}

