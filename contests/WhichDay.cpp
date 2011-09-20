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
class WhichDay {
public:
    string getDay(vector <string> notOnThisDay) {

        int i = 0;
        string alldays[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday","Saturday"};
        int size = notOnThisDay.size();
        vector<string>::const_iterator it;
        string res;
        for(i = 0; i <= 6; i++) {
            res = alldays[i];
            it = find(notOnThisDay.begin(), notOnThisDay.end(),res);
            if (it == notOnThisDay.end())
                return res;
        }
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        string notOnThisDayARRAY[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
        vector <string> notOnThisDay( notOnThisDayARRAY, notOnThisDayARRAY+ARRSIZE(notOnThisDayARRAY) );
        WhichDay theObject;
        eq(0, theObject.getDay(notOnThisDay),"Saturday");
    }
    {
        string notOnThisDayARRAY[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Friday", "Thursday"};
        vector <string> notOnThisDay( notOnThisDayARRAY, notOnThisDayARRAY+ARRSIZE(notOnThisDayARRAY) );
        WhichDay theObject;
        eq(1, theObject.getDay(notOnThisDay),"Saturday");
    }
    {
        string notOnThisDayARRAY[] = {"Sunday", "Monday", "Tuesday", "Thursday", "Friday", "Saturday"};
        vector <string> notOnThisDay( notOnThisDayARRAY, notOnThisDayARRAY+ARRSIZE(notOnThisDayARRAY) );
        WhichDay theObject;
        eq(2, theObject.getDay(notOnThisDay),"Wednesday");
    }
    {
        string notOnThisDayARRAY[] = {"Sunday", "Friday", "Tuesday", "Wednesday", "Monday", "Saturday"};
        vector <string> notOnThisDay( notOnThisDayARRAY, notOnThisDayARRAY+ARRSIZE(notOnThisDayARRAY) );
        WhichDay theObject;
        eq(3, theObject.getDay(notOnThisDay),"Thursday");
    }
}
// END CUT HERE
