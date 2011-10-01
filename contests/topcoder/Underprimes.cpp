/**

Class: Underprimes

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
