/***
Problem Statement
    
The Erdos number is a way of describing the "collaborative distance" between a
scientist and Paul Erdos by authorship of scientific publications. Paul Erdos
is the only person who has an Erdos number equal to zero. To be assigned a
finite Erdos number, a scientist must publish a paper in co-authorship with a
scientist with a finite Erdos number. The Erdos number of a scientist is the
lowest Erdos number of his coauthors + 1. The order of publications and numbers
assignment doesn't matter, i.e., after each publication the list of assigned
numbers is updated accordingly. You will be given a vector <string>
publications, each element of which describes the list of authors of a single
publication and is formatted as "AUTHOR_1 AUTHOR_2 ... AUTHOR_N" (quotes for
clarity only). Paul Erdos will be given as "ERDOS". Return the list of Erdos
numbers which will be assigned to the authors of the listed publications. Each
element of your return should be formatted as "AUTHOR NUMBER" if AUTHOR can be
assigned a finite Erdos number, and just "AUTHOR" otherwise. The authors in
your return must be ordered lexicographically.

Definition
    
Class: ErdosNumber
Method: calculateNumbers
Parameters: vector <string>
Returns: vector <string>
Method signature: vector <string> calculateNumbers(vector <string> publications)

(be sure your method is public)
    

Notes

- All authors mentioned in the list must be present in your return.
- Assume that all publications of mentioned authors are given in publications.
- String S is lexicographically before string T if S is a proper prefix of T, or
if S has an earlier character at the first position where the strings differ.
Constraints
- publications will contain between 1 and 50 elements, inclusive.
- Each element of publications will contain between 1 and 50 characters,
inclusive.
- An author is a string of between 1 and 50 uppercase letters ('A'-'Z'),
inclusive.
- Each element of publications will be a list of authors, separated by single
spaces.
- The authors in each element of publication will be distinct.
- There will be at most 100 distinct authors in all publications.
- Paul Erdos will be given as "ERDOS", and at least one publication will list him
as one of the authors.

Examples

0)
{"ERDOS"}
Returns: {"ERDOS 0" }
The only author is Erdos himself, with Erdos number equal to 0.

1)
{"KLEITMAN LANDER", "ERDOS KLEITMAN"}
Returns: {"ERDOS 0", "KLEITMAN 1", "LANDER 2" }
publications[1] defines Kleitman's number as 1, and publications[0] defines
Lander's number as 2.

2)
{"ERDOS A", "A B", "B AA C"}
Returns: {"A 1", "AA 3", "B 2", "C 3", "ERDOS 0" }

3)
{"ERDOS B", "A B C", "B A E", "D F"}
Returns: {"A 2", "B 1", "C 2", "D", "E 2", "ERDOS 0", "F" }
E has coauthors B (Erdos number 1) and A (Erdos number 2), so his Erdos number
is defined through the coauthor with the lowest Erdos number. D and F aren't
connected to Erdos and thus have no numbers assigned.

4)
{"ERDOS KLEITMAN", "CHUNG GODDARD KLEITMAN WAYNE", "WAYNE GODDARD KLEITMAN", 
 "ALON KLEITMAN", "DEAN GODDARD WAYNE KLEITMAN STURTEVANT"}

Returns: 
{"ALON 2",
 "CHUNG 2",
 "DEAN 2",
 "ERDOS 0",
 "GODDARD 2",
 "KLEITMAN 1",
 "STURTEVANT 2",
 "WAYNE 2" }

This problem statement is the exclusive and proprietary property of TopCoder,
Inc. Any unauthorized use or reproduction of this information without the prior
written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder,
Inc. All rights reserved.

**/

Class ErdosNumber
{
	public:
		vector <string> calculateNumbers(vector <string> publications)
		{
		}
};

int main(int argc, char *argv[])
{
	ErdosNumber erdos;

}
