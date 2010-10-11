/* TopCoder Problem on Euclidean distance.
 * Not Solved.
 */

#include<iostream>
#include<cmath>
using namespace std;

class NotTwo {
	public:
		int maxStones(int width, int height)
		{
			int x1,x2,y1,y2;
			int stones;

			for(x1=0,y1=0; ((x1<(width-1)) || (y1<(height-1)));x1++,y1++)
				for(x2=0,y2=0; (x2<(width-1) || (y2<(height-1))); x2++,y2++)
					continue;


			return stones;

		}
};

int main(int argc, char *argv[])
{
	NotTwo obj;
	cout<<obj.maxStones(2,2)<<endl;

}

