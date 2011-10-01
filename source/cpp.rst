===============
C++ Programming
===============


Questions
=========

#) What are Virtual Tables?

#) What is const-correctness?

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#defile all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define all(c) c.begin(), c.end()
#define tr(container, it) \
	for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
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
