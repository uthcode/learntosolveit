#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	vector<string> s;
	s.push_back("A");
	s.push_back("B");
	s.push_back("C");
	s.push_back("D");
	s.push_back("E");
	for (unsigned int p=0;p< s.size(); p++)
		for (unsigned int q=p+1; q < s.size(); q++)
			for (unsigned int r=q+1; r < s.size(); r++)
				cout<<s[p]<<s[q]<<s[r]<<endl;
}
