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

class TheBoredomDivTwo {
public:
    int find(int n, int m, int j, int b) {
        int res;
	if ((j + b) <= n)
		res = n;
	else
	{
		if (( j <= n) && (b > n))
			res = n +1;
		if (( b <= n) && (j > n))
			res = n +1;
		if ((j > n)  && (b > n))
			res = n +2;
	}
        return res;
    }

};
