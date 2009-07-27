#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class TheNewHouseDivTwo{
	public:
		int count(vector <int> x, vector <int> y)
		{
			int xmin,xmax,ymin,ymax;
			vector <int> temp;
			int count;

			temp = x;
			sort(temp.begin(), temp.end());
			xmin = temp[0];
			xmax = temp[temp.size()-1];

			temp = y;
			sort(temp.begin(), temp.end());
			ymin = temp[0];
			ymax = temp[temp.size()-1];

			int i,j;
			for (i = xmin; i <=xmax; i++)
				for (j = ymin; j <=ymax; j++)
				{
					//if i in x and j in y:

				}
		}

};

int main(int argc, char *argv[])
{
	TheNewHouseDivTwo obj;
	vector <int>x;
	vector <int>y;
	x.push_back(0);
	x.push_back(3);
	x.push_back(1);
	x.push_back(2);
	y.push_back(0);
	y.push_back(3);
	y.push_back(1);
	y.push_back(2);
	obj.count(x,y);
}


