#include<iostream>
#include<vector>
#include<string>

using namespace std;

class BoredPhilosophers {
	public:
		vector <int> simulate(vector <string> text, int N)
		{
			int i,j,k;
			int p=1;
			int words=1;
			int checksize;
			vector <int> v1(10,20);
			string str = text[0];
			for (i=1;i< text.size();i++)
				str += text[i];

			for (i=0; i < str.size(); i++)
				if (str[i] == ' ')
					words++;

			while (p <= N) // while there are philosophers left
			{
				//for each philosopher and his index.
				//group the sentences into his vector.
				//Find unique amongst them.
				vector <string> unique;
				for (i=0; i < words; i+=p)
					unique.push_back(str[i]);


			}
			cout<<str<<endl;
			return v1;
		}
};

int main(int argc, char **argv)
{
	BoredPhilosophers obj;
	vector <string> v1;
	v1.push_back("remember");
        v1.push_back(" t");
        v1.push_back("o concatenate ");
        v1.push_back("the");
        v1.push_back(" ");
        v1.push_back("text");
	obj.simulate(v1,10);
}
