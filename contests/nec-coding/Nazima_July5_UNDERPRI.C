#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
	int k=0,j,i=0,m,y,count=0,flag,x,l=0,q,temp;
	double A,B,p,r;
	long int C[100000],pr[100000],factr[100000],up[100000];
	clrscr();
	printf("Enter the limits A and B:");
	scanf("%d%d",&A,&B);
// To find the prime numbers less than the upper limit
	for(r=2;r<=B;r++)
		C[r]=r;
	for(p=2;p<=sqrt(B);p++)
	{
		if(C[p]!=0)
		{
			j=p*p;
			while(j<B)
			{
				C[j]=0;
				j=j+p;
			}
		}
	}
	for(p=0;p<B;p++)
	{
		if(C[p]!=0)
		{
			pr[i]=C[p];
			i++;
		}
	}
	m=i;
/* To find the under primes in the given range */
	for(i=A;i<=B;i++)
	{
		y=i;k=0;
		/* To factorise a number*/
		for(j=0;j<m&&x>2;j++)
		{
			if(y%pr[j]==0)
			{
				y=y/pr[j];
				factr[k]=pr[j];
				k++;
				j=-1;
			}
		}
		/* To check the number of factors to be prime */
		flag=0;
		x=2;
		q=k%x;
		if(q==0)
			flag=0;
		else
		{
			while(q!=0)
			{
				x=x+1;
				temp=k/2;
				if(x<temp)
				{
					q=k%x;
					continue;
				}
				else
				{
					flag=1;
					break;
				}
			}
		}
		if(flag==1)
		{
			up[l]=A;
			count++;
		}
	}
	printf("The number of under prime numbers between %f and %f = %d and they are \n",A,B,count);
	for(n=0;n<count;n++)
		printf("%d\n",up[n]);
	getch();
}