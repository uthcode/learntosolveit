/***

Problem Statement   PalindromesCount
**/

#include<iostream>
#include<string>
using namespace std;

class PalindromesCount {
	public:
		int ispalindrome(string C)
		{
			int i,j;
			for(i=0,j=C.length()-1; i <=j;i++,j--)
				if (C[i] != C[j])
					return 0;
			return 1;
		}
		int count(string A, string B)
		{
			int i;
			string C;
			int count=0;
			for(i=0;i<A.length();i++)
			{
				C = A;
				C.insert(i,B);
				if (ispalindrome(C))
					count++;
			}
			return count;
		}
};

int main(int argc, char *argv[])
{
	string A,B;
	A = "aba";
	B = "b";
	PalindromesCount obj;
	cout<<obj.count(A,B)<<endl;
}
