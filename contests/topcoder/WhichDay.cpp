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

class WhichDay {
public:
    string getDay(vector <string> notOnThisDay) {

        int i = 0;
        string alldays[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday","Saturday"};
        int size = notOnThisDay.size();
        vector<string>::const_iterator it;
        string res;
        for(i = 0; i <= 6; i++) {
            res = alldays[i];
            it = find(notOnThisDay.begin(), notOnThisDay.end(),res);
            if (it == notOnThisDay.end())
                return res;
        }
    }

};
