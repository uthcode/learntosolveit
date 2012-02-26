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
class PointErasingTwo {
public:
    int getMaximum(vector <int> y) {
        int res;
        return res;
    }

};
// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        int yARRAY[] = { 1, 2, 1, 1, 0, 4, 3 };
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        PointErasingTwo theObject;
        eq(0, theObject.getMaximum(y),2);
    }
    {
        int yARRAY[] = { 0, 1 };
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        PointErasingTwo theObject;
        eq(1, theObject.getMaximum(y),0);
    }
    {
        int yARRAY[] = { 0, 1, 2, 3, 4 };
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        PointErasingTwo theObject;
        eq(2, theObject.getMaximum(y),3);
    }
    {
        int yARRAY[] = { 10, 19, 10, 19 };
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        PointErasingTwo theObject;
        eq(3, theObject.getMaximum(y),0);
    }
    {
        int yARRAY[] = { 0, 23, 49, 50, 32, 0, 18, 50, 0, 28, 50, 27, 49, 0 };
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        PointErasingTwo theObject;
        eq(4, theObject.getMaximum(y),5);
    }
}
// END CUT HERE
