/**

Problem Statement
    	

Let's say you have a binary string such as the following:

011100011

One way to encrypt this string is to add to each digit the sum of its adjacent
digits. For example, the above string would become:

123210122

In particular, if P is the original string, and Q is the encrypted string, then
Q[i] = P[i-1] + P[i] + P[i+1] for all digit positions i. Characters off the
left and right edges of the string are treated as zeroes.

An encrypted string given to you in this format can be decoded as follows
(using 123210122 as an example):

   1. Assume P[0] = 0.
   2. Because Q[0] = P[0] + P[1] = 0 + P[1] = 1, we know that P[1] = 1.
   3. Because Q[1] = P[0] + P[1] + P[2] = 0 + 1 + P[2] = 2, we know that P[2] = 1.
   4. Because Q[2] = P[1] + P[2] + P[3] = 1 + 1 + P[3] = 3, we know that P[3] = 1.
   5. Repeating these steps gives us P[4] = 0, P[5] = 0, P[6] = 0, P[7] = 1, and P[8] = 1.
   6. We check our work by noting that Q[8] = P[7] + P[8] = 1 + 1 = 2. Since
this equation works out, we are finished, and we have recovered one possible
original string.

Now we repeat the process, assuming the opposite about P[0]:

   1. Assume P[0] = 1.
   2. Because Q[0] = P[0] + P[1] = 1 + P[1] = 0, we know that P[1] = 0.
   3. Because Q[1] = P[0] + P[1] + P[2] = 1 + 0 + P[2] = 2, we know that P[2] = 1.
   4. Now note that Q[2] = P[1] + P[2] + P[3] = 0 + 1 + P[3] = 3, which leads
us to the conclusion that P[3] = 2. However, this violates the fact that each
character in the original string must be '0' or '1'. Therefore, there exists no
such original string P where the first digit is '1'.

Note that this algorithm produces at most two decodings for any given encrypted
string. There can never be more than one possible way to decode a string once
the first binary digit is set.

Given a String message, containing the encrypted string, return a
vector<string> with exactly two elements. The first element should contain the
decrypted string assuming the first character is '0'; the second element should
assume the first character is '1'. If one of the tests fails, return the string
"NONE" in its place. For the above example, you should return {"011100011",
"NONE"}.
 
Definition
    	
Class:	BinaryCode
Method:	decode
Parameters:	String
Returns:	String[]
Method signature:	String[] decode(String message)
(be sure your method is public)
    
 
Constraints
-	message will contain between 1 and 50 characters, inclusive.
-	Each character in message will be either '0', '1', '2', or '3'.
 
Examples
0)	
    	

"123210122"

Returns: { "011100011",  "NONE" }

The example from above.
1)	
    	

"11"

Returns: { "01",  "10" }

We know that one of the digits must be '1', and the other must be '0'. We return both cases.
2)	
    	

"22111"

Returns: { "NONE",  "11001" }

Since the first digit of the encrypted string is '2', the first two digits of
the original string must be '1'. Our test fails when we try to assume that P[0]
= 0.

3)	
    	

"123210120"

Returns: { "NONE",  "NONE" }

This is the same as the first example, but the rightmost digit has been changed
to something inconsistent with the rest of the original string. No solutions
are possible.

4)	
    	

"3"

Returns: { "NONE",  "NONE" }

5)	
    	

"12221112222221112221111111112221111"

Returns: 
{ "01101001101101001101001001001101001",
 "10110010110110010110010010010110010" }

This problem statement is the exclusive and proprietary property of TopCoder,
Inc. Any unauthorized use or reproduction of this information without the prior
written consent of TopCoder, Inc. is strictly prohibited. (c)2006, TopCoder,
Inc. All rights reserved. 

**/

#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>

using namespace std;

class BinaryCode {

	public:
		vector<string> decode(string message){

			vector<string> result;
			string P0,P1,Q;
			Q = message;

			int len = Q.size();
			int i;

			P0 = "0";

			for (i = 0; i < len-1; ++i)
			{
				if ((i-1) < 0)
				{
					// Q[i] = P0[i] + P0[i+1]
					string p0,q;
					p0 = P0[i];
					q = Q[i];
					int q1 = atoi(p0.c_str());
					int q2 = atoi(q.c_str());
					int p = q2-q1;
					if ( p < 0 || p > 1)
					{
						result.push_back("NONE");
						break;
					}
					if (p == 0) P0 += "0";
					if (p == 1) P0 += "1";

				}
				else if ((i+1) > len)
				{
					//Q[i] = P0[i-1] + P0[i];
					string p0,q;
					p0 = P0[i-1];
					q = Q[i];
					int q1 = atoi(p0.c_str());
					int q2 = atoi(q.c_str());
					int p = q2 - q1;
					if (p < 0 || p > 1)
					{
						result.push_back("NONE");
						break;
					}
					if (p == 0) P0 += "0";
					if (p == 1) P0 += "1";

				}
				else
				{

					//Q[i] = P0[i-1] + P0[i] + P0[i+1];
					string p0,p1,q;
					p0 = P0[i-1];
					p1 = P0[i];
					q  = Q[i];
					int q1 = atoi(p0.c_str());
					int q2 = atoi(p1.c_str());
					int q3 = atoi(q.c_str());
					int p = q3 - (q1 + q2);
					if (p < 0 || p > 1)
					{
						result.push_back("NONE");
						break;
					}
					if (p == 0) P0 += "0";
					if (p == 1) P0 += "1";


				}
			}
			result.push_back(P0);

			P0 = "1";
			for (i = 0; i < len-1; ++i)
			{
				if ((i-1) < 0)
				{
					// Q[i] = P0[i] + P0[i+1]
					string p0,q;
					p0 = P0[i];
					q = Q[i];
					int q1 = atoi(p0.c_str());
					int q2 = atoi(q.c_str());
					int p = q2-q1;
					if ( p < 0 || p > 1)
					{
						result.push_back("NONE");
						break;
					}
					if (p == 0) P0 += "0";
					if (p == 1) P0 += "1";

				}
				else if ((i+1) > len)
				{
					//Q[i] = P0[i-1] + P0[i];
					string p0,q;
					p0 = P0[i-1];
					q = Q[i];
					int q1 = atoi(p0.c_str());
					int q2 = atoi(q.c_str());
					int p = q2 - q1;
					if (p < 0 || p > 1)
					{
						result.push_back("NONE");
						break;
					}
					if (p == 0) P0 += "0";
					if (p == 1) P0 += "1";

				}
				else
				//else if ( 0 < i && i < len-1)
				{

					//Q[i] = P0[i-1] + P0[i] + P0[i+1];
					string p0,p1,q;
					p0 = P0[i-1];
					p1 = P0[i];
					q  = Q[i];
					int q1 = atoi(p0.c_str());
					int q2 = atoi(p1.c_str());
					int q3 = atoi(q.c_str());
					int p = q3 - (q1 + q2);
					if (p < 0 || p > 1)
					{
						result.push_back("NONE");
						break;
					}
					if (p == 0) P0 += "0";
					if (p == 1) P0 += "1";

				}
			}
			result.push_back(P0);

			return result;
		}
};

int main()
{
	BinaryCode bcode;
	string s1;
	//s1 = "11";
	//s1 = "123210122";
	s1 = "22111";
	cout<<bcode.decode(s1)[0]<<endl;
	cout<<bcode.decode(s1)[1]<<endl;
}
