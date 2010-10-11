/** The Solution is correct
 * The Logic is very round-about. Some times it happens.
 * To improve your coding further, you might want to choose a good editor and
 * look at the spacing between tokens etc.
 * Like a=b is one way.
 * but a = b ( with space between two variables is different and more legible).
 * Also, when we put comma ',' we separate the varible names like
 * A.setElementAt(x, i-3).
 *
 * Also, have a look at problem statement's required Class and Method
 * Signature. Your Solution has a different Method Signature.
 *
 *
 *
/* Submitted By
A.Srinivaasan
Final CSE
National Engineering College*/

import java.io.*;
import java.util.*;
class TriFibonacci
{
 public static void main(String args[]) throws IOException
 {
  int ans=-1,y,i;
  DataInputStream z=new DataInputStream(System.in);
  System.out.println("Enter the number of terms in the Vector:");
  int n=Integer.parseInt(z.readLine());
  if(n>3&&n<21)
  {
   Vector<Integer> A=new Vector<Integer>(n);
   System.out.println("Enter the elements of the Vector one by one");
   for(i=0;i<n;i++)
   {
    y=Integer.parseInt(z.readLine());
    if(y==-1||(y>0&&y<1000001))
    A.add(i,y);
    else
    {
     System.out.println("ERROR:The Element should be from 1-100000 or -1");
     break;
    }
   }
   if(n==i)
   {
    if(A.contains(-1))
    {
     FillTriFibonacci x=new FillTriFibonacci();
     ans=x.contains(A);
    }
    else
     System.out.println("ERROR: The elements should contain -1");
    if(ans>0)
    {
     System.out.println("The Replacement is: "+ans);
    }
   }
  }
  else
  {
   System.out.println("ERROR: Range is 4-20");
  }
 }
}

class FillTriFibonacci
{
 public int contains(Vector<Integer> A)
 {
  int a,b,c,d,ans=-1,flag=0;
  for(int i=3;i<A.size();i++)
  {
   a=A.get(i-3);
   b=A.get(i-2);
   c=A.get(i-1);
   d=A.get(i);
   if(a==-1||b==-1||c==-1||d==-1)
   {
    if(flag!=0)
    {
     System.out.println("ERROR: More than one -1 is present in the vector");
     return -1;
    }
    flag=1;
    if(a==-1)
    {
     ans=(d-(b+c));
     A.setElementAt(ans,i-3);
    }
    else if(b==-1)
    {
     ans=(d-(a+c));
     A.setElementAt(ans,i-2);
    }
    else if(c==-1)
    {
     ans=(d-(a+b));
     A.setElementAt(ans,i-1);
    }
    else
    {
     ans=(a+b+c);
     A.setElementAt(ans,i);
    }
    i--;
    continue;
   }
   if(d!=(a+b+c))
   {
    System.out.println("ERROR: The given series in not TriFibonacci");
    return -1;
   }
  } 
  if(ans==0||ans<-1)
  {
   ans=-1;
   System.out.println("ERROR: No positive replacements can be made"); 
  }
  return ans;
 }
} 
