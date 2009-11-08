/* TopCoder: SRM 144 Div 2
 * Class: Time
 * Method: whatTime
 * Parameters: int
 * Returns: string
 * Method signature: * string whatTime(int seconds)
 *
 */

#include<iostream>
#include<string>
using namespace std;

class Time {
	public:
		string whatTime(int seconds)
		{
			string result;
			char some[10];
			sprintf(some,"%d:%d:%d",seconds/(60*60), (seconds%(60*60))/60,(seconds%(60*60))%60);
			result=some;
			return result;

		}
};

int main(int argc, char *argv[])
{
	Time obj;
	cout<<obj.whatTime(5436)<<endl;
	cout<<obj.whatTime(86399)<<endl;
}
