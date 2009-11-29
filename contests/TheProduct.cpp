#include<iostream>
#include<vector>

using namespace std;

class TheProduct {
	public:
	long long maxProduct(vector <int> numbers, int k, int maxDist)
	{
		int N,i,t,j;
		N = numbers.size();
		vector <int> newlist;
		long long max=0, result;
		for(i = 0; i < N-1;)
		{
			if (newlist.size() < k)
				newlist.push_back(i+j);
			i = maxDist;
			
			result = multiplythem(newlist,numbers);
			if (result > max)
				max = result;
		}

		return max;

	}

	long long multiplythem(vector<int> nl, vector<int> num)
	{
		long long product=1;
		for(vector<int>::iterator it=nl.begin(); it!=nl.end(); ++it)
			product *= num[*it];
		return product;
	}

};

int main(int argc, char *argv[])
{
	TheProduct obj;
	vector<int> numbers;
	int k, maxDist;
	numbers.push_back(7);
	numbers.push_back(4);
	numbers.push_back(7);
	k = 2;
	maxDist = 50;
	cout<<obj.maxProduct(numbers, k, maxDist)<<endl;

}
