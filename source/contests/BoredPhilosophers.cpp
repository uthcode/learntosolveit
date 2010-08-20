/** Problem Statement:
 * http://www.topcoder.com/stat?c=problem_statement&pm=10456
 * */

#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<cstring>
#include<sstream>

using namespace std;

class BoredPhilosophers {
	public:
		vector <int> simulate(vector <string> text, int N)
		{
			vector <int> v1;
			vector <string> words;
			string joined,aword,group_of_words;
			set <string> uniq;
			int i,j,k, word_length;

			for(i=0; i < text.size(); i++)
				joined += text[i];

			cout<<joined<<endl;
			istringstream str_of_words(joined);

			while (str_of_words >> aword)
				words.push_back(aword);

			for(i=0; i<N;i++)
			{
				uniq.clear();
				for (j=0; j < words.size(); j++)
				{
					word_length = i+1;
					if ((j + word_length) > words.size())
						break;
					group_of_words.clear();
					for(k=j;k<(j+word_length);k++)
						group_of_words += words[k];
					uniq.insert(group_of_words);
				}
				v1.push_back(uniq.size());
			}

			return v1;
		}
};

int main(int argc, char **argv)
{
	BoredPhilosophers obj;
	vector <string> v1;
	vector <int> out;
	v1.push_back("hello world");
	out = obj.simulate(v1,2);
	for(int i=0;i<out.size();i++)
		cout<<out[i]<<endl;
}
