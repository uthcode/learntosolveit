/** TopCoder Problem Statement:
 *
 * http://www.topcoder.com/stat?c=problem_statement&pm=2911&rd=5849&rm=&cr=7446789

   Definition

   Class: MatchMaking
   Method: makeMatch
   Parameters: vector <string>, vector <string>, vector <string>, vector <string>, string
   Returns: string
   Method signature:
   string makeMatch(vector <string> namesWomen, vector <string> answersWomen,
   vector <string> namesMen, vector <string> answersMen, string queryWoman)
  (be sure your method is public)
 *
 */

#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

class MatchMaking {
	public:
		string makeMatch(vector <string> namesWomen, vector <string> answersWomen, 
				vector <string> namesMen, vector <string> answersMen,
				string queryWoman)
		{
			map<string,string> women;
			map<string,string> men;
			map<string,string>:: iterator wi,mi;
			map<string,string> suitablematch;

			string womanname,manname;
			string womanans, manans;
			int matchrank=0;
			int points=0;

			for (int i=0; i < namesWomen.size(); i++)
			{
				women[namesWomen[i]] = answersWomen[i];
				men[namesMen[i]] = answersMen[i];
			}

			/* Algorithm/ Strategy
			 * For each woman from the map, take her answer
			 * and iterate through the answers of mens do a bitwise
			 * AND and get the result. For the maximum value, let
			 * her escape with him.
			 *
			 */
			for(wi = women.begin(); wi !=women.end(); wi++)
			{
				womanname = wi->first;
				womanans = wi->second;
				matchrank = 0;
				for (mi = men.begin(); mi != men.end(); mi++)
				{
					manans = mi->second;
					points = find_match(womanans, manans);
					if (points > matchrank)
					{
						matchrank = points;
						suitablematch[womanname] = mi->first;
					}

				}
				//womens.erase(womansname);
				men.erase(suitablematch[womanname]);

			}

			return suitablematch[queryWoman];
		}

		int find_match(string str1,string str2)
		{
			int n,score=0;
			n = str1.size();
			for(int i=0; i< n; i++)
			{
				if (str1[i] == str2[i])
					score++;
			}
			return score;
		}

};

int main(int argc, char *argv[])
{
	MatchMaking obj;
	vector <string> nW,aW,nM,aM;
	string match;
	nW.push_back("Constance");
	nW.push_back("Bertha");
	nW.push_back("Alice");
	
	aW.push_back("aaba");
	aW.push_back("baab");
	aW.push_back("aaaa");

	nM.push_back("Chip");
	nM.push_back("Biff");
	nM.push_back("Abe");

	aM.push_back("bbaa");
	aM.push_back("baaa");
	aM.push_back("aaab");

	match = obj.makeMatch(nW,aW,nM,aM,"Bertha");
	cout<<match<<endl;
}

