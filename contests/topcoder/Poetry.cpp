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
class Poetry {
public:
    string rhymeScheme(vector <string> poem) {
        vector <string>::iterator string_it;
        string res, line, empty_line;
        string word;
        string::iterator ec;
        map<string,string> rhymes;
        res = "";
        string chars_in_poem = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int current_char = 0;
        int blank_line = 1;

        for(string_it = poem.begin(); string_it != poem.end(); string_it++)
        {
            line = (*string_it);
            
            /* lower case it */

            transform(line.begin(),line.end(),line.begin(),::tolower);
        
            /* check blank line */

            empty_line = line;
            empty_line.erase(std::remove_if(empty_line.begin(), empty_line.end(), (int(*)(int))isspace), empty_line.end());
            if (empty_line.size() == 0)
            {
                res += " ";
                continue;
            }

            /* remove spaces (trailing) and first y */

            word = find_word(line);
            word.erase(std::remove_if(word.begin(), word.end(), (int(*)(int))isspace), word.end());
            if (word[0] == 'y')
                word = word.substr(1);

            /**
             * The idea is form the dictionary of the rhymes and fetch from the
             * dictionary if the rhyme already exist, if not add to the
             * dictionary for the new rhyme created according to the rule.
             */

            if (rhymes.count(word) > 0)
                res += rhymes[word];
            else
            {
                rhymes[word] += chars_in_poem[current_char];
                res += chars_in_poem[current_char];
                current_char++;
            }
        }
        return res;
    }

    string find_word(string line)
    {
        // find the last contiguous vowels
        string::iterator c;
        int v;
        int len = line.size();
        int found = 0;
        string sub_str;
        for(c= line.end()-1; c != line.begin(); --c)
        {
            v = *c;
            if ( (v == 'y' && (c != line.begin() || c != line.end()-1)) || v == 'a' || v == 'e' || v == 'i' || v == 'o' || v == 'u')
            {
                len -= 1;
                found = 1;
            }
            else
            {
                if (found == 0)
                {
                    len -= 1;
                }
                else 
                    break;
            }
        }

        sub_str = line.substr(len);
        return sub_str;
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        string poemARRAY[] = {"problem",
            "anotherproblem",
            "this stupid haiku"};
        vector <string> poem( poemARRAY, poemARRAY+ARRSIZE(poemARRAY) );
        Poetry theObject;
        eq(0, theObject.rhymeScheme(poem),"aab");
    }
    {
        string poemARRAY[] = {"I hope this problem",
            "is a whole lot better than",
            "this stupid haiku"};
        vector <string> poem( poemARRAY, poemARRAY+ARRSIZE(poemARRAY) );
        Poetry theObject;
        eq(0, theObject.rhymeScheme(poem),"abc");
    }

    {
        string poemARRAY[] = {"     ",
            "Measure your height",
            "AND WEIGHT      ",
            "said the doctor",
            "",
            "And make sure to take your pills",
            "   to   cure   your    ills",
            "Every",
            "DAY"};
        vector <string> poem( poemARRAY, poemARRAY+ARRSIZE(poemARRAY) );
        Poetry theObject;
        eq(1, theObject.rhymeScheme(poem)," aab ccde");
    }
    {
        string poemARRAY[] = {"One bright day in the middle of the night",
            "Two dead boys got up to fight",
            "Back to back they faced each other",
            "Drew their swords and shot each other",
            "",
            "A deaf policeman heard the noise",
            "And came to arrest the two dead boys",
            "And if you dont believe this lie is true",
            "Ask the blind man he saw it too"};
        vector <string> poem( poemARRAY, poemARRAY+ARRSIZE(poemARRAY) );
        Poetry theObject;
        eq(2, theObject.rhymeScheme(poem),"aabb cdef");
    }
    {
        string poemARRAY[] = {"",
            "",
            "",
            ""};
        vector <string> poem( poemARRAY, poemARRAY+ARRSIZE(poemARRAY) );
        Poetry theObject;
        eq(3, theObject.rhymeScheme(poem),"    ");
    }
    {
        string poemARRAY[] = {"This poem has uppercase letters",
            "In its rhyme scheme",
            "Alpha", "Blaster", "Cat", "Desert", "Elephant", "Frog", "Gulch", 
            "Horse", "Ireland", "Jam", "Krispy Kreme", "Loofah", "Moo", "Narf",
            "Old", "Pink", "Quash", "Rainbow", "Star", "Tour", "Uvula", "Very",
            "Will", "Xmas", "Young", "Zed", "deception", "comic", "grout",
            "oval", "cable", "rob", "steal", "steel", "weak"};
        vector <string> poem( poemARRAY, poemARRAY+ARRSIZE(poemARRAY) );
        Poetry theObject;
        eq(4, theObject.rhymeScheme(poem),"abcdefghibjkblmnopqrstcuvwxyzABCbDEFG");
    }
    {
        string poemARRAY[] = {" ",
            "     ",
            "This poem",
            "         ",
            " ",
            " ",
            "",
            "Has lots of blank lines",
            " ",
            "      ",
            "                                            ",
            "         ",
            " ",
            "              ",
            "                                                  ",
            "  in      it           "};
        vector <string> poem( poemARRAY, poemARRAY+ARRSIZE(poemARRAY) );
        Poetry theObject;
        eq(5, theObject.rhymeScheme(poem),"  a    b       c");
    }
    {
        string poemARRAY[] = {"too bad   your",
            "     solution went   sour"};
        vector <string> poem( poemARRAY, poemARRAY+ARRSIZE(poemARRAY) );
        Poetry theObject;
        eq(6, theObject.rhymeScheme(poem),"aa");
    }

}
