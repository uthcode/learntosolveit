#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class ImportantTasks
{
	public:
		int maximalCost(vector <int> complexity, vector <int> computers)
		{
			sort(complexity.begin(), complexity.end());
			sort(computers.begin(), computers.end());
			int count=0;
			for (int i=0; i < computers.size(); i++)
				for (int j=0; j< complexity.size(); j++)
					if (complexity[j] <= computers[i])
					{
						count++;
						complexity[j] = 1000001;
						break;
					}
			return count;
		}
};
