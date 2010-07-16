/**

Definition
    
Class: ProfitCalculator
Method: percent
Parameters: vector <string>
Returns: int
Method signature: int percent(vector <string> items)
(be sure your method is public)
**/
#include<iostream>
#include<sstream>
#include<vector>
#include<string>

using namespace std;

class ProfitCalculator {
	public:
		int percent(vector<string> items)
		{
			int i,total,cost=0,price=0;
			float a,b;
			string eachitem;
			total = items.size();
			for(i=0;i<total;i++)
			{
				eachitem = items[i];
				stringstream(eachitem) >> a >> b;
				price += a;
				cost += b;
			}
			return int(100 * (price-cost)/(price));

		}
};

int main(int argc, char *argv[])
{
	ProfitCalculator obj;
	vector<string> v;
	v.push_back("12.1 21.1");
	v.push_back("14.1 41.1");
	cout<<obj.percent(v);
}
