/**

Problem Statement: DivisorDigits
    
*/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class DivisorDigits {
	public:
		int howMany(int number)
		{
			int orig=number;
			int count=0,digit;
			while (number)
			{
				digit = number - ((number/10)*10);
				number = number/10;
				if ((orig % digit) == 0)
					count++;
			}
			return count;
			
		}
};

int main(int argc, char *argv[])
{
	DivisorDigits obj;
	cout<<obj.howMany(12345)<<endl;
}
