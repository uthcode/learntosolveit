#include<conio.h>
#include<iostream.h>
#include<math.h>

class underprimes

{
public:

    unsigned long int howmany(unsigned long int n);

}u;

unsigned long int underprimes::howmany(unsigned long int n)
{
  unsigned long int i,b,j=0,flag=0;
  b=n;
  for(i=2;i<=n;i++)
  {

    if(n%i==0)
      {
	j++;
	n=n/i;
	i=1;
      }
  }

  for(i=2;i<=j/2;i++)
  {
    if(j%i==0)
    flag=1;
    break;
  }
  if((flag==1)||(j==1))
    return 0;
  else
     return b;
}

void main()
{
  clrscr();
  unsigned long int c=0,z,n,a=0,b=0,k;
  cout<<"\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
  cout<<"\t\t\tCOUNT OF UNDERPRIME NUMBERS";
  do
  {
  cout<<"\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
  cout<<"Enter a number between 2 and 1,00,000:";
  cin>>a;
  cout<<"enter a number between "<<a<< "and 1,00,000:";
  cin>>b;
  if(((2>a)||(b>100000))||((a>b)||(b>100000)))
    cout<<"try again";
  else
    break;

  }while(1);
  for(k=a;k<=b;k++)
  {
    n=k;
    z=u.howmany(n);

    if(z!=0)
	c++;
  }
  cout<<"\n\nTHE NUMBER OF UNDER PRIME NUMBERS IN THE SPECIFIED RANGE:\n"<<c;

  getch();
}
