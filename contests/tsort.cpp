/***
 *
#!/usr/bin/python

"""
Problem Name: Turbo Sort
Problem code: TSORT
http://www.codechef.com/problems/TSORT/
"""

output = []
t = int(raw_input())
for num in range(t):
    output.append(int(raw_input()))
output.sort()
for num in output:
    print num
 
 *
 *
 * ***/

#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int main(int argc, char *argv[])
{
	long int i,t=0,n;
	scanf("%ld",&t);
	//cin>>t;
	long int arr[t];
	for (i=0; i<t;i++)
	{
		scanf("%ld",&n);
		arr[i] = n;
	}
	sort(arr, arr+t);
	for (i=0; i<t;i++)
		printf("%ld\n",arr[i]);
		//cout<<arr[i]<<endl;
}
