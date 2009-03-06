/* Program illustrating sieve of Eratosthenes */

#include<stdio.h>
#define N 100

int main(void)
{
	int i,j,z[N];

	
	for(i=2;i<=N;++i)
		z[i]=i;

	for(i=2;i<N;i++)
	{
		for(j=i;j<=N;++j)
		{
			if(z[j]!=0 && j!=i && z[j]%i ==0)
				z[j]=0;
		}
	}

	for(i=2;i<=N;++i)
		if(z[i]!=0)
		printf("%d ",z[i]);
}

	
