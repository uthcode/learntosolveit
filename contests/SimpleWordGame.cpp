/**

Problem Statement
    
The Simple Word Game is a game where a player tries to remember as many words
as possible from a given dictionary. The score for each distinct word that the
player remembers correctly is the square of the word's length.  You are given a
vector <string> player, each element of which is a word remembered by the
player. There may be duplicate words, but if the same word appears multiple
times, it should only be counted once. You are given the dictionary in the
vector <string> dictionary, each element of which is a single distinct word.
Return the player's total score.

Definition
    
Class: SimpleWordGame
Method: points
Parameters: vector <string>, vector <string>
Returns: int 
Method signature: int points(vector <string> player, vector <string> dictionary)

(be sure your method is public)
    
Constraints

- player will contain between 1 and 50 elements, inclusive.
- Each element of player will contain between 1 and 50 characters, inclusive.
- Each character of each element of player will be a lowercase letter of English alphabet ('a' - 'z').
- dictionary will contain between 1 and 50 elements, inclusive.
- Each element of dictionary will contain between 1 and 50 characters, inclusive.
- Each character of each element of dictionary will be a lowercase letter of English alphabet ('a' - 'z').
- All elements of dictionary will be distinct.

Examples

0) { "apple", "orange", "strawberry" }
{ "strawberry", "orange", "grapefruit", "watermelon" }

Returns: 136

The player has correctly remembered two words from the dictionary: "orange"
(worth 6*6 = 36 points) and "strawberry" (worth 10*10 = 100 points). That gives
a total score of 136 points.

1) { "apple" }
{ "strawberry", "orange", "grapefruit", "watermelon" }

Returns: 0

The player has remembered just "apple" and it's not in the dictionary, so the score is 0.

2) { "orange", "orange" }
{ "strawberry", "orange", "grapefruit", "watermelon" }

Returns: 36
The "orange" occurs twice in player, but should be counted just once towards the score.

3) { "lidi", "o", "lidi", "gnbewjzb", "kten",
  "ebnelff", "gptsvqx", "rkauxq", "rkauxq", "kfkcdn"}
{ "nava", "wk", "kfkcdn", "lidi", "gptsvqx",
  "ebnelff", "hgsppdezet", "ulf", "rkauxq", "wcicx"}

Returns: 186

This problem statement is the exclusive and proprietary property of TopCoder,
Inc. Any unauthorized use or reproduction of this information without the prior
written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder,
Inc. All rights reserved.

**/

#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>


using namespace std;

class SimpleWordGame {

	public:
		int points(vector <string> player, vector <string> dictionary)
		{
			int score=0;
			int found=0;
			// Remove duplicates from the player.
			sort(player.begin(), player.end());
			player.erase(unique(player.begin(), player.end()),player.end());

			for (int i = 0; i < player.size(); i++)
			{
				found = 0;
				for (int j=0; j < dictionary.size(); j++)
				{
					if (player[i] == dictionary[j])
					{
						found = 1;
						score += (strlen(player[i].c_str()) * strlen(player[i].c_str()));
						break;
					}
				}
				if (found == 1)
					continue;
			}

			return score;
		}
};

int main(int argc, char *argv[]){

	SimpleWordGame swg;
	vector <string> player(3), dictionary(4);
	player[0] = "apple";
	player[1] = "orange";
	player[2] = "strawberry";
	dictionary[0] = "strawberry";
	dictionary[1] = "orange";
	dictionary[2] = "grapefruit";
	dictionary[3] = "watermellon";
	cout<< swg.points(player,dictionary);
}

