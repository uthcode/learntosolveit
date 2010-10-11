#include<vector>
#include<iostream>

using namespace std;

class Something
{
	public:
		int foo()
		{
			return 10;
		}
		int bar()
		{
			return foo();
		}
};

int main(int argc, char *argv[])
{
	vector <pair <int, int> > cords;
	cords.push_back(make_pair(1,-1));
	cords.push_back(make_pair(0,-1));
	int i;
	for (i =0; i < cords.size(); i++)
		cout<<cords[i].first<<" "<<cords[i].second<<endl;
	Something obj;
	cout<<obj.bar();
}
