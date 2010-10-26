#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>

using namespace std;

class MicrowaveSelling {
	public:
		// method name
		int mostAttractivePrice(int minPrice, int maxPrice)
		{
			int i;
			int num, nines=0, whole=1;
			int price = maxPrice;
			num = maxPrice;

			while (num >10)
			{
				num /= 10;
				nines = (nines *10) + 9;
				whole *= 10;
			}

			for(price = maxPrice; price >= minPrice; price--)
			{
				if (whole > price)
				{
					whole /= 10;
					nines /= 10;
				}

				if ((price % whole) == nines)
					return price;

			}

			return maxPrice;

		}
};

int main(int argc, char *argv[])
{
	MicrowaveSelling obj;
	cout<<obj.mostAttractivePrice(20,25)<<endl;
}
