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

class GuessingNextElement {
public:
    int guess(vector <int> A) {
	int p, q, last, secondlast,n;
        int res;
	p = A[0];
	last = A[A.size()-1];
	secondlast = A[A.size()-2];

	if (last % secondlast == 0)
	{
		n = last / secondlast;
		if ((p * n) == A[1])
			res = last * n;
		else
		{
			n = last - secondlast;
			if ((p + n) == A[1])
				res = last + n;
		}
	}
	else
	{
		n = last - secondlast;
		res = last + n;
	}
        return res;
    }

};
