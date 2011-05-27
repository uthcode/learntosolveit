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
#include <iostream>
#include <numeric>
using namespace std;

int gcd(int a, int b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

int lcm(int a, int b)
{
    int temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

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
int lcmofvectors(vector <int> divisorsminusone)
{
	int result;
	result = accumulate(divisorsminusone.begin(),divisorsminusone.end(),1,lcm);
	return result;
}
class AllButOneDivisor {
public:
    int getMinimum(vector <int> divisors) {
        int res;
	vector <int> copyofdivisors;
	vector <int> answers;
	int i;
	int elem;
	int lcm;
	int found=-1;
	sort(divisors.begin(),divisors.end());
	reverse(divisors.begin(),divisors.end());
	for(i = 0; i<divisors.size();i++)
	{
		copyofdivisors = divisors;
		elem = divisors[i];
		copyofdivisors.erase(copyofdivisors.begin()+i);
		lcm = lcmofvectors(copyofdivisors);
		if ((lcm % elem ) == 0)
			continue;
		else
		{
			answers.push_back(lcm);
			found = 1;
		}
		/** if (found != -1)
			break;
		**/

	}
	if (found != -1)
	{
		sort(answers.begin(),answers.end());
		res = answers[0];
	}
	else
		res = -1;
	//res = found;
        return res;
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        int divisorsARRAY[] = {2,3,5};
        vector <int> divisors( divisorsARRAY, divisorsARRAY+ARRSIZE(divisorsARRAY) );
        AllButOneDivisor theObject;
        eq(0, theObject.getMinimum(divisors),6);
    }
    {
        int divisorsARRAY[] = {2,4,3,9};
        vector <int> divisors( divisorsARRAY, divisorsARRAY+ARRSIZE(divisorsARRAY) );
        AllButOneDivisor theObject;
        eq(1, theObject.getMinimum(divisors),12);
    }
    {
        int divisorsARRAY[] = {3,2,6};
        vector <int> divisors( divisorsARRAY, divisorsARRAY+ARRSIZE(divisorsARRAY) );
        AllButOneDivisor theObject;
        eq(2, theObject.getMinimum(divisors),-1);
    }
    {
        int divisorsARRAY[] = {6,7,8,9,10};
        vector <int> divisors( divisorsARRAY, divisorsARRAY+ARRSIZE(divisorsARRAY) );
        AllButOneDivisor theObject;
        eq(3, theObject.getMinimum(divisors),360);
    }
    {
        int divisorsARRAY[] = {10,6,15};
        vector <int> divisors( divisorsARRAY, divisorsARRAY+ARRSIZE(divisorsARRAY) );
        AllButOneDivisor theObject;
        eq(4, theObject.getMinimum(divisors),-1);
    }
}
// END CUT HERE
