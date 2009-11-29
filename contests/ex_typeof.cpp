#include<vector>
#include<iostream>
using namespace std;

#define tr(container, it) \
	for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)


int main(int argc, char *argv[])
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	tr(v1,it)
		cout<<*it<<endl;
}
