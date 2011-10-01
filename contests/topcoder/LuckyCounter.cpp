#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;

class LuckyCounter {
public:
    int countLuckyMoments(vector <string> moments) {
        int res=0;
	int num = moments.size();
	string each;
	string a1,a2,b1,b2;
	for(int i=0;i<num;i++)
	{
		a1 = moments[i].substr(0,1);
		a2 = moments[i].substr(1,1);
		b1 = moments[i].substr(3,1);
		b2 = moments[i].substr(4,1);

		if ( ( (a1 == a2) && (b1 == b2)) || ((a1 == b1) && (a2 == b2)) || ((a1 == b2) && (a2 == b1)))
			res++;
	}
        return res;
    }

};
