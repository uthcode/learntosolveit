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
class GogoXCake {
public:
    string solve(vector <string> cake, vector <string> cutter) {
        string res="YES";
        vector<string> initial;
        string item="X";
        int row = (int)cake[0].size();
        int col = (int)cake.size();
        for (int i=0; i < col; i++)
        {
            string rowentry="";
            for(int j=0; j < row; j++)
                rowentry += item;
            initial.push_back(rowentry);
        }
        print(initial);
        print(cake);
        print(cutter);
        return res;
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        string cakeARRAY[] = {"X.X"
           ,"..."
           ,"..."
           ,"X.X"};
        vector <string> cake( cakeARRAY, cakeARRAY+ARRSIZE(cakeARRAY) );
        string cutterARRAY[] = {".X"
           ,".."
           ,"X."};
        vector <string> cutter( cutterARRAY, cutterARRAY+ARRSIZE(cutterARRAY) );
        GogoXCake theObject;
        eq(0, theObject.solve(cake, cutter),"YES");
    }
    {
        string cakeARRAY[] = {"..XX"
           ,"...X"
           ,"X..."
           ,"XX.."};
        vector <string> cake( cakeARRAY, cakeARRAY+ARRSIZE(cakeARRAY) );
        string cutterARRAY[] = {".."
           ,".."};
        vector <string> cutter( cutterARRAY, cutterARRAY+ARRSIZE(cutterARRAY) );
        GogoXCake theObject;
        eq(1, theObject.solve(cake, cutter),"NO");
    }
    {
        string cakeARRAY[] = {"...X..."};
        vector <string> cake( cakeARRAY, cakeARRAY+ARRSIZE(cakeARRAY) );
        string cutterARRAY[] = {"..."};
        vector <string> cutter( cutterARRAY, cutterARRAY+ARRSIZE(cutterARRAY) );
        GogoXCake theObject;
        eq(2, theObject.solve(cake, cutter),"YES");
    }
    {
        string cakeARRAY[] = {".X."
           ,"X.X"
           ,".X."};
        vector <string> cake( cakeARRAY, cakeARRAY+ARRSIZE(cakeARRAY) );
        string cutterARRAY[] = {"."};
        vector <string> cutter( cutterARRAY, cutterARRAY+ARRSIZE(cutterARRAY) );
        GogoXCake theObject;
        eq(3, theObject.solve(cake, cutter),"YES");
    }
    {
        string cakeARRAY[] = {"XXXXXXX"
           ,"X.....X"
           ,"X.....X"
           ,"X.....X"
           ,"XXXXXXX"};
        vector <string> cake( cakeARRAY, cakeARRAY+ARRSIZE(cakeARRAY) );
        string cutterARRAY[] = {".X."
           ,"XXX"
           ,".X."};
        vector <string> cutter( cutterARRAY, cutterARRAY+ARRSIZE(cutterARRAY) );
        GogoXCake theObject;
        eq(4, theObject.solve(cake, cutter),"NO");
    }
    {
        string cakeARRAY[] = {".."
           ,"X."
           ,".X"};
        vector <string> cake( cakeARRAY, cakeARRAY+ARRSIZE(cakeARRAY) );
        string cutterARRAY[] = {".."
           ,".X"
           ,"X."};
        vector <string> cutter( cutterARRAY, cutterARRAY+ARRSIZE(cutterARRAY) );
        GogoXCake theObject;
        eq(5, theObject.solve(cake, cutter),"NO");
    }
    {
        string cakeARRAY[] = {"X.."
           ,".XX"
           ,".XX"};
        vector <string> cake( cakeARRAY, cakeARRAY+ARRSIZE(cakeARRAY) );
        string cutterARRAY[] = {".XX"
           ,".XX"
           ,"X.."};
        vector <string> cutter( cutterARRAY, cutterARRAY+ARRSIZE(cutterARRAY) );
        GogoXCake theObject;
        eq(6, theObject.solve(cake, cutter),"NO");
    }
}
// END CUT HERE
