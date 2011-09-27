#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;

class TwiceString {
public:
    string getShortest(string s) {
        string res, check, temp;
        temp = s + s;
        res = temp;
        size_t found;
        int startpos = s.size();
        for (int i = 1; i <= s.size()-1; i++)
        {
            check = temp;
            check.erase(startpos,i);
            found = check.find(s,1);
            if (found != string::npos)
                res = check;
        }

        return res;
    }

};
