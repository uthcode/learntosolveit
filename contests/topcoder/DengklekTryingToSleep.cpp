#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class DengklekTryingToSleep {
public:
    int minDucks(vector <int> ducks) {
        int res=0;
        sort(ducks.begin(), ducks.end());
        int min, max;
        min = ducks[0];
        max = ducks[ducks.size()-1];
        for(int i=min; i<=max;i++)
        {
            if (binary_search(ducks.begin(),ducks.end(),i))
                continue;
            else
                res++;
        }

        return res;
    }

};

