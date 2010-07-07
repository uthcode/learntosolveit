/***

Problem Statement
    
There are N students standing in a single row, one next to the other, numbered
0 to N-1 from left to right. Your goal is to minimize the number of adjacent
pairs where one student is a boy and the other is a girl. More precisely, you
want to minimize the number of values i, 0 <= i < N-1, where student i and
student i+1 are of different genders.  You are given the current arrangement as
a string row, where the i-th character is 'G' if student i is a girl, and 'B'
if student i is a boy. In a single move, you can choose two adjacent students
and swap their positions. Return the minimum number of moves required to
achieve your goal.

Definition
    
Class: GirlsAndBoys
Method: sortThem
Parameters: string
Returns: int
Method signature: int sortThem(string row)
(be sure your method is public)
    
Constraints
- row will contain between 1 and 50 characters, inclusive.
- Each character in row will be 'G' or 'B'.

Examples

0)"GGBBG"

Returns: 2

You can swap the rightmost girl with the two boys (one after the other) to get
"GGGBB", with a minimum of only 1 pair of adjacent students of different
gender.

1)"BBBBGGGG"

Returns: 0

There is already a single pair of adjacent students of different gender, and
there is no arrangement without such pairs at all, so the best solution is to
swap nothing.

2)
"BGBGBGBGGGBBGBGBGG"
Returns: 33

3)

"B"
Returns: 0

With only one student, there is not much swapping to do.

Algorithm:
1. Imitate bubble sort.
2. Two loops and in the inner loop, count the swaps for boys and girls.
2. Whoever is lesser their swap number will be the result.
***/

#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>

using namespace std;

class  GirlsAndBoys{
	public:
		// method name
		int sortThem(string row)
		{
			int i=0,j=0,b=0,g=0;
			for(i=0; i < row.size(); i++)
				for(j = 0; j < i; j++)
				{
					b += row[i] < row[j];
					g += row[i] > row[j];
				}
			return b < g? b:g;
		}
};

int main(int argc, char *argv[])
{
	GirlsAndBoys obj;
	cout<<obj.sortThem("BBGGGGGB");
}
