#include<iostream>
#include<map>

using namespace std;

class TheEncryptionDivTwo{
	public:
		string encrypt(string message)
		{
			map<char, char> cipher;
			string alphabets = "abcdefghijklmnopqrstuvwxyz";
			string result;
			int i,j=0;
			char c,m;
			for(i=0;i<message.size();i++)
			{
				c = message[i];
				if (cipher.count(c) ==0)
				{
					cipher[c] = alphabets[j];
					result.push_back(alphabets[j]);
					j++;
				}
				else
				{
					result.push_back(cipher[c]);
				}
			}

			return result;
		}

};

int main(int argc, char *argv[])
{
	TheEncryptionDivTwo obj;
	cout<<obj.encrypt("hello");
	cout<<obj.encrypt("encryption");
}

