#include<vector>
#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
	vector<vector <int> > VVI;
	vector <int> v1(5,42);
	VVI.push_back(v1);
	VVI.push_back(v1);
	cout<<VVI.size()<<endl;
}

