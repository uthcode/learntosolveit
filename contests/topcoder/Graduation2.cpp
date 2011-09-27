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

#define CLASSTAKEN 1
#define MAXSIZE 126
#define NOTVISITED -1
#define VISITED -2

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

typedef vector<int> VI;  typedef vector<vector<int> > VVI;
typedef vector<string> VS;  typedef vector<vector<string> > VVS;
typedef signed long long i64;  typedef unsigned long long u64;

int taken[128];

// NOTE: returns -1 for unmatched items.  nm is number of matchable items.
int bipartitematch(const vector<vector<int> > &m, int nm = 128) {
  vector<int> mat(nm, -1), ret(m.size(), -1);
  int i, j, x, y;
  int retn = 0;

  for( i = 0; i < m.size(); i++ ) {
    queue<int> q;
    vector<int> pred(m.size(), -1);
    q.push(i);
    pred[i] = -2;
    while( !q.empty() ) {
      x = q.front(); q.pop();
      for( j = 0; j < m[x].size(); j++ ) if( taken[m[x][j]] ) {
	cout<<m[x][j]<<endl;
        y = mat[m[x][j]];
        if( y == -1 ) goto found;
        if( pred[y] != -1 ) continue;
        pred[y] = x;
        q.push(y);
      }
    }
    continue;
found:  y = m[x][j];
    retn++;
    while( x != -2 ) {
      mat[y] = x;
      swap(ret[x], y);
      x = pred[x];
    }
  }
  return retn;
}

class Graduation {
public:
string moreClasses(string a, vector <string> b) {
  int i, j, k, x, y, z, n;
  string ret = "";
  VVI m;

  for( i = 0; i < b.size(); i++ ) {
    n = atoi(b[i].c_str());
    for( j = 0; j < n; j++ ) {
      m.push_back(VI());
      for( k = 0; k < b[i].size(); k++ ) if( !isdigit(b[i][k]) )
        m.back().push_back(b[i][k]);
    }
  }
  if( m.size() > 128 ) return "0";
  for( i = 0; i < a.size(); i++ ) taken[a[i]] = 1;
  n = m.size()-bipartitematch(m);
  x = 33;
  while( n ) {
    if( x >= 128 ) return "0";
    if( taken[x] ) {x++; continue;}
    taken[x] = 1;
    if (x >= 67)
	    cout<<x;
    z = m.size()-bipartitematch(m);
    if( z == n )
      taken[x] = 0;
    else
      ret += x;
    n = z;
    x++;
  }
  return ret;
}
}; 

int main( int argc, char* argv[] ) {
    {
        string requirementsARRAY[] = {"2ABC","2CDE"};
        vector <string> requirements( requirementsARRAY, requirementsARRAY+ARRSIZE(requirementsARRAY) );
        Graduation theObject;
        eq(0, theObject.moreClasses("A", requirements),"BCD");
    }
    {
        string requirementsARRAY[] = {"3NAMT","2+/","1M"};
        vector <string> requirements( requirementsARRAY, requirementsARRAY+ARRSIZE(requirementsARRAY) );
        Graduation theObject;
        eq(1, theObject.moreClasses("+/NAMT", requirements),"");
    }
    {
        string requirementsARRAY[] = {"100%*Klju"};
        vector <string> requirements( requirementsARRAY, requirementsARRAY+ARRSIZE(requirementsARRAY) );
        Graduation theObject;
        eq(2, theObject.moreClasses("A", requirements),"0");
    }
    {
        string requirementsARRAY[] = {"5ABCDE","1BCDE,"};
        vector <string> requirements( requirementsARRAY, requirementsARRAY+ARRSIZE(requirementsARRAY) );
        Graduation theObject;
        eq(3, theObject.moreClasses("", requirements),",ABCDE");
    }
    {
        string requirementsARRAY[] = {"2AP", "3CDEF", "1CDEFH"};
        vector <string> requirements( requirementsARRAY, requirementsARRAY+ARRSIZE(requirementsARRAY) );
        Graduation theObject;
        eq(4, theObject.moreClasses("CDH", requirements),"AEP");
    }
}
// END CUT HERE
