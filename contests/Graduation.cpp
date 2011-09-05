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

int taken[MAXSIZE];

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

int bipartitematch(const vector <vector <int> > &set_of_requirements)
{

    int q_item;
    int retn = 0;
    int path, classindex;
    int class_value;

    int size_of_requirements = set_of_requirements.size();

    vector <int> source(MAXSIZE, NOTVISITED);
    vector <int> target(size_of_requirements, NOTVISITED);

    for (int elem = 0; elem < size_of_requirements; elem++)
    {
        queue<int> q_of_elements;
        q_of_elements.push(elem);

        vector<int> previous(size_of_requirements, NOTVISITED);

        previous[elem] = VISITED;

        while (!q_of_elements.empty())
        {
            q_item = q_of_elements.front(); q_of_elements.pop();

            for (classindex = 0; classindex < set_of_requirements[q_item].size(); classindex++)
            {
                class_value =  set_of_requirements[q_item][classindex];

                if (taken[class_value])
                {
                    // Augumenting path logic.
                    //
                    if (source[class_value] == NOTVISITED)
                        goto found;

                    path = source[class_value];

                    if (previous[path] == NOTVISITED)
                    {
                        // This is BFS.
                        // Similar to kho-kho game.
                        previous[path] = q_item;
                        q_of_elements.push(path);
                    }
                    else 
                        continue;
                }
            }
        }
        continue;
        found:
            path = set_of_requirements[q_item][classindex];
            retn++;
            while (q_item != VISITED)
            {
                source[path] = q_item;
                swap(target[q_item], path);
                //target[q_item] = path;
                q_item = previous[q_item];
            }

    }

    return retn;
}

class Graduation {
public:
    string moreClasses(string classesTaken, vector <string> requirements) {
        vector <vector <int> > m; // [[], [], []]
        int remaining, paths;
        int nextclass;
        string res="";

        for (int ct=0; ct<classesTaken.size(); ct++)
            taken[classesTaken[ct]] = CLASSTAKEN;

        for (int i=0; i<requirements.size(); i++)
        {
            int num = atoi(requirements[i].c_str());
            for (int choice=0; choice < num; choice++)
            {
                m.push_back(vector<int>());
                for (int j=0; j < requirements[i].size(); j++)
                    if (isalpha(requirements[i][j]))
                        m.back().push_back(requirements[i][j]);
            }
        }

        if (m.size() > MAXSIZE) return "0";

        remaining = m.size() - bipartitematch(m);

        nextclass = 33;
        
        while (remaining)
        {
            if (nextclass >= MAXSIZE) return "0";

            if (taken[nextclass])
            {
                nextclass++;
                continue;
            }
            taken[nextclass] = 1;

            paths = m.size() - bipartitematch(m);

            if (paths == remaining)
                taken[nextclass] = 0;
            else
            {
                res += nextclass;
                remaining = paths;
            }
            nextclass++;
        }

        return res;
    }

};
// BEGIN CUT HERE
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
