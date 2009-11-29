#include<iostream>
#include<set>
#include<string>
#include<cstring>
#include<sstream>
#include<vector>

using namespace std;

class ToolsBox {
	public:
		int countTools(vector<string> need)
		{
			string toollist,tool;
			set<string> uniq;
			for(vector<string>::iterator it=need.begin(); it!=need.end(); ++it)
			{
				toollist = *it;
				istringstream str_of_words(toollist);
				while(str_of_words >> tool)
					uniq.insert(tool);

			}
			return uniq.size();

		}
};

int main(int argc, char *argv[])
{
	ToolsBox obj;
	vector<string> v1;
	v1.push_back("A B C");
	v1.push_back("B C D");
	cout<<obj.countTools(v1);
}
