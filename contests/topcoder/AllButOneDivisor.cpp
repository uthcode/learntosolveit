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
#include <iostream>
#include <numeric>
using namespace std;

int gcd(int a, int b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

int lcm(int a, int b)
{
    int temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

int lcmofvectors(vector <int> divisorsminusone)
{
	int result;
	result = accumulate(divisorsminusone.begin(),divisorsminusone.end(),1,lcm);
	return result;
}

class AllButOneDivisor {
public:
    int getMinimum(vector <int> divisors) {
        int res;
	vector <int> copyofdivisors;
	vector <int> answers;
	int i;
	int elem;
	int lcm;
	int found=-1;
	sort(divisors.begin(),divisors.end());
	reverse(divisors.begin(),divisors.end());
	for(i = 0; i<divisors.size();i++)
	{
		copyofdivisors = divisors;
		elem = divisors[i];
		copyofdivisors.erase(copyofdivisors.begin()+i);
		lcm = lcmofvectors(copyofdivisors);
		if ((lcm % elem ) == 0)
			continue;
		else
		{
			answers.push_back(lcm);
			found = 1;
		}
		/** if (found != -1)
			break;
		**/

	}
	if (found != -1)
	{
		sort(answers.begin(),answers.end());
		res = answers[0];
	}
	else
		res = -1;
	//res = found;
        return res;
    }

};
