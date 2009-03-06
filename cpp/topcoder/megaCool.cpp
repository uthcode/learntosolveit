
#include<iostream>
using namespace std;

class MegaCoolNumber {
	public:
		int count(int N) {
			int megacool=0;
			// Check if N is between 1 and 1000
			if (N >=1 && N <=1000)
				for (int i = 1; i <= N; i++) {
					if (i < 100)
					       megacool++;
					else {
						if (i != 1000) {
							int d1 = i % 10;
							int d2 = (i/10) % 10;
							int d3 = (i/100) % 10;

							if ((d1-d2) == (d2-d3))
								megacool++;
						}
					}
				}
			return megacool;
		}

};

int main()
{
	MegaCoolNumber mnum;
	cout<<mnum.count(999);
	return 0;
}
