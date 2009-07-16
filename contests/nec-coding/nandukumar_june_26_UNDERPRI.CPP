#include<iostream.h>
#include<stdlib.h>
#include<conio.h>
class underprime
{
 public:
	//int  A,B;
       int howmany(int A,int B);
};
int underprime::howmany(int A,int B)
       {
       int l,n,a,w=0,s,flag,k=0,i,j,m;
       //int c[10000];
       //int q=99999;
//       s:
       for(l=A;l<=B;l++)
       {
	n=l;
//	k=0;
      //	t:
	scheck:
	while(n>1)
	{
	 if(n%2==0)
	 {
	  for(j=2;j<=9;j+=2)
	  {
	   a=n/j;
	   n=a;
	  // c[k]=j;
	   k++;
	 //  z++;
	   goto scheck;
	  }
	 }
	 else
	 {
       //saw:
	 for(m=3;m<=9999;m+=2)
	 {
	  if(n%m==0)
	  {
	   a=n/m;
	   n=a;
	   //c[z]=m;
	   k++;
	   //k=z;
	   goto scheck;
	  }
	//else
	//{
	// goto saw;
	 //}
	  }
	 }
	}
	s=k;
//	t=k;
/*	if(s==1)
	{
	k=0;
	n=l++;
	goto scheck;
	}  */
	if(s==1)
	{
	s=0;
	k=0;
	}

	if(s!=1&&s!=0)
	{
	k=0;
	for(i=2;i<s;i++)
	{
	 if(s%i==0)
	 {
	  flag=0;
	  //break;
	 }
	}
	if(flag!=0)
	{
	w++;
	}
	//cout<<"the w is "<<w;
       }
	 }
       return w;
       }

  void main()
  {
  int t,A,B;
   int r=10000;
   underprime prime;
   clrscr();
   cout<<"Enter the first no \n";
   cin>>A;
   check:
   if((A<2)||(A>r))
   {
   cout<<"The entered no is invalid......Pls enter the number between 2 to 100000\n";
   cin>>A;
   goto check;
   }

   cout<<"Enter the second no \n";
   cin>>B;
   if((B<A)||(B>r))
   {
   cout<<"The entered no is invalid......Pls enter the number between"<<A <<"\tto 100000\n";
   cin>>B;
   goto check;
   }
   t=prime.howmany(A,B);

   cout<<"The no of underprimes between\t"<<A<<"\t and"<<B<<"\t is "<<t;
   getch();

   }



