/* SRM 145 Div 2 200
 *     
 * Class: ImageDithering
 * Method: count
 * Parameters: string, vector <string>
 * Returns: int
 * Method signature: int count(string dithered, vector <string> screen)
 *
 */

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class ImageDithering {
	public:
		int count(string dithered, vector<string> screen)
		{
			int result=0;
			string::iterator str_iter;
			for(vector<string>::iterator iter=screen.begin();
					iter != screen.end(); ++iter)
			{
				for(str_iter = (*iter).begin();
						str_iter != (*iter).end();
						++str_iter)
				{
					if (dithered.find(*str_iter) != string::npos)
						result++;
				}

			}
			return result;


		}
};

int main(int argc, char *argv[])
{
	ImageDithering obj;
	vector<string> v1;
	v1.push_back("AAAA");
	v1.push_back("BBBB");
	cout<< obj.count("XB",v1)<<endl;
}
