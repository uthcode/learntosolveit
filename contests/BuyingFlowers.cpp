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
class BuyingFlowers {
public:
    int buy(vector <int> roses, vector <int> lilies) {
        int res;
        return res;
    }

};
// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        int rosesARRAY[] = {2, 4};
        vector <int> roses( rosesARRAY, rosesARRAY+ARRSIZE(rosesARRAY) );
        int liliesARRAY[] = {4, 2};
        vector <int> lilies( liliesARRAY, liliesARRAY+ARRSIZE(liliesARRAY) );
        BuyingFlowers theObject;
        eq(0, theObject.buy(roses, lilies),1);
    }
    {
        int rosesARRAY[] = {2, 7, 3};
        vector <int> roses( rosesARRAY, rosesARRAY+ARRSIZE(rosesARRAY) );
        int liliesARRAY[] = {3, 4, 1};
        vector <int> lilies( liliesARRAY, liliesARRAY+ARRSIZE(liliesARRAY) );
        BuyingFlowers theObject;
        eq(1, theObject.buy(roses, lilies),0);
    }
    {
        int rosesARRAY[] = {4, 5, 2, 1};
        vector <int> roses( rosesARRAY, rosesARRAY+ARRSIZE(rosesARRAY) );
        int liliesARRAY[] = {6, 10, 5, 9};
        vector <int> lilies( liliesARRAY, liliesARRAY+ARRSIZE(liliesARRAY) );
        BuyingFlowers theObject;
        eq(2, theObject.buy(roses, lilies),-1);
    }
    {
        int rosesARRAY[] = {1, 208, 19, 0, 3, 234, 1, 106, 99, 17};
        vector <int> roses( rosesARRAY, rosesARRAY+ARRSIZE(rosesARRAY) );
        int liliesARRAY[] = {58, 30, 3, 5, 0, 997, 9, 615, 77, 5};
        vector <int> lilies( liliesARRAY, liliesARRAY+ARRSIZE(liliesARRAY) );
        BuyingFlowers theObject;
        eq(3, theObject.buy(roses, lilies),36);
    }
}
// END CUT HERE
