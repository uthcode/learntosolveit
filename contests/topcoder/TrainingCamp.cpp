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

class TrainingCamp {
public:
    vector <string> determineSolvers(vector <string> attendance, vector <string> problemTopics) {
        vector <string> res;
	vector <string>::iterator it;
	vector <string>::iterator it2;
	string each_string; 
	string each_string2;
	int len_of_string;
	int c;
	string s;
	string s2;
	string s3;
	int pass;

	for(it = attendance.begin(); it < attendance.end(); it++)
	{
		each_string = *it;
		len_of_string = each_string.length();
		s = "";
		for(it2 = problemTopics.begin(); it2 < problemTopics.end(); it2++)
		{
			each_string2 = *it2;
			pass = 1;
			for (c= 0; c < len_of_string; c++)
			{
				if ((each_string[c] == '-' )&& (each_string2[c] == 'X'))
				{
					pass = 0;
					break;
				}

			}
			if (pass == 1)
				s += "X";
			else
				s += "-";
		}
		res.push_back(s);
	}
        return res;
    }

};

int main( int argc, char* argv[] ) {
    {
        string attendanceARRAY[] = {"XXX",
            "XXX",
            "XX-"};
        vector <string> attendance( attendanceARRAY, attendanceARRAY+ARRSIZE(attendanceARRAY) );
        string problemTopicsARRAY[] = {"---",
            "XXX",
            "-XX",
            "XX-"};
        vector <string> problemTopics( problemTopicsARRAY, problemTopicsARRAY+ARRSIZE(problemTopicsARRAY) );
        string retrunValueARRAY[] = {"XXXX", "XXXX", "X--X" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TrainingCamp theObject;
        eq(0, theObject.determineSolvers(attendance, problemTopics),retrunValue);
    }
    {
        string attendanceARRAY[] = {"-XXXX",
            "----X",
            "XXX--",
            "X-X-X"};
        vector <string> attendance( attendanceARRAY, attendanceARRAY+ARRSIZE(attendanceARRAY) );
        string problemTopicsARRAY[] = {"X---X",
            "-X---",
            "XXX--",
            "--X--"};
        vector <string> problemTopics( problemTopicsARRAY, problemTopicsARRAY+ARRSIZE(problemTopicsARRAY) );
        string retrunValueARRAY[] = {"-X-X", "----", "-XXX", "X--X" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TrainingCamp theObject;
        eq(1, theObject.determineSolvers(attendance, problemTopics),retrunValue);
    }
    {
        string attendanceARRAY[] = {"-----",
            "XXXXX"};
        vector <string> attendance( attendanceARRAY, attendanceARRAY+ARRSIZE(attendanceARRAY) );
        string problemTopicsARRAY[] = {"XXXXX",
            "-----",
            "--X-X"};
        vector <string> problemTopics( problemTopicsARRAY, problemTopicsARRAY+ARRSIZE(problemTopicsARRAY) );
        string retrunValueARRAY[] = {"-X-", "XXX" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TrainingCamp theObject;
        eq(2, theObject.determineSolvers(attendance, problemTopics),retrunValue);
    }
    {
        string attendanceARRAY[] = {"-",
            "X",
            "X",
            "-",
            "X"};
        vector <string> attendance( attendanceARRAY, attendanceARRAY+ARRSIZE(attendanceARRAY) );
        string problemTopicsARRAY[] = {"-",
            "X"};
        vector <string> problemTopics( problemTopicsARRAY, problemTopicsARRAY+ARRSIZE(problemTopicsARRAY) );
        string retrunValueARRAY[] = {"X-", "XX", "XX", "X-", "XX" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TrainingCamp theObject;
        eq(3, theObject.determineSolvers(attendance, problemTopics),retrunValue);
    }
    {
        string attendanceARRAY[] = {"X----X--X",
            "X--X-X---",
            "--X-X----",
            "XXXX-X-X-",
            "XXXX--XXX"};
        vector <string> attendance( attendanceARRAY, attendanceARRAY+ARRSIZE(attendanceARRAY) );
        string problemTopicsARRAY[] = {"X----X-X-",
            "-----X---",
            "-X----X-X",
            "-X-X-X---",
            "-----X---",
            "X-------X"};
        vector <string> problemTopics( problemTopicsARRAY, problemTopicsARRAY+ARRSIZE(problemTopicsARRAY) );
        string retrunValueARRAY[] = {"-X--XX", "-X--X-", "------", "XX-XX-", "--X--X" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TrainingCamp theObject;
        eq(4, theObject.determineSolvers(attendance, problemTopics),retrunValue);
    }
}
