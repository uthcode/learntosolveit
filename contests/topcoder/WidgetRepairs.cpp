/**

Class: WidgetRepairs

**/
#include<vector>
#include<iostream>
using namespace std;

class WidgetRepairs {
	public:
		int days(vector <int> arrivals, int numPerDay)
		{
			int days=0,remainder=0,towork=0;
			vector<int>::iterator iter;
			for(iter=arrivals.begin(); iter!=arrivals.end();++iter)
			{
				towork = *iter + remainder;
				if (towork == 0) continue;
				remainder = towork - numPerDay;
				if (remainder < 0)
					remainder = 0;
				days++;
			}
			while (remainder > 0)
			{
				days++;
				remainder = remainder - numPerDay;
			}
			return days;
		}
};

int main(int argc, char *argv[])
{
	vector <int> arrivals;
	int numPerday=8;
	arrivals.push_back(10);
	arrivals.push_back(0);
	arrivals.push_back(0);
	arrivals.push_back(4);
	arrivals.push_back(20);
	WidgetRepairs obj;
	cout<<obj.days(arrivals,numPerday)<<endl;
}
