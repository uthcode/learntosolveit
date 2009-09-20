/** Comments:
 * 1. Very good Solution.
 * 2. You have used a template <class T> which is surprising and different.
 * 3. If you had googled for Vector C++. you might have found #include <vector>
 * class which was the exact thing required.
 * 4. There was a memory error while executing the program. I gave the input (4
 * elements, 1000000, 1000000, 1000000, -1) . After returning the correct
 * answer. it threw out of exceptions. 
 * Best idea is the learn about vector class and use that. ( See the example
 * program in C++)
 * 5. Also, class and method signature is correct.
 *
/*TriFibonacci Sequence*/
#include<iostream>
using namespace std;

template <class T>
class vector
{
	int i,j;
	public:
	T *v;
	vector(long int vector_size)     // Vector creation using constructor
	{
	  v=new T[vector_size];
	  j=0;
	}
	~vector()                        // deleting Vector memory using destructor
	{
	 delete v;
	}
	void insert(long int i)           //  Inserting elements into Vector
	{
	  if(j>20)       		  // Vector Size must be less than 20
	    cout<<endl<<"Error: Out of Range";
	  else
	    v[j++]=i;
	}
	int size()	  // Returns the current size of the Vector
	{
	   return j;
	}
};
class Trifibonacci
{
	int flag,i,p;
	long int value;
	public:
	long int complete(vector<long int> A)     // Returns the Value which is to be replaced in the sequence instead of -1
	{
		flag=0;
		int n=A.size();
		for(p=0;p<n;p++)
		{
		   if(A.v[p]==-1)	// P has the position of -1 in the vector
		     break;
		}
		for(i=3;i<n;i++)
		{
		  if(i==p||i==p+1||i==p+2||i==p+3)  // Not considering the positions 
		     continue;
		  else
		  {
		    if(A.v[i]!=(A.v[i-1]+A.v[i-2]+A.v[i-3]))  // Checking the Sequence
		    {
			flag=1;
			break;
		     }
		   }
		}
	      if(flag==1)    // The sequence is incorrect
		value=-1;
	      else
	     {
	       if(p==0)                        // If -1 is in position 0
		 value=A.v[3]-A.v[1]-A.v[2];
	       else if(p==1)                   // If -1 is in position 1
		 value=A.v[3]-A.v[0]-A.v[2];
	       else if(p==2)                   // If -1 is in position 2
		 value=A.v[3]-A.v[0]-A.v[1];
	       else
		 value=A.v[p-1]+A.v[p-2]+A.v[p-3];
	    }
	  if(value==0)         // Since 0 is not a positive number
	  {
	    value=-1;
	    return value;
	  }
	  return value;
}
};
int main()
{
	int i,n;
	long int x,val;
	cout<<"Enter the size of vector between 4 and 20:";
	cin>>n;
	vector<long int> v(n);  // Creates the vector of size n
	Trifibonacci t;
	cout<<"Enter the elements: "<<endl;
	for(i=0;i<n;i++)
	{
	  cin>>x;
	  v.insert(x);
	 }
	val=t.complete(v);        // Returns the value
	cout<<"Returns:  "<<val<<endl;
}
