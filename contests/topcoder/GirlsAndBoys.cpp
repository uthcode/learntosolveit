/***

Problem Statement: GirlsAndBoys
    

Algorithm:
1. Imitate bubble sort.
2. Two loops and in the inner loop, count the swaps for boys and girls.
2. Whoever is lesser their swap number will be the result.
***/

#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>

using namespace std;

class  GirlsAndBoys{
	public:
		// method name
		int sortThem(string row)
		{
			int i=0,j=0,b=0,g=0;
			for(i=0; i < row.size(); i++)
				for(j = 0; j < i; j++)
				{
					b += row[i] < row[j];
					g += row[i] > row[j];
				}
			return b < g? b:g;
		}
};

int main(int argc, char *argv[])
{
	GirlsAndBoys obj;
	cout<<obj.sortThem("BBGGGGGB");
}
