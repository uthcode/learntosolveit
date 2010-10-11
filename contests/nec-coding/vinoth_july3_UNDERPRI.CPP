#include<iostream.h>
#include<conio.h>

class prime
	{
	private:
	   int a,b;
	   int d,x;
	   long int array[10000];
	public:
	   int factor(int a,int b);
	   int primeno(int x);
	   int underprime(int a);
	 };
int prime::factor(int a,int b)
{
int c=0,i,flag,flag1=0,x;
for(i=a;i<=b;i++)
{
array[c++]=i;
}
d=c;
for(c=0;c<d;c++)
	{
	x=array[c];
	flag=underprime(x);
	if(flag==1)
	flag1++;
	}

return flag1;


}
int prime::primeno(int x)
{
int flag=0;
int n=2,r,temp;
r=x%2;
if(r==0)
	return 1;
else
	{
	while(r!=0)
		{
		n++;
		temp=x/2;
		if(n<temp)
		{
		r=x%n;
		continue;
		}
		else
		{
		flag=1;
		break;
		}
		}
	if(flag==1)
	return 0;
	else
	return 1;
	}
}
int prime::underprime(int a)
{
int count=0,prime,q,i,count1,p,x,no;
prime=primeno(a);
	if(prime==1)
		{
		q=a/2;
		label2:
		for(i=2;i<=q;i++)
			{
			if(a%i==0)
				{
				a=a/i;
				count++;
				p=primeno(x);
				if(p==0)
				goto label1;
				else
				goto label2;
				}
			}

			label1:
			no=primeno(count);
			if(no==0)
			count1=1;
			else
			count1=0;
	}
	if(count1==1)
	return 1;
	else
	return 0;
	}




void main()
{
class prime obj;
int a,b,total;

cout<<"Enter The nos A and B:";
cin>>a>>b;
total=obj.factor(a,b);
cout<<"No of UnderPrimes between A&B:"<<total;
getch();
}














