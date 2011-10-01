/**

ProblemName: BinaryCode

**/

#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>

using namespace std;

class BinaryCode {

	public:
		vector<string> decode(string message){

			vector<string> result;
			string P0,P1,Q;
			Q = message;

			int len = Q.size();
			int i;

			P0 = "0";
			for (i = 0; i < len; ++i)
			{
				if ((i-1) < 0)
				{
					// Q[i] = P0[i] + P0[i+1]
					string p0,q;
					p0 = P0[i];
					q = Q[i];

					int q1 = atoi(p0.c_str());
					int q2 = atoi(q.c_str());

					int p = q2-q1;

					if ( (p < 0) || (p > 1))
					{
						result.push_back("NONE");
						break;
					}
					if (p == 0) P0 += "0";
					if (p == 1) P0 += "1";

				}
				else if ((i+1) == len)
				{
					// Verify: Q[i] = P0[i-1] + P[i]
					string p0,p,q;
					p0 = P0[i-1];
					p = P0[i];
					q = Q[i];
					int q0 = atoi(p0.c_str());
					int q1 = atoi(p.c_str());
					int q2 = atoi(q.c_str());
					if (q2 == (q1 + q0)) 
						result.push_back(P0);
					else 
						result.push_back("NONE");
				}
				else
				{

					//Q[i] = P0[i-1] + P0[i] + P0[i+1];
					string p0,p1,q;
					p0 = P0[i-1];
					p1 = P0[i];
					q  = Q[i];
					int q1 = atoi(p0.c_str());
					int q2 = atoi(p1.c_str());
					int q3 = atoi(q.c_str());
					int p = q3 - (q1 + q2);
					if ((p < 0) || (p > 1))
					{
						result.push_back("NONE");
						break;
					}
					if (p == 0) P0 += "0";
					if (p == 1) P0 += "1";

				}
			}

			P0 = "1";
			for (i = 0; i < len; ++i)
			{
				if ((i-1) < 0)
				{
					// Q[i] = P0[i] + P0[i+1]
					string p0,q;
					p0 = P0[i];
					q = Q[i];

					int q1 = atoi(p0.c_str());
					int q2 = atoi(q.c_str());

					int p = q2-q1;

					if ( (p < 0) || (p > 1))
					{
						result.push_back("NONE");
						break;
					}
					if (p == 0) P0 += "0";
					if (p == 1) P0 += "1";

				}
				else if ((i+1) == len)
				{
					// Verify: Q[i] = P0[i-1] + P[i]
					string p0,p,q;
					p0 = P0[i-1];
					p = P0[i];
					q = Q[i];
					int q0 = atoi(p0.c_str());
					int q1 = atoi(p.c_str());
					int q2 = atoi(q.c_str());
					if (q2 == (q1 + q0)) 
						result.push_back(P0);
					else 
						result.push_back("NONE");
				}
				else
				{

					//Q[i] = P0[i-1] + P0[i] + P0[i+1];
					string p0,p1,q;
					p0 = P0[i-1];
					p1 = P0[i];
					q  = Q[i];
					int q1 = atoi(p0.c_str());
					int q2 = atoi(p1.c_str());
					int q3 = atoi(q.c_str());
					int p = q3 - (q1 + q2);
					if ((p < 0) || (p > 1))
					{
						result.push_back("NONE");
						break;
					}
					if (p == 0) P0 += "0";
					if (p == 1) P0 += "1";

				}
			}

			return result;
		}
};

int main()
{
	BinaryCode bcode;
	string s1;
	vector <string> res;
	s1 = "123";
	//s1 = "11";
	//s1 = "123210122";
	//s1 = "22111";
	//s1 = "3";
	//s1 = "123210120";
	res = bcode.decode(s1);
	for (int i =0; i < res.size(); ++i)
		cout<<i<<"result is"<<res[i]<<endl;
}
