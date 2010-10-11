/***
Problem Statement
    
A palindrome is a string that is the same whether it is read from left to right or from right to left. Little Dazdraperma likes palindromes a lot. As a birthday gift she received two strings A and B. Now she is curious if there is a way to insert string B into string A so that the resulting string is a palindrome. You agreed to help her and even tell how many different variants of such insertions exist. Two variants are considered different if string B is inserted in different places. Return the number of possible insertion variants.  For example, let A="aba" and B="b". You can insert B in 4 different places:
Before the first letter of A. The result is "baba" and it is not a palindrome.
After the first letter 'a'. The result is "abba" and it is a palindrome.
After the letter 'b'. The result is "abba" and it is also a palindrome.
After the second letter 'a'. The result is "abab" and it is not a palindrome.
So, the answer for this example is 2.
Definition
    
Class:
PalindromesCount
Method:
count
Parameters:
string, string
Returns:
int
Method signature:
int count(string A, string B)
(be sure your method is public)
    

Constraints
-
A and B will each contain between 1 and 50 characters, inclusive.
-
Each character of A and B will be a lowercase letter ('a'-'z').
Examples
0)

    
"aba"
"b"
Returns: 2
The example from the problem statement.
1)

    
"aa"
"a"
Returns: 3
Here every possible insertion point gives you a palindrome.
2)

    
"aca"
"bb"
Returns: 0
No possible solutions.
3)

    
"abba"
"abba"
Returns: 3

4)

    
"topcoder"
"coder"
Returns: 0

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
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
