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
class SlimeXSlimesCity {
public:
    int merge(vector <int> population) {
        int res;
	vector <vector <int> > cycles;
	vector <int> apopulation;
	vector<int>:: iterator it;
	int s;
	int i;
	int j;
	int k;
	int elem;
	s = population.size();
	for (i=0; i < population.size();i++)
		cycles.push_back(population);
	for (i=0; i < population.size();i++)
	{
		j = i;
		apopulation = cycles.at(i);
		for (k =0; k<j; k++)
		{
			elem = apopulation[k];
			apopulation.erase(apopulation.begin() + 1);
			apopulation.push_back(elem);
		}
		cycles[i] = apopulation;

	}
	/**
	for (it = cycles.begin(); it < cycles.end(); it++)
	{
		apopulation = *it;
	}

	**/
        return res;
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        int populationARRAY[] = {2, 3, 4};
        vector <int> population( populationARRAY, populationARRAY+ARRSIZE(populationARRAY) );
        SlimeXSlimesCity theObject;
        eq(0, theObject.merge(population),2);
    }
    {
        int populationARRAY[] = {1, 2, 3};
        vector <int> population( populationARRAY, populationARRAY+ARRSIZE(populationARRAY) );
        SlimeXSlimesCity theObject;
        eq(1, theObject.merge(population),2);
    }
    {
        int populationARRAY[] = {8,2,3,8};
        vector <int> population( populationARRAY, populationARRAY+ARRSIZE(populationARRAY) );
        SlimeXSlimesCity theObject;
        eq(2, theObject.merge(population),2);
    }
    {
        int populationARRAY[] = {1000000000, 999999999, 999999998, 999999997};
        vector <int> population( populationARRAY, populationARRAY+ARRSIZE(populationARRAY) );
        SlimeXSlimesCity theObject;
        eq(3, theObject.merge(population),3);
    }
    {
        int populationARRAY[] = {1,1,1};
        vector <int> population( populationARRAY, populationARRAY+ARRSIZE(populationARRAY) );
        SlimeXSlimesCity theObject;
        eq(4, theObject.merge(population),3);
    }
    {
        int populationARRAY[] = {1, 2, 4, 6, 14, 16, 20};
        vector <int> population( populationARRAY, populationARRAY+ARRSIZE(populationARRAY) );
        SlimeXSlimesCity theObject;
        eq(5, theObject.merge(population),3);
    }
}
// END CUT HERE
