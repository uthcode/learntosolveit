#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

class MagicStonesStore {
public:

    int isprime(int n)
    {
        if (n <=1)
            return 0;
        if (n == 2)
            return 1;
        if (n%2 == 0)
            return 0;
        int m = sqrt(n);

        for (int i=3; i<=m; i+=2)
            if (n%i == 0)
                return 0;
        return 1;
    }

    string ableToDivide(int n) {
        string res;
        if (isprime(n))
            return "YES";
        else
        {
            int m = 2*n;
            for (int i = 2; i <m; i++)
                if (isprime(i) && isprime(m-i))
                    return "YES";
        }
            return "NO";
    }

};
