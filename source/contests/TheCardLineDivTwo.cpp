/**

Problem Statement
    
John and Brus are training for a card game tournament. During his off-time, Brus likes to occupy himself with the following game. The game is played with a subset of a standard deck of 52 distinct cards. Each card can be represented by a two-character string, where the first character is the rank ('2'-'9', 'T', 'J', 'Q', 'K', or 'A') and the second character is the suit ('S' for Spades, 'C' for Clubs, 'D' for Diamonds or 'H' for Hearts). All Spades and Clubs are black, and all Diamonds and Hearts are red. For example, the Jack of Spades is black and is represented as "JS", and the Nine of Hearts is red and is represented as "9H".
You are given a vector <string> cards containing the subset of the deck that Brus is playing with. Each element of cards represents a single card. He wants to place all of these cards in a line such that every pair of neighboring cards has the same rank or the same color (or both). Return the number of different ways he can do this modulo 1234567891.

Definition
    
Class:
TheCardLineDivTwo
Method:
count
Parameters:
vector <string>
Returns:
int
Method signature:
int count(vector <string> cards)
(be sure your method is public)
    

Constraints
-
cards will contain between 1 and 16 elements, inclusive.
-
Each element of cards will contain exactly two characters, where the first character is '2'-'9', 'T', 'J', 'Q', 'K' or 'A', and the second character is 'S', 'C', 'D' or 'H'.
-
All elements of cards will be distinct.
Examples
0)

    
{"KH", "QD", "KC"}
Returns: 2
There are two possible placements - KC-KH-QD and QD-KH-KC.
1)

    
{"JS", "JC", "JD", "JH"}
Returns: 24
All 24 permutations are valid.
2)

    
{"2S", "3C", "4C", "5S", "6C", "7S", "8S", "9H"}
Returns: 0
There is nothing we can do with the Nine of Hearts.
3)

    
{"KD", "KC", "AD", "7C", "AH", "9C", "4H", "4S", "AS"}
Returns: 2416

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.

**/

#include<iostream>
#include<vector>
using namespace std;

class TheCardLineDivTwo
{
	public:
		int count(vector<string> cards)
		{
			return 0;
		}
};

int main(int argc, char *argv[])
{
	TheCardLineDivTwo obj;
	vector<string> cards;
	cards.push_back("KH");
	cards.push_back("QD");
	cards.push_back("KC");

	cout<<obj.count(cards)<<endl;
}
