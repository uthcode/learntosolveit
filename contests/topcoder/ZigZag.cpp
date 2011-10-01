/**
    
Class: ZigZag

**/

#include<iostream>
#include<vector>
using namespace std;

class ZigZag
{
	public:
	int longestZigZag(vector <int> sequence)
	{
		int len;
		int prevsign=0;
		int sign;
		vector<int> resultseq;
		
		for (int i=0; i < sequence.size(); i++)
		{
			if (i == 0) 
			{
				resultseq.push_back(sequence[i]);
				continue;
			}
			if (i == 1)
			{
				resultseq.push_back(sequence[i]);
				if ((sequence[i] - sequence[i-1]) > 0)
					prevsign = 1;
				else
					prevsign = -1;
				continue;
			}
			if (sequence[i] == sequence[i-1])
				continue;

			if ((sequence[i] - sequence[i-1]) > 0)
				sign = 1;

			else
				sign = -1;

			if (prevsign != sign)
			{
				resultseq.push_back(sequence[i]);
			}
			else
			{
				resultseq[resultseq.size()-1] = sequence[i];
			}
			prevsign = sign;

		}

		len = resultseq.size();
		return len;
	}
};

int main(int argc, char *argv[])
{
	ZigZag obj;
	vector<int> sequence;
	sequence.push_back(1);
	sequence.push_back(17);
	sequence.push_back(5);
	sequence.push_back(10);
	sequence.push_back(13);
	sequence.push_back(15);
	sequence.push_back(10);
	sequence.push_back(5);
	sequence.push_back(16);
	sequence.push_back(8);
	cout<<obj.longestZigZag(sequence)<<endl;
}

