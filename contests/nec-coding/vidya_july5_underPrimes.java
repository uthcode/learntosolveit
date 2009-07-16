/*Submitted by:
P.Vidhya
Final CSE
National Engineering College*/

import java.io.*;
public class underPrimes
{
 public static void main(String[] args) throws IOException
 {
  BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
  System.out.println("Enter the range a and b (2 to 100000):\n");
  int a=Integer.parseInt(br.readLine());
  int b=Integer.parseInt(br.readLine());
  if(a>1&&a<100001&&b>1&&b<100001)
  {
   prime c=new prime();
   System.out.println("The number of under prime numbers between "+a+"and "+b+" is "+c.howmany(a, b));
  }
  else
  {
   System.out.println("The range is from 2 to 100000");
  }
 }
}

class prime
{
 int m,s,l,count;
 public int howmany(int c,int d)
{
 int k;
 count=0;
 for(int i=c;i<=d;i++)
 {
  k=primefactor(i);
  m=k/2;
  for(l=2;l<=m;l++)
  {
   if(k%l==0)
    break;
  }
  if(l==(m+1))
   count++;
 }
 return(count);
}
int primefactor(int n)
{
 int i=2;
 s=1;
 while(i<n)
 {
  if(n%i==0)
  {
   s++;
   n=n/i;
   i=2;
  }
  else
   i++;
 }
 return(s);
}
}
