#include<iostream>
using namespace std;

class EggCartons {
	public:
		int minCartons(int n)
		{
			int i,j;
			for(i=0;i<=18;i++)
				for(j=0;j<=12;j++)
					if (n == (i*6+j*8))
						return i+j;
			return -1;
		}
};

int main(int argc, char *argv[])
{
	EggCartons obj;
	cout<<obj.minCartons(100);
}

