/* Comments:
 * 1. Good use of Vector and BufferedReader class.
 * 2. Good use of try, catch exception handling too.
 * 3. Switch Case Statement properly suited for the purpose.
 *
 * Some Improvements which could be made are:
 * 1. Proper spacing betweeen varaible names and variable and commas and
 * between operators etc. For e.g. (get>=1)&&(get<=1000000) could be written as
 * (get >= 1) && (get <= 1000000) 
 * This greatly improves the readability of the code.
 *
 */

import java.io.*;
import java.util.*;
class TriFibonacci
{
  public static void main(String S[]) throws Exception
 {
   int index,result,limit,exit=0,stop=0,get;
  Vector<Integer> A =new Vector<Integer>();
   BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
   TriFibonacci t=new TriFibonacci();
   try
   {
     System.out.println("enter the no of elements");
    limit=Integer.parseInt(br.readLine());
     if(limit>=4&&limit<=20)
     {
       System.out.println("Enter the elements");
       for(index=0;index<limit;index++)
      {
         get=Integer.parseInt(br.readLine());
         if((get==-1)||((get>=1)&&(get<=1000000)))
         {
	   A.addElement(get);
         }
         else
         {
           exit=1;
           System.out.println("Elements must be between 1 and 1000000 and there should be exactly one -1");
           break;
         }
       }
     }
     else
     {
       stop=1;
       System.out.println("Your vector must contain between 4 and 20 elements");
     }
     if((exit==0)&&(stop==0))
     {
       result=t.complete(A);
       System.out.println("The number is "+result);
     }
   }
   catch(Exception e)
   {
     System.out.println(e);
   }
 }
 public int complete(Vector<Integer> A)
 {
   int i,ret=0,ref=0,j;
   for(i=0;i<A.size();i++)
   {
     if(A.elementAt(i)==-1)
     {
       switch(i)
       {
        case 0:
              ret=A.elementAt(i+3)-(A.elementAt(i+2)+A.elementAt(i+1));
              if(ret>0)
              A.setElementAt(A.elementAt(i+3)-(A.elementAt(i+2)+A.elementAt(i+1)),i);
              else
              break;
              break;
        case 1:
              ret=A.elementAt(i+2)-(A.elementAt(i-1)+A.elementAt(i+1));
              if(ret>0)
              A.setElementAt(A.elementAt(i+2)-(A.elementAt(i-1)+A.elementAt(i+1)),i);
              else
              break;
              break;
        case 2:
              ret=A.elementAt(i+1)-(A.elementAt(i-1)+A.elementAt(i-2));
              if(ret>0)
              A.setElementAt(A.elementAt(i+1)-(A.elementAt(i-1)+A.elementAt(i-2)),i);
              else
              break;
              break;
        default:
              ret=A.elementAt(i-1)+A.elementAt(i-2)+A.elementAt(i-3);
              if(ret>0)
              A.setElementAt(A.elementAt(i-1)+A.elementAt(i-2)+A.elementAt(i-3),i);
              else
              break;
              break;
	}
      }
    }
    for(i=3;i<A.size();i++)
    {
      if(A.elementAt(i)!=(A.elementAt(i-1)+A.elementAt(i-2)+A.elementAt(i-3)))
      return(-1);
    }
    return(ret);
 }
}
