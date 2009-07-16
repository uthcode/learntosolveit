// To find  the UnderPrimes  B/w  the values  A  &  B
#include<iostream.h>
#include<conio.h>
#include<math.h>
class underprimes
{
	public:
	    long int howmany(long int a,long int b);  // Member functions under Public mode
	    int prime(long int n);
};
long int underprimes::howmany(long int a,long int b)
{
	long int i,j,q,f=0,t=0,c,k=0;
	long int p[10000],up[10000],mid,product=1,no,v,count=0;
	mid=a/4;
	cout<<"\n\nBecause of using long integer variables the execution time is some more large\nThe o/p will appear slowly for large nos:\n\n ";
	for(q=2;q<=mid;q++)
	{
	     if(prime(q))
	     {
		p[k++]=q;
	      }
	 }
	 // To find underprime nos b/w the given range A & B
	 for(j=a;j<=b;j++)
	{
	    no=j;
	    i=0;
	    c=0;
	    f=0;
	    product=1;
	    if(!prime(no))
	     {
		while(product!=no)      // To find the product of prime factors is equalto the number no.
		{
		 if(no%p[i]==0&&f==0)
		  {
		     c++;
		     product*=p[i];
		     q=no/p[i];
		     f=1;
		     if(q%p[i]==0)
		     {
			 if(q%p[i]==0)
			   while(q%p[i]==0)
			   {
			      c++;
			      product*=p[i];
			      q=q/p[i];
			    }
			 else if(prime(q))
			 {
			   product*=q;
			   c++;
			   continue;
			  }
		      }
		      else if(prime(q))
		      {
			   product*=q;
			   c++;
			   continue;
		       }
			 i++;
		    }
	    else if(f==1)
	    {
		 if(q%p[i]==0)
		   while(q%p[i]==0)
		    {
		       c++;
		       product*=p[i];
		       q=q/p[i];
		     }
		 else if(prime(q))
		  {
		     product*=q;
		     c++;
		     continue;
		   }
		  else;
		    i++;
		    f=0;
	      }
	      else
	      {
		i++;
		continue;
	       }
	    }
	   if(prime(c))   // To find the no is underprime or not
	   {
		 up[t++]=no;  // Storing the underprime no into up[] array
		 count++;     // Counting the underprime nos b/w A & B
	    }
	  }
	}
	if(t>0)
	cout<<"\nThe underprime values are:\n\n";
	for(i=0;i<t;i++)
	   cout<<up[i]<<"\t";   //  Displaying all the underprimes
	return count;
}
int underprimes::prime(long int n)  // To find n is prime or not
{
	int flag=0;
	long int i;
	for(i=2;i<n;i++)
	{
	   if(n%i==0)
	      flag=1;
	}
	if(flag==0)
	  return 1;    // If n is prime
	else
	  return 0;    // If n is not prime
}
void main()
{
	long int a,b;
	long int count;
	underprimes up;
	clrscr();
	cout<<"Enter the A value b/w 2 & 100000 :";
	cin>>a;
	cout<<"\nEnter the B value b/w "<<a<<" & 100000 :";
	cin>>b;
	count=up.howmany(a,b);
	cout<<"\n\nCount of UnderPrimes:  "<<count<<endl;
	getch();
}


