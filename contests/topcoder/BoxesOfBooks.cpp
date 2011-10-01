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
class BoxesOfBooks {
public:
    int boxes(vector <int> weights, int maxWeight) {
        int res;
	int num,cur,rem;
	num = weights.size();
	int total=0;
	for(int i=0; i <=num; i++)
	{
		cur = weights[i];
		rem = maxWeight;
		while (cur <= rem)
		{
			rem -= cur;
			i+= 1;
			cur = weights[i];
		}
		total++;
	}

        return total;
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        int weightsARRAY[] = { 5, 5, 5, 5, 5, 5 };
        vector <int> weights( weightsARRAY, weightsARRAY+ARRSIZE(weightsARRAY) );
        BoxesOfBooks theObject;
        eq(0, theObject.boxes(weights, 10),3);
    }
    {
        int weightsARRAY[] = { 51, 51, 51, 51, 51 };
        vector <int> weights( weightsARRAY, weightsARRAY+ARRSIZE(weightsARRAY) );
        BoxesOfBooks theObject;
        eq(1, theObject.boxes(weights, 100),5);
    }
    {
        int weightsARRAY[] = { 1, 1, 1, 7, 7, 7 };
        vector <int> weights( weightsARRAY, weightsARRAY+ARRSIZE(weightsARRAY) );
        BoxesOfBooks theObject;
        eq(2, theObject.boxes(weights, 8),4);
    }
    {
        int weightsARRAY[] = { 12, 1, 11, 2, 10, 3, 4, 5, 6, 6, 1 };
        vector <int> weights( weightsARRAY, weightsARRAY+ARRSIZE(weightsARRAY) );
        BoxesOfBooks theObject;
        eq(3, theObject.boxes(weights, 12),6);
    }
    {
        BoxesOfBooks theObject;
        eq(4, theObject.boxes(vector <int>(), 7),0);
    }
    {
        int weightsARRAY[] = { 20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
             20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
             20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
             20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
             20, 20, 20, 20, 20, 20, 20, 20, 20, 20 };
        vector <int> weights( weightsARRAY, weightsARRAY+ARRSIZE(weightsARRAY) );
        BoxesOfBooks theObject;
        eq(5, theObject.boxes(weights, 1000),1);
    }
}
// END CUT HERE
