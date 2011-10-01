#include<iostream>
#include<stack>

using namespace std;

class TheCardShufflingDivTwo
{
	public:
	int shuffle(int n, int m)
	{
		stack<int> main;
		stack<int> left;
		stack<int> right;
		int im,il,ir;
		int item,value;
		for(int i=n; i>=1; i--)
			main.push(i);

		for(int j=0; j < m; j++)
		{
			while(!main.empty())
			/**for (im=0;im<main.size(); im++) **/
			{
				item = main.top(); main.pop();
				left.push(item);
				if (!main.empty())
				{
					item = main.top();
					main.pop();
					right.push(item);
				}
			}
			while (!left.empty())
			{
				item=left.top();left.pop();
				main.push(item);
			}
			
			/*
			for(il=0; il< left.size(); il++)
			{
				item = left.top();left.pop();
				main.push(item);
			}
			*/
			while(!right.empty())
			{
				item=right.top();right.pop();
				main.push(item);
			}


			/**
			for(ir=0;ir < right.size(); ir++)
			{
				item = right.top(); right.pop();
				main.push(item);
			}
			**/

		}

		value = main.top();

		return value;
	}
};

int main(int argc, char *argv[])
{
	int n,m;
	n = 1000000;
	m = 1000000;
	TheCardShufflingDivTwo obj;
	cout<<obj.shuffle(n,m)<<endl;
}

