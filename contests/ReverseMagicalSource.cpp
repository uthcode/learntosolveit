#include<iostream>
#include<math.h>
using namespace std;

class ReverseMagicalSource{
	public:
		int find(int source, int A)
		{
			int i=1;
			int sum=source;
			if (source > A)
				return source;
			else
				while (sum <= A)
				{
					source = source * (int)pow(10,i);
					sum += source;
				}
				return sum;
		}
};

int main(int argc, char **argv)
{
	ReverseMagicalSource obj;
	cout<<obj.find(333,36963);
}
