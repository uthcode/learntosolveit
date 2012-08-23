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
#include <stack>

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

class Suminator {
public:
         int findMissing(vector <int> program, int wantedResult) {
            int i;
            int res;
            int elem;
            int top;
            int topminusone;
            stack<int> ss;
            ss.push(0);
            ss.push(0);

            for (i=0; i <= program.size() - 1; i++)
            {
                elem = program[i];
                if (elem == 0)
                {
                    top =  ss.top();
                    ss.pop();
                    topminusone = ss.top();
                    ss.pop();
                    ss.push(top+topminusone);
                }
                else
                {
                    ss.push(elem);
                }
            }

            res = ss.top();

            return res;

          }

};
// BEGIN CUT HERE
int main(int argc, char* argv[] ) {
    {
        int programARRAY[] = {7,-1,0};
        vector <int> program( programARRAY, programARRAY+ARRSIZE(programARRAY) );
        Suminator theObject;
        eq(0, theObject.findMissing(program, 10),3);
    }
    {
        int programARRAY[] = {100, 200, 300, 0, 100, -1};
        vector <int> program( programARRAY, programARRAY+ARRSIZE(programARRAY) );
        Suminator theObject;
        eq(1, theObject.findMissing(program, 600),0);
    }
    {
        int programARRAY[] = {-1, 7, 3, 0, 1, 2, 0, 0};
        vector <int> program( programARRAY, programARRAY+ARRSIZE(programARRAY) );
        Suminator theObject;
        eq(2, theObject.findMissing(program, 13),0);
    }
    {
        int programARRAY[] = {-1, 8, 4, 0, 1, 2, 0, 0};
        vector <int> program( programARRAY, programARRAY+ARRSIZE(programARRAY) );
        Suminator theObject;
        eq(3, theObject.findMissing(program, 16),-1);
    }
    {
        int programARRAY[] = {1000000000, 1000000000, 1000000000,  1000000000, -1, 0, 0, 0, 0};
        vector <int> program( programARRAY, programARRAY+ARRSIZE(programARRAY) );
        Suminator theObject;
        eq(4, theObject.findMissing(program, 1000000000),-1);
    }
    {
        int programARRAY[] = {7, -1, 3, 0};
        vector <int> program( programARRAY, programARRAY+ARRSIZE(programARRAY) );
        Suminator theObject;
        eq(5, theObject.findMissing(program, 3),-1);
    }
}
// END CUT HERE
//
/**
 * 7, -1, 3, 0
 *
 * WantedResult = 3
 *
 * 0 + 7 = 7
 * X
 * [7, x]
 * x+ 3 = 3
 * x = 0
 *
 * {1}
 * [0, 1] -> 1
 * { 5, 0 , 1, 2, 0}
 * [0,5]
 * [5]
 * [5,1]
 * [5,1,2]
 * [5,3] -> 3
 *
 * {7,-1,0}
 * [0,7]
 * [0,7,x]
 * 7+x = 10
 * x = 10 - 7
 *
 * last element -1 two separate logic.
 * Sum of last two == expected result then return 0
 * else return the expected result.
 *
 */
