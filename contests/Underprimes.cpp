/**

Problem Statement
    
The prime factorization of a number X is the list of prime numbers that
multiply together to form X. For example, the prime factorization of 12 is 2 *
2 * 3. Note that 1 is not a prime number.

An underprime is a number whose prime factorization contains a prime number of
elements. For example, 12 is an underprime because its prime factorization
contains 3 elements, and 3 is a prime number. Given ints A and B, return the
number of underprimes between A and B, inclusive.

Definition
    
Class: Underprimes
Method: howMany
Parameters: int, int
Returns: int
Method signature: int howMany(int A, int B)

(be sure your method is public)
    
Notes

- A positive integer number is called prime if it has exactly two divisors - 1
  and itself. For example, 2, 3, 5 and 7 are prime numbers, and 4, 6, 8 and 9 are
  not prime. By convention, 1 is not considered to be a prime number.

- All prime factorizations of the same integer always contain the same prime
numbers and can only differ by the order of primes within them.

Constraints

- A will be between 2 and 100000, inclusive.
- B will be between A and 100000, inclusive.

Examples

0)

2
10
Returns: 5

The underprimes in this interval are: 4, 6, 8, 9, 10.

1)

100
105
Returns: 2
The underprimes in this interval are 102 = 2 * 3 * 17 and 105 = 3 * 5 * 7.

2)

17
17
Returns: 0

17 is a prime number, so its prime factorization contains one element. 1 is not
a prime, so 17 is not an underprime.

3)

123
456
Returns: 217

This problem statement is the exclusive and proprietary property of TopCoder,
Inc. Any unauthorized use or reproduction of this information without the prior
written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder,
Inc. All rights reserved.

**/

#include<vector>
#include<cmath>
#include<iostream>

using namespace std;

class Underprimes {

	private:

		int isprime(int n)
		{
			if (n <=1)
				return 0;
			if (n == 2)
				return 1;
			if (n%2 == 0)
				return 0;

			int m = sqrt(n);

			for (int i=3; i <= m ; i+=2)
				if(n%i == 0)
					return 0;
			return 1;
		}

		vector<int> getprimefactors(int num)
		{
			vector<int> primefactors;
			int i = 2;
			while (i <= num /i)
			{
				while (num % i == 0)
				{
					num = num /i;
					primefactors.push_back(i);
				}
				i++;
			}

			if (num > 1)
				primefactors.push_back(num);
			return primefactors;
		}

	public:
		int howMany(int A, int B) 
		{
			vector <int> factors;
			int count=0;
			for(int i = A; i <=B; i++)
			{
				factors = getprimefactors(i);
				if (isprime(factors.size()))
					count++;
			}
			return count;
		}

};

int main(int argc, char *argv[])
{
	Underprimes up;
	cout<<up.howMany(2,10);
}
