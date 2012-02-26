#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;

class GogoXBallsAndBinsEasy {
public:
    int solve(vector <int> T) {
        int res=0;
        int count, totalcount;
        int elem;
        vector <int> PT = T;
        do {
            count = 0;
            totalcount = 0;
            for(elem = 0; elem <= (int)PT.size()-1; elem++)
            {
                if (PT[elem] > T[elem])
                {
                    count = PT[elem] - T[elem];
                    totalcount += count;
                }
            }
            if (totalcount > res)
                res = totalcount;
        }
        while(next_permutation(PT.begin(), PT.end()));
        
        return res;
    }

};
