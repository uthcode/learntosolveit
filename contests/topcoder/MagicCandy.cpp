// BEGIN CUT HERE

// END CUT HERE

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
class MagicCandy {
public:

    int perfectsqr(int n)
    {
        int m;
        m = sqrt(n);
        if (n == m * m)
            return 1;
        else
            return 0;
    }

    vector<int> resultvector(vector<int> v)
    {
        int i=1;
        vector<int> e=v;
        for (i=v.size(); i >=1;i--)
        {
            if (perfectsqr(i))
                e.erase(e.begin()+i-1);
        }
        return e;

    }
    int whichOne(int n) {
        int res;
        int i;
        vector<int> v;
        for(i=1;i<=n;i++)
            v.push_back(i);

        while (v.size() != 1)
            v = resultvector(v);

        res = v[0];
        return res;
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        MagicCandy theObject;
        eq(0, theObject.whichOne(5),5);
    }
    {
        MagicCandy theObject;
        eq(1, theObject.whichOne(9),7);
    }
    {
        MagicCandy theObject;
        eq(2, theObject.whichOne(20),17);
    }
    {
        MagicCandy theObject;
        eq(3, theObject.whichOne(5265),5257);
    }
    {
        MagicCandy theObject;
        eq(4, theObject.whichOne(20111223),20110741);
    }
    {
        MagicCandy theObject;
        eq(5, theObject.whichOne(1),1);
    }
}
// END CUT HERE
