/***

Definition
    
Class: MatrixShiftings
Method: minimumShifts
Parameters: vector <string>, int
Returns: int
Method signature: int minimumShifts(vector <string> matrix, int value)
(be sure your method is public)

***/
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

class MatrixShiftings {
	public:
		int minimumShifts(vector <string> matrix, int value)
		{
			string s;
			stringstream out;
			out<<value;
			s = out.str();
			size_t found;
			int len = matrix.size();
			int j,stringlen;
			for(int i=0; i < len; i++)
			{
				found = matrix[i].find(s);
				if (found != string::npos)
				{
					j = (int)found;
					stringlen = matrix[i].size();
					if (j > (stringlen-j))
						j = stringlen-j;
					if (i > (len-i))
						i = len-i;
					return i+j;

				}
			}
			return -1;

		}
};

int main(int argc, char *argv[])
{
	vector<string> v;
	v.push_back("12345");
	MatrixShiftings obj;
	cout<<obj.minimumShifts(v,4)<<endl;
}
