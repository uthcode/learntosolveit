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
class SlimeXSlimeRancher2 {
public:
    int train(vector <int> attributes) {
        int res;
	sort(attributes.begin(),attributes.end());
	int elem;
	int value;
	value = 0;
	elem = attributes.back();
	vector<int>::iterator it;
	for(it = attributes.begin();it<attributes.end();it++)
		value += abs(*it-elem);

        return value;
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        int attributesARRAY[] = {1,2,3};
        vector <int> attributes( attributesARRAY, attributesARRAY+ARRSIZE(attributesARRAY) );
        SlimeXSlimeRancher2 theObject;
        eq(0, theObject.train(attributes),3);
    }
    {
        int attributesARRAY[] = {5,5};
        vector <int> attributes( attributesARRAY, attributesARRAY+ARRSIZE(attributesARRAY) );
        SlimeXSlimeRancher2 theObject;
        eq(1, theObject.train(attributes),0);
    }
    {
        int attributesARRAY[] = {900,500,100};
        vector <int> attributes( attributesARRAY, attributesARRAY+ARRSIZE(attributesARRAY) );
        SlimeXSlimeRancher2 theObject;
        eq(2, theObject.train(attributes),1200);
    }
}
// END CUT HERE
