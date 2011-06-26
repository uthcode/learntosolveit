#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;

class SlimeXSlimeRancher2 {
public:
    int train(vector <int> attributes) {
        int res;
	sort(attributes.begin(),attributes.end());
	int elem;
	int value;
	value = 0;
	elem = attributes.back();
	vector<int>::iterator it;
	for(it = attributes.begin();it<attributes.end();it++)
		value += abs(*it-elem);

        return value;
    }

};
