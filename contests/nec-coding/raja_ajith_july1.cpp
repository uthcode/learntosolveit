   J.RAJA SINGH XAVIER AJITH
   III - CSE B
   072107
   National Engineering College
   Kovilpatti

________________________________

   Hello sir,
            I have attached the cpp file for the contest of programming  underprime numbers.
    Thankyou for your support for the students as  alumini and we hope for more and more contest like this.
     
   Hoping for the best result from you sir.Please send an confirmation mail .


________________________________


This is the source code for generating underprime numbers
                                                                                  
# include <iostream.h>
# include <conio.h>
class prime
{
       public:
             int primeno(long int);
             int factor(long int,long int);
};

int prime::primeno(long int a)                   //Returns whether the given no is prime or not
{                                                            //Returns 1 if it is prime & returns 0 if it is not
     long int n;
     int l;
     n=2;
     if(a==1||a==2)
        return 1;
     if(a==0)
          return 0;
     while(n<a)
     {
          l=a%n;
          if(l==0)
                 return 0;
          n=n+1;
      }
     return 1;
}
 
int prime::factor(long int a,long int b)       //Returns no of factor the given no has
{
         int p,fa,j;
         long int s,k;
         fa=0;
         k=2;
         s=a;
         b=b-1;
         p=primeno(a);
         if(p==1)
             return 0;
         else
             while(s!=1)
             {
                       j=s%k;
                       if(j==0)
                       {
                                s=s/k;
                                k--;
                                fa++;
                           }
                           k++;
             }
             return fa;
 }

void main()
{
        prime p;
       long int a,b,i,l;
        int k,m;
        l=0;
        clrscr();
        cout<<"Enter the limit a :";
        cin>>a;
        cout<<"Enter the limit b :";
        cin>>b;
        cout<<"\n";
       i=a;
        cout<<"The underprime nos are\n";
        if(a!=b)
            while(i<=b)
            {
                      k=p.factor(i,b);                              //Finds the factor of given no
                      m=p.primeno(k);                           //Finds whether the factor is prime or not
                     if(m==1)                                       //If it is prime it is added to underprime nos
                      {
                                  l++;
                                  cout<<i;
                                  cout<<"\n";
                         }
                          i++;
               }
               cout<<"No of UNDERPRIME NOS between a to b  is "<<l;
               getch();
}



      See the Web&#39;s breaking stories, chosen by people like you. Check out Yahoo! Buzz. http://in.buzz.yahoo.com/