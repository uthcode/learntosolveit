/**

Definition
    
Class: KiwiJuiceEasy
Method: thePouring
Parameters: vector <int>, vector <int>, vector <int>, vector <int>
Returns: vector <int>
Method signature: vector <int> thePouring(vector <int> capacities, vector <int> bottles, vector <int> fromId, vector <int> toId)
(be sure your method is public)

**/

#include<iostream>
#include<vector>
using namespace std;

class KiwiJuiceEasy {
	public:
		vector <int> thePouring(vector <int> capacities, vector <int> bottles, vector <int> fromId, vector <int> toId)
		{
			int i,total,mj,f,t,m,ac,rem;
			total = fromId.size();
			for(i = 0; i <total; i++)
			{
				f = fromId[i];
				t = toId[i];
				mj = bottles[f];
				ac = capacities[t] - bottles[t];

				if (mj <= ac)
				{
					bottles[f] = bottles[f] - mj;
					bottles[t] = bottles[t] + mj;
				}
				else
				{
					bottles[f] = bottles[f] - ac;
					bottles[t] = bottles[t] + ac;

				}
			}
			return bottles;
		}
};
