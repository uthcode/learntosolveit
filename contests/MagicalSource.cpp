/* SRM 451 Div 1
 *
 Problem Statement
    
Rick firmly believes that there are magical patterns related to some numbers. This belief is the result of his own tendency to find odd patterns everywhere. He has recently thought that some numbers have a "magical source". For example, the number 1371110974 has a magical source equal to 1234 because of the following process: 
        1234
+      12340
+     123400
+    1234000
+   12340000
+  123400000
+ 1234000000
------------
  1371110974
Formally, 1234 is a magical source of 1371110974 because there exists a number n such that the sum of a sequence of n numbers, where the i-th number (0-indexed) is 1234 multipled by 10^i, is equal to 1371110974. Note that by this definition, a positive number is a magical source of itself.  Given a positive long long x, return its minimum positive magical source.
Definition
    
Class:
MagicalSource
Method:
calculate
Parameters:
long long
Returns:
long long
Method signature:
long long calculate(long long x)
(be sure your method is public)
    

Constraints
-
x will be between 1 and 1000000000000 (10^12), inclusive.
Examples
0)

    
1371110974
Returns: 1234
This is the example from the statement.
1)

    
111111
Returns: 1

2)

    
10989
Returns: 99

3)

    
120
Returns: 120
Note that a number is always a magical source of itself.
4)

    
109999999989
Returns: 99

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.*
 */

#include<iostream>
using namespace std;

class MagicalSource {
	long long calculate(long long x)
	{


	}
};

int main(int argc, char *argv[])
{
}

