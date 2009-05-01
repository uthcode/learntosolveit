
#include<math.h>
#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

class FallingPoints {
	public:
		vector <double> getHeights(vector <int> X, int R) {
			vector <double> ans;
			ans.push_back(0.0);

			for (int i=1; i < (int)X.size(); ++i)
			{
				double x1 = X[i-1], y1=ans[i-1], x2 = X[i];
				double y2;

				if ((x2-x1) * (x2-x1) > R*R)
					ans.push_back(0.0);
				else {
					y2 = sqrt(R*R - (x2-x1) * (x2-x1)) + y1;
					ans.push_back(y2);
				}
			}
			return ans;
		}
};

int main()
{
	FallingPoints fps;
	vector<int> xcords;
	xcords.push_back(0);
	xcords.push_back(10);
	cout << fps.getHeights(xcords,10) <<endl;
}
