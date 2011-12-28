#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;

class LoveCalculator {
public:
    string findBoy(string girl, vector <string> boys) {
        string boyname;
        int L,O,V,E;
        int gL,gO,gV,gE;
        string res;

        sort(boys.begin(), boys.end());

        int probability=0, max= -1;

        gL = count(girl.begin(),girl.end(), 'L');
        gO = count(girl.begin(),girl.end(), 'O');
        gV = count(girl.begin(),girl.end(), 'V');
        gE = count(girl.begin(),girl.end(), 'E');

        for(int i=0; i< boys.size(); i++)
        {
            L = gL; O = gO; V = gV; E = gE;
            boyname = boys[i];
            L += count(boyname.begin(), boyname.end(), 'L');
            O += count(boyname.begin(), boyname.end(), 'O');
            V += count(boyname.begin(), boyname.end(), 'V');
            E += count(boyname.begin(), boyname.end(), 'E');
            probability = ((L+O)*(L+V)*(L+E)*(O+V)*(O+E)*(V+E))%100;

            if (probability > max)
            {
                max = probability;
                res = boyname;
            }
        }
        return res;
    }

};

