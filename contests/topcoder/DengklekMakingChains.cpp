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
#include <regex.h>

using namespace std;

vector<string> split( const string& s, const string& delim =" " ) {
    vector<string> res;
    string t;
    for ( int i = 0 ; i != s.size() ; i++ ) {
        if ( delim.find( s[i] ) != string::npos ) {
            if ( !t.empty() ) {
                res.push_back( t );
                t = "";
            }
        } else {
            t += s[i];
        }
    }
    if ( !t.empty() ) {
        res.push_back(t);
    }
    return res;
}

vector<int> splitInt( const string& s, const string& delim =" " ) {
    vector<string> tok = split( s, delim );
    vector<int> res;
    for ( int i = 0 ; i != tok.size(); i++ )
        res.push_back( atoi( tok[i].c_str() ) );
    return res;
}

// BEGIN CUT HERE
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))

template<typename T> void print( T a ) {
    cerr << a;
}
static void print( long long a ) {
    cerr << a << "L";
}
static void print( string a ) {
    cerr << '"' << a << '"';
}
template<typename T> void print( vector<T> a ) {
    cerr << "{";
    for ( int i = 0 ; i != a.size() ; i++ ) {
        if ( i != 0 ) cerr << ", ";
        print( a[i] );
    }
    cerr << "}" << endl;
}
template<typename T> void eq( int n, T have, T need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}
template<typename T> void eq( int n, vector<T> have, vector<T> need ) {
    if( have.size() != need.size() ) {
        cerr << "Case " << n << " failed: returned " << have.size() << " elements; expected " << need.size() << " elements.";
        print( have );
        print( need );
        return;
    }
    for( int i= 0; i < have.size(); i++ ) {
        if( have[i] != need[i] ) {
            cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
            print( have );
            print( need );
            return;
        }
    }
    cerr << "Case " << n << " passed." << endl;
}
static void eq( int n, string have, string need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}
// END CUT HERE
class DengklekMakingChains {
public:
    string getstring(vector<string> v)
    {
        string s;
        for(int i=0; i<v.size();i++)
        {
            s += v[i];
        }
        return s;
    }

    int maxlen(string s)
    {
        int sum_so_far = 0;
        int maxsum = 0;
        int i=0,num;
        string c;
        string dot(".");
        for(i=0;i<=s.size()-1;i++)
        {
            c = s[i];
            if (c.compare(dot) == 0)
            {
                if (sum_so_far > maxsum)
                    maxsum = sum_so_far;
                sum_so_far = 0;
            }
            else
            {
                c = s[i];
                num = atoi(c.c_str());
                sum_so_far += num;
            }

        }
        return maxsum;
    }

    int maxBeauty(vector <string> chains) {
        int res=0;
        int maxlenout;
        string result;
        sort(chains.begin(),chains.end());

        result = getstring(chains);
        maxlenout = maxlen(result);
        res = maxlenout;
        int left_max=0;
        int middle_total=0;
        int right_max=0;
        string first,last;

        string dot(".");
        string c;

        int num;
        print(chains);

        for (int i=0; i<=chains.size()-1;i++)
        {
            c = chains[i];
            first = c[0];
            last = c[c.size()-1];
            if (first.compare(dot) == 0 && last.compare(dot) != 0)
            {
                num = maxlen(c);
                if (num > left_max)
                    left_max = num;
            }
            if (first.compare(dot) != 0 && last.compare(dot) == 0)
            {
                num = maxlen(c);
                if (num > right_max)
                    right_max = num;
            }
            if (first.compare(dot) != 0 && last.compare(dot) != 0)
            {
                num = maxlen(c);
                middle_total += num;
            }


        }
        res = left_max + right_max + middle_total;

        /**
        while(next_permutation(chains.begin(), chains.end()))
        {
            result = getstring(chains);
            maxlenout = maxlen(result);

            if (maxlenout > res)
                res = maxlenout;
        }
        **/

        return res;
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        string chainsARRAY[] = {".15", "7..", "402", "..3"};
        vector <string> chains( chainsARRAY, chainsARRAY+ARRSIZE(chainsARRAY) );
        DengklekMakingChains theObject;
        eq(0, theObject.maxBeauty(chains),19);
    }
    {
        string chainsARRAY[] = {"..1", "7..", "567", "24.", "8..", "234"};
        vector <string> chains( chainsARRAY, chainsARRAY+ARRSIZE(chainsARRAY) );
        DengklekMakingChains theObject;
        eq(1, theObject.maxBeauty(chains),36);
    }
    {
        string chainsARRAY[] = {"...", "..."};
        vector <string> chains( chainsARRAY, chainsARRAY+ARRSIZE(chainsARRAY) );
        DengklekMakingChains theObject;
        eq(2, theObject.maxBeauty(chains),0);
    }
    {
        string chainsARRAY[] = {"16.", "9.8", ".24", "52.", "3.1", "532", "4.4", "111"};
        vector <string> chains( chainsARRAY, chainsARRAY+ARRSIZE(chainsARRAY) );
        DengklekMakingChains theObject;
        eq(3, theObject.maxBeauty(chains),28);
    }
    {
        string chainsARRAY[] = {"..1", "3..", "2..", ".7."};
        vector <string> chains( chainsARRAY, chainsARRAY+ARRSIZE(chainsARRAY) );
        DengklekMakingChains theObject;
        eq(4, theObject.maxBeauty(chains),7);
    }
    {
        string chainsARRAY[] = {"412", "..7", ".58", "7.8", "32.", "6..", "351", "3.9", "985", "...", ".46"};
        vector <string> chains( chainsARRAY, chainsARRAY+ARRSIZE(chainsARRAY) );
        DengklekMakingChains theObject;
        eq(5, theObject.maxBeauty(chains),58);
    }
}
// END CUT HERE
