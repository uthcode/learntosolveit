/**

Class: SimpleWordGame

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

