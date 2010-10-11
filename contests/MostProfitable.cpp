/***

Definition
    
Class: MostProfitable
Method: bestItem
Parameters: vector <int>, vector <int>, vector <int>, vector <string>
Returns: string
Method signature: string bestItem(vector <int> costs, vector <int> prices, vector <int> sales, vector <string> items)
(be sure your method is public)

***/
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class MostProfitable {
	public:
		string bestItem(vector <int> costs, vector <int> prices, vector <int> sales, vector <string> items)
		{
			int total,max=0,i,profit=0;
			string result;
			total = costs.size();
			for(i=0; i < total; i++)
			{
				profit = (prices[i] - costs[i]) * sales[i];
				if (profit > max)
				{
					max = profit;
					result = items[i];
				}
			}
			return result;
		}
};
