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

class BadVocabulary {
public:
    int count(string badPrefix, string badSuffix, string badSubstring, vector <string> vocabulary) {
        int res=0,i;
	string word,reversed_test,reversed_word;
	int len= vocabulary.size();
	size_t found1,found2,found3;

	for(i = 0; i< len; i++)
	{
		word = vocabulary[i];

		found1 = word.find(badPrefix);
		found2 = word.find(badSuffix);
		found3 = word.find(badSubstring,1);

		if (found1 != string::npos || found2 != string::npos || found3 !=string::npos)
		{
			if (found1 != string::npos)
			{
				if (int(found1) == 0)
				{
					res++;
					continue;
				}
			}

			if (found2 != string::npos)
			{
				
				reversed_test = badSuffix;
				reversed_word = word;
				reverse(reversed_test.begin(), reversed_test.end());
				reverse(reversed_word.begin(), reversed_word.end());

				found2 = reversed_word.find(reversed_test);
				if (found2 != string::npos)
				{
					if (int(found2) == 0)
					{
						res++;
						continue;
					}
				}
			}

			if (found3 != string::npos)
			{
				reversed_test = badSubstring;
				reversed_word = word;
				reverse(reversed_test.begin(), reversed_test.end());
				reverse(reversed_word.begin(), reversed_word.end());

				found3 = reversed_word.find(reversed_test,1);
				if (found3 != string::npos)
				{
						res++;
						continue;
				}

			}

		}

	}
	
        return res;
    }

};
