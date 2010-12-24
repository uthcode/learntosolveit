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
class MonotoneSequence {
public:
    int longestMonotoneSequence(vector <int> seq) {
        int res,i;
	int longest=1;
	int longdec=1,longinc=1;
	int len;
	len = seq.size();
	int num;
	int prev=-1;
	num = seq[0];
	for(i = 1; i < len; i++)
	{
		if ((longinc > longest) || (longdec > longest))
		{
			if (longinc >= longdec)
				longest = longinc;
			else
				longest = longdec;
		}

		if (seq[i] > num)
		{
			longdec = 0;
			if (prev == -1 || prev == 1)
			{
				longinc++;
			}
			else
			{
				longinc= 1;
			}
			prev = 1;
			num = seq[i];
		}
		if (seq[i] < num)
		{
			longinc = 0;
			if (prev == -1 || prev == 0)
			{
				longdec++;
			}
			else
			{
				longdec=1;
			}
			prev = 0;
			num = seq[i];
		}
	}

	res = longest;

        return res;
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        int seqARRAY[] = {1, 7, 7, 8, 3, 6, 7, 2};
        vector <int> seq( seqARRAY, seqARRAY+ARRSIZE(seqARRAY) );
        MonotoneSequence theObject;
        eq(0, theObject.longestMonotoneSequence(seq),3);
    }
    {
        int seqARRAY[] = {1, 1, 1, 1, 1};
        vector <int> seq( seqARRAY, seqARRAY+ARRSIZE(seqARRAY) );
        MonotoneSequence theObject;
        eq(1, theObject.longestMonotoneSequence(seq),1);
    }
    {
        int seqARRAY[] = {10, 20, 30, 25, 20, 19, 20, 18, 23};
        vector <int> seq( seqARRAY, seqARRAY+ARRSIZE(seqARRAY) );
        MonotoneSequence theObject;
        eq(2, theObject.longestMonotoneSequence(seq),4);
    }
    {
        int seqARRAY[] = {3, 2, 1, 4};
        vector <int> seq( seqARRAY, seqARRAY+ARRSIZE(seqARRAY) );
        MonotoneSequence theObject;
        eq(3, theObject.longestMonotoneSequence(seq),3);
    }
}
// END CUT HERE
