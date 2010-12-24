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

class LeaguePicks {
public:
    vector <int> returnPicks(int position, int friends, int picks) {
        vector <int> res;
	int i;
	int pick;
	for (pick = 1; pick <= picks;)
	{
		for (i = 1; i <= friends; i++)
		{
			if (pick > picks)
				break;
			if (i == position)
				res.push_back(pick);
			pick++;
		}
		for (i = friends; i >=1; i--)
		{
			if (pick > picks)
				break;
			if (i == position)
				res.push_back(pick);
			pick++;
		}
	}
        return res;
    }

};
