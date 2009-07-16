/* Program Submitted by:
 * A.Srinivaasan
 * Final Year, CSE-B,
 * National Engineering College
*/


import java.io.*;
public class underPrime 
{
 public static void main(String[] args) throws IOException
 {
  DataInputStream z=new DataInputStream(System.in);
  System.out.println("Enter the Range\nËnter the starting value(2-100000):");
  int a=Integer.parseInt(z.readLine());
  System.out.println("Ënter the ending value(2-100000):");
  int b=Integer.parseInt(z.readLine());
  if((a>b)||(a<2)||(a>100000)||(b<2)||(b>100000))
  {
   System.out.println("Enter a valid range");
  }
  else
  {
   underPrimes obj=new underPrimes();
   System.out.println("NUMBER OF UNDER PRIME NUMBERS :"+obj.howmany(a,b));
  }
 }
}

class underPrimes
{
 private int a,b;                 
 public int prime[],c,under;      
 public int howmany(int a,int b)
 {
  int i,j,temp,count,factors;
  this.a=a;
  this.b=b;
  prime=new int[b];
  c=0;
  // generating prime numbers
  for(i=2;i<=b;i++)
  {
   if(isPrime(i))
   {
    prime[c]=i;
    c++;
   }
  }
  // finding the underprime numbers
  factors=1;
  under=0;
  for(i=a;i<=b;i++)
  {
   count=0;
   factors=1;
   temp=i;
   while((prime[count]<temp)&&(count<c))
   {
    if(temp%prime[count]==0)
    {
     temp=temp/prime[count];
     count=0;
     factors++;
     continue;
    }
    count++;
   }
   if(isPrime(factors))
   {
    //System.out.println(i); To display the under prime numbers in the range
    under++;
   }
  }
  return under;
 }
 public boolean isPrime(int num)
 {
  int j,temp;
  temp=num/2;
  for(j=2;j<=temp;j++)
  {
   if(num%j==0)
   break;
  }
  if(j!=(temp+1))
   return false;
  return true;
 }
}
