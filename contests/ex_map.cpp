#include<map>
#include<iostream>

#define tr(container, it) \
	for(typeof(container.begin()) it = container.begin(); it !=container.end(); it++)
using namespace std;

int main(int argc, char *argv[])
{
	map<int, int> m1;
	m1[1] = 100;
	m1[2] = 200;
	m1[3] = 300;
	tr(m1,it)
		cout<<it->first<<" "<<it->second<<endl;
}
