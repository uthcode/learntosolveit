/**

  Class RectangularGrid

**/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class RectangularGrid{

	public:
		long long countRectangles(int width, int height)
		{
			int i=0,j=0;
			long long count=0;
			for (i=1;i<=width;i++)
				for(j=1;j<=width;j++)
				{
					if (i == j)
						continue;
					count += i*j;
				}
			return count;

		}
};

int main(int argc, char *argv[])
{
	RectangularGrid obj;
	cout<<obj.countRectangles(3,3)<<endl;
}
