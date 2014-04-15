/* binsearch: Implementation of Binary Search,In the array v[],search for n in the binary way*/

#include<stdio.h>

int binsearch(int x,int v[],int n);

int main(void)
{
	int arr[]={2,4,5,7,8,9,11,23,45,50};
	int x,n;

	printf("%d",binsearch(9,arr,10));

	return 0;
}

int binsearch(int x,int v[],int n)
{
	int low,high,mid;

	low=0;
	high=n-1;

	while(low<high)
	{
		mid = ( low + high ) / 2;

		if( x < v[mid])
			high  = mid - 1;
		else if ( x > v[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}
