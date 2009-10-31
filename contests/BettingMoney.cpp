/* Topcoder Problem Statement:
 * http://www.topcoder.com/stat?c=problem_statement&pm=2297&rd=4775
 *
 * Definition:
 *
 * Class:	BettingMoney
 * Method:	moneyMade
 * Parameters:	vector<int>, vector<int>, int
 * Returns:	int
 * Method signature:	int moneyMade(vector<int> amounts,vector<int> centsPerDollar, int finalResult)
 */

#include<iostream>
#include<vector>

using namespace std;

class BettingMoney {
	public:
		int moneyMade(vector<int> amounts, vector<int> centsPerDollar, int finalResult)
		{
			int netgain=0;
			int resAmount, resCentsPerDollar;
			resAmount = amounts[finalResult];
			resCentsPerDollar = centsPerDollar[finalResult];
			for (int i=0; i < amounts.size() ; i++)
			{
				if (i == finalResult)
					continue;
				netgain += amounts[i];
			}

			netgain = (netgain*100) - (resAmount * resCentsPerDollar);
			return netgain;
		}
};

int main(int argc, char *argv[])
{
	BettingMoney obj;
	vector<int> v1, v2;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);

	v2.push_back(20);
	v2.push_back(30);
	v2.push_back(40);

	int finalResult=1;
	cout<<obj.moneyMade(v1,v2,finalResult);

}
