#include<iostream>
#include<map>
#include<string>

using namespace std;
int main(int argc, char *argv[])
{
	map<int,int> mymap;
	map<string,string> mystrmap;
	mymap[10] = 100;
	mystrmap["senthil"] = "kumaran";
	cout<<mymap[10]<<endl;
	cout<<mystrmap["senthil"]<<endl;
}
