/***

Problem Statement
    
You are a student advisor at TopCoder University (TCU). The graduation
requirements at TCU are somewhat complicated. Each requirement states that a
student must take some number of classes from some set, and all requirements
must be satisfied for a student to graduate. Each class is represented as a
single distinct character. For example, one requirement might be "Take any 2
classes of B, C, D, or F." Further complicating the matter is the fact that no
class can be used to satisfy more than one requirement. And so students come to
you all the time, dazed and confused, because they don't know how close they
are to satisfying the requirements so that they can graduate!

Each class is represented as a distinct single character whose ASCII value is
between 33 and 126, inclusive, but is also not a numeric character ('0'-'9').
You will be given a string classesTaken, which represents the classes that a
given student has taken. You will also be given a vector <string> requirements,
which lists the requirements needed to graduate. Each string in requirements
will start with a positive integer, followed by some number of classes. For
example, the requirement "Take any 2 classes from B, C, D, or F" would be
represented in requirements as "2BCDF".

Your method should return a String representing the classes that the student
needs to take in order to graduate, in ASCII order. Classes may not be taken
more than once. If there is more than one set that will allow the student to
graduate, return the smallest set. If there are multiple smallest sets, return
the lexicographically smallest of these. Finally, if there is no set that will
enable this student to graduate, return "0".

Definition
    
Class: Graduation
Method: moreClasses
Parameters: string, vector <string>
Returns: string
Method signature:

string moreClasses(string classesTaken, vector <string> requirements)
	    
Notes

	- Classes may not be taken more than once.

Constraints

- classesTaken will be between 0 and 50 characters in length, inclusive.
- each character in classesTaken will be a valid class (ASCII value between 33
to 126 inclusive and not a digit).

- there will be no duplicate classes in classesTaken.

- requirements will contain between 1 and 50 elements, inclusive.

- each element of requirements will contain a positive integer with no leading
zeros between 1 and 100, inclusive, followed by some number of valid classes.

- each element of requirements will be between 1 and 50 characters in length, inclusive.

- there will be no duplicate classes in any given element of requirements

Examples

0) 

"A"
{"2ABC","2CDE"}

Returns: "BCD"

The student must take two classes from {A,B,C}, and two from {C,D,E}. He has already taken A.

1)
"+/NAMT"
{"3NAMT","2+/","1M"}
Returns: ""

The student has already fulfilled all the requirements - you should congratulate him for his achievement!

2)
"A"
{"100%*Klju"}
Returns: "0"
No matter how hard you try, you can't take 100 classes out of 6. TCU had better fix their policies quick.

3)
""
{"5ABCDE","1BCDE,"}
Returns: ",ABCDE"

4)
"CDH"
{"2AP", "3CDEF", "1CDEFH"}

Returns: "AEP"

	This problem statement is the exclusive and proprietary property of
	TopCoder, Inc. Any unauthorized use or reproduction of this information
	without the prior written consent of TopCoder, Inc. is strictly
	prohibited. (c)2003, TopCoder, Inc. All rights reserved.
**/

#include <vector>
#include <iostream>
#include <typeinfo>
#include <cstdlib>
#include <stdio.h>
#include <ctype.h>
#include <queue>

#define MAXSIZE 127
#define VISITED -2
#define NOTVISITED -1
#define CLASSTAKEN 1

using namespace std;

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

// Do we need 128? The ascii values are between 33 and 126.

int taken[MAXSIZE];

int bipartitematch(const vector <vector <int> > &set_of_requirements) // Why is &m here?
{

    // We find the Bipartite match between elements in the set_of_requirements
    // to the taken list. Only one item in each set of requirements is matched
    // against the taken.

	int q_item;
	int retn=0;
	int path,classindex;
    int class_value;

    int size_of_requirements = set_of_requirements.size();

	vector <int> allclasses(MAXSIZE, NOTVISITED);
	vector <int> set_of_classes(size_of_requirements, NOTVISITED);

	for(int elem=0; elem < size_of_requirements; elem++)
	{
		queue<int> q_of_elements;
		q_of_elements.push(elem);

		vector<int> previous(size_of_requirements, NOTVISITED); // to keep track of elements.

		previous[elem] = VISITED;  // mark the elem as visited.

		while (!q_of_elements.empty())
		{
			q_item = q_of_elements.front(); q_of_elements.pop();

			for (classindex=0; classindex < set_of_requirements[q_item].size(); classindex++)
            {
                class_value = set_of_requirements[q_item][classindex];

				if (taken[class_value]) // If the individual class is taken.
				{

					if (allclasses[class_value] == NOTVISITED) 
						goto found;

					path = allclasses[class_value];

					if (previous[path] != NOTVISITED) // continue to next if previous[path] other than -1
						continue;

                    //previous has -1 at path.
					previous[path] = q_item; // BFS
					q_of_elements.push(path); // BFS
				}
            }
		}
		continue;
		found:  
            path = set_of_requirements[q_item][classindex];
			retn++;
			while( q_item != VISITED) 
			{
				allclasses[path] = q_item; // Mark the Path.
				swap(set_of_classes[q_item], path);  // Mark the Path.
				q_item = previous[q_item]; // get from previous
			}
	}
		return retn;
}

class Graduation
{
	public:
		string moreClasses(string classesTaken, vector <string> requirements)
		{
			vector <vector <int> > m; // [[]]
			int remaining,paths;
			int nextclass;
			string ret="";

			for (int ct=0; ct<classesTaken.size();ct++)
				taken[classesTaken[ct]] = CLASSTAKEN;

			for (int i=0;i<requirements.size();i++)
			{
				// does it take the first c char and discards the rest?
				int num = atoi(requirements[i].c_str()); 
				for (int choice=0; choice<num;choice++)
				{
					m.push_back(vector<int>());
					for (int j=0; j < requirements[i].size(); j++)
						if (isalpha(requirements[i][j]))
							m.back().push_back(requirements[i][j]);
				}
			}
			
			if (m.size() > MAXSIZE) return "0";

			remaining = m.size()-bipartitematch(m); //BP match

			nextclass=33;
			while(remaining)
			{
				if (nextclass >= MAXSIZE) return "0";
				if (taken[nextclass]) 
				{
					nextclass++;
					continue;
				}
				taken[nextclass] = 1;

				paths = m.size() - bipartitematch(m); // BP match

				if (paths == remaining)
					taken[nextclass] = 0;
				else
				{
					ret += nextclass; // is it concatenating str + int and giving str?
					remaining = paths;
				}
				nextclass++;

			}

			return ret;

		}
};

int main(int argc, char *argv[])
{
	Graduation combination;
	vector<string> requirement;
	requirement.push_back("2ABC");
	requirement.push_back("2CDE");
	//cout<<combination.moreClasses("ACE",requirement)<<endl;
	//cout<<combination.moreClasses("E",requirement)<<endl;
	cout<<combination.moreClasses("AE",requirement)<<endl;
}
