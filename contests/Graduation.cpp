/***
 *

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

using namespace std;

int taken[128];

int bipartitematch(const vector <vector <int> > &m, int max=128) // Why is &m here?
{
	int elemno;
	int retn=0;
	int y,j;
	//mat and ret vector.
	vector <int> mat(max, -1); // mat is like the residual network Keeps track of edges super source to set A.
	vector <int> ret(m.size(), -1); //  ret is residual network keeps track of edges from B to sink.

	for(int i=0; i < m.size(); i++)
	{
		queue<int> q;
		vector<int> pred(m.size(), -1); // to keep track of elements.
		q.push(i);
		pred[i] = -2;  // mark the elem as visited.
		while (!q.empty())
		{
			elemno = q.front(); q.pop();
			for (j=0; j < m[elemno].size(); j++)
				if (taken[m[elemno][j]]) // If the individual class is taken.
				{
					y = mat[m[elemno][j]]; // Have we marked the path?
					if (y == -1)  // Not yet.
						goto found;
					if (pred[y] != -1) // already visited. 
						continue;
					pred[y] = elemno; // BFS
					q.push(y); // BFS
				}
		}
		continue;
		found:  y = m[elemno][j];
			retn++;
			while( elemno != -2)
			{
				mat[y] = elemno; // Mark the Path.
				swap(ret[elemno], y);  // Mark the Path.
				elemno = pred[elemno]; // Is it visited or not?
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
				taken[classesTaken[ct]] = 1;

			for (int i=0;i<requirements.size();i++)
			{
				int num = atoi(requirements[i].c_str());
				for (int choice=0; choice<num;choice++)
				{
					m.push_back(vector<int>());
					for (int j=0; j < requirements[i].size(); j++)
						if (isalpha(requirements[i][j]))
							m.back().push_back(requirements[i][j]);
				}
			}
			
			if (m.size() > 128) return "0";
			remaining = m.size()-bipartitematch(m);
			nextclass=33;
			while(remaining)
			{
				if (nextclass >= 128) return "0";
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
					ret += nextclass;
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
	cout<<combination.moreClasses("A",requirement)<<endl;

}
