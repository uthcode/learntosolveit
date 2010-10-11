/* TopCoder Problem Statement:
 * http://www.topcoder.com/stat?c=problem_statement&pm=1686&rd=4580
 *
 * Class: Quipu
 * Method:readKnots
 * Parameters: string
 * Returns:int
 * Method signature: int readKnots(string knots)
 *
 * */

#include<iostream>
#include<string>
#include<cmath>
#include<vector>

using namespace std;

class Quipu {
	public:
		int readKnots(string knots)
		{
			int c,result=0;
			vector<int> num;
			int digits=0,zeros=0;
			for(c = 1; c <(knots.size()-1);c++)
			{
				switch(knots[c])
				{
					case 'X':
						while(knots[c] == 'X')
						{
							digits++;
							c++;
						}
						num.push_back(digits);
						c--;
						break;
					case '-':
						while(knots[c] == '-')
						{
							zeros++;
							c++;
						}
						zeros -= 1;
						if(zeros!=0)
							while(zeros)
							{
								num.push_back(0);
								zeros--;
							}
						c--;
						break;
				}
				digits=0;
				zeros=0;
			}
			int digit,pos,mul;
			for(int i=0; i < num.size(); i++)
			{
				digit = num[i];
				pos = num.size()-(i+1);
				mul = power(10,pos);
				digit *= mul;
				result += digit;
			}
			return result;

		}
		int power(int base, int exp)
		{
			int p=1;
			while (exp)
			{
				p *= base;
				exp--;
			}
			return p;
		}
};

int main(int argc, char *argv[])
{
	Quipu obj;
	cout<<obj.readKnots("-XX--XXXX-XXX-")<<endl;
}
