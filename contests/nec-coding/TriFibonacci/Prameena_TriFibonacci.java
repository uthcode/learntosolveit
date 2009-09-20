/** Comments:
 *  1. Good Solution. 
 *  2. It works properly. I tested it for couple of inputs.
 *  3. You have used the correct logic and the method signature is also
 *  correct.
 *  4. Proper use Vector class too.
 *  
 *
 *  **/

import java.io.*;
import java.util.*;
class TriFibonacci 
{
 public int complete(Vector <Integer>A)
 {
  int pos=0;
  for(int j=0;j<A.size();j++)
  {
   if(A.elementAt(j)==-1)
   {
    pos=j;
    break;
   }
  }
  if(pos<3)
  {
   int sum=0;
   for(int k=0;k<3;k++)
   {   
     if(A.elementAt(k)>0)
        sum+=A.elementAt(k);
   }
   if((A.elementAt(3)-sum)<1)
        return -1;
   A.setElementAt(A.elementAt(3)-sum,pos);
   for(int l=3;l<A.size();l++)
   {
    if(A.elementAt(l)!=A.elementAt(l-1)+A.elementAt(l-2)+A.elementAt(l-3))
      return -1;
   }
    return A.elementAt(pos);              
  }
  A.setElementAt(A.elementAt(pos-1)+A.elementAt(pos-2)+A.elementAt(pos-3),pos);
   for(int m=3;m<A.size();m++)
   {
    if(A.elementAt(m)!=A.elementAt(m-1)+A.elementAt(m-2)+A.elementAt(m-3))
      return -1;
   }
    return A.elementAt(pos);          
 }
 public static void main(String args[])throws IOException
 {
  Vector<Integer> A=new Vector<Integer>();
  TriFibonacci Tf=new TriFibonacci();
  int f=0;
  try
  {
   System.out.println("enter the number of elements in Vector A");
   BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
   int N=Integer.parseInt(br.readLine());
   if(N>=4 && N<=20)
   {
    System.out.println("enter the Vector elements::Exactly one element of Vector will be -1");
    for(int i=0;i<N;i++)
    {
     int n=Integer.parseInt(br.readLine());
     if(n==-1 || n>=1 && n<=1000000)
      A.addElement(n);
     else
     {
      System.out.println("element should be -1 or it should be in between 1 and 1000000");
      f=1;
      break;
     }
    }     
   }
   else
   {
    System.out.println("Number of element in Vector should be in between 1 and 1000000");
   }
   if(f!=1)
   {
    System.out.println(" "+Tf.complete(A));
   }
  }catch(IOException e)
   {
    System.out.println("interger conversion error");
   }
 }
}
     
    
