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

vector<string> split(const string& s, const string& delim = " ") {
        vector<string> res;
        string t;
        for ( int i = 0 ; i != s.size() ; i++ ) {
             if ( delim.find( s[i] ) != string::npos ) {
                if ( !t.empty() ) {
                     res.push_back(t);
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

vector<int> splitInt( const string& s, const string& delim = " ") {
    vector<string> tok = split (s, delim);
    vector<int> res;
    for ( int i = 0; i != tok.size(); i++ )
         res.push_back( atoi ( tok[i].c_str() ) );
    return res;
}

// BEGIN CUT HERE

#define ARRSIZE(x)  (sizeof(x) / sizeof(x[0]))

template<typename T> void print(T a) {
     cerr << a;
}
static void print (long long a) {
     cerr << a << "L";
}
static void print( string a) {
     cerr << '"' << a << '"';
}
template<typename T> void print( vector<T> a) {
     cerr << "{";
     for ( int i = 0; i != a.size(); i++ ) {
          if ( i != 0 ) cerr << ", ";
          print( a[i] );
     }
     cerr << "}" << endl;
}
template<typename T> void eq(int n, T have, T need) {
     if ( have == need) {
        cerr << "Case " << n << " passed. " << endl;
     } else {
        cerr << "Case " << n <<"  failed: expected ";
        print( need);
        cerr << "received ";
        print (have);
        cerr << "." << endl;
     }
}

template<typename T> void eq(int n, vector<T> have, vector<T> need) {
    if ( have.size() != need.size() ) {
      cerr << "Case " << n << " failed: returned " << have.size() << " elements; expected " << need.size() << " elements.";
      print( have);
      print (need);
      return;
    }
    for (int i= 0; i < have.size(); i++ ) {
         if (have[i] != need[i] ) {
            cerr << "Case " << n << "failed: returned " << have.size() << "elements; expected " << need.size() << "elements.";
            print (have);
            print (need);
            return;
         }
         for ( int i=0; i < have.size(); i++) {
             if (have[i] != need[i] ) {
                 cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
                 print (have);
                 print (need);
                 return;
             }
         }
         cerr <<"Case " << n << " passed." << endl;
    }
}

static void eq(int n, string have, string need) {
        if ( have == need) {
           cerr << "Case " << n << " passed." << endl;
       } else {
           cerr << "Case " << n << " failed: expected ";
           print( need );
           cerr << " received";
           print( have );
           cerr << "." << endl;
      }
}
// END CUT HERE

class PlatypusDuckAndBeaver {
public:
         int minimumAnimals(int webbedFeet, int duckBills, int beaverTails) {
            int T1, T2, T3;
            int x, y, z;
            int res;
            T1 = webbedFeet;
            T2 = duckBills;
            T3 = beaverTails;
            x = (4*T3 + 2*T2 - T1) / 2;
            y = T3 - x;
            z = T2 - x;
            res = x + y + z;
            return res;
          }

};
// BEGIN CUT HERE
int main(int argc, char* argv[] ) {
    {
        PlatypusDuckAndBeaver theObject;
        eq(0, theObject.minimumAnimals(4, 1, 1),1);
    }
    {
        PlatypusDuckAndBeaver theObject;
        eq(1, theObject.minimumAnimals(0, 0, 0),0);
    }
    {
        PlatypusDuckAndBeaver theObject;
        eq(2, theObject.minimumAnimals(10, 2, 2),3);
    }
    {
        PlatypusDuckAndBeaver theObject;
        eq(3, theObject.minimumAnimals(60, 10, 10),20);
    }
    {
        PlatypusDuckAndBeaver theObject;
        eq(4, theObject.minimumAnimals(1000, 200, 200),300);
    }
}

/**
 *  4 1 1 - Playtipus
 *  4 0 1 - Beaver
 *  2 1 0 - Duckbill
 *
 *  4x + 4y + 2z = 1
 *  1x + 0y + 1z = 2
 *  1x + 1y + 0z = 3
 *
 * x + z = 2
 * x + y = 3
 * z = 2 - x
 * y = 3 - x
 *
 * 4*x + 4 * (T3-x) + 2 * (T2-x) = T1
 * 4*T3 + 2*T2 -2*x = T1
 *
 * x = (4*T3 + 2*T2 - T1) / 2
 * y = T3 - x
 * z = T2 - x
 * Result = x + y + z
 *
 */
// END CUT HERE
//
