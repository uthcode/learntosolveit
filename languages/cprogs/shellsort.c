/* shellsort: sorting distant elements first and then reducing the distance */

#include<stdio.h>
void shellsort(int v[],int n);

int main(void)
{
	int i;
	int v[10]={32,12,46,25,8,6,12,98,34,90};
	for(i=0;i<10;i++)
		printf("%d ",v[i]);
	shellsort(v,10);
	printf("\nAfter Sort\n");
	for(i=0;i<10;i++)
		printf("%d ",v[i]);

	return 0;
}

void shellsort(int v[],int n)
{
	int gap,i,j,temp;

	for(gap = n/2; gap > 0; gap /=2)
		for(i= gap; i < n ; ++i)
			for( j=i-gap; j >=0 && (v[j] > v[j+gap]);j-=gap)
			{
				temp = v[j];
				v[j] = v[j+gap];
				v[j+gap] = temp;
			}
}

	
