#include <vector>
#include <string>
#include <iostream>

using namespace std;

class StringBuilder {
	public: 
		string buildString(vector<char> array)
		{
			// create a string for vector
			string s;
			
			// loop over every element in the array.

			for (int i = 0; i < array.size(); i++)
			{
				s = s + array[i];
			}

			return s;
		}
};

int main() {
	StringBuilder myStr;
	vector<char> myvect(10);
	for (int i=0; i < myvect.size(); i++) {
		myvect[i] = i;
	}
	cout << myStr.buildString(myvect);
	return 0;
}

