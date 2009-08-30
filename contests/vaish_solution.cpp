#include<iostream>
#include<vector>
using namespace std;

class binarycode
{
	public:
		vector<string> decode(string msg);
};

vector<string> binarycode::decode(string msg)
{

	string dstr1 = "0";
	vector<string> decodedstr;
	vector<string>::iterator it;
	string dstr2 = "0";
	int i=0,j=0,k=0;
	int Length;
	bool flag1 = false, flag2 = false;
	int m = 0;
	dstr1[i] = '0';
	dstr2[i] = '1';

	Length = msg.size();

	while((Length > 1) && (++i < Length) )
	{
		if(i ==1)
			dstr1[i] = ((msg[i-1] - '0')-(dstr1[i-1] - '0')) + '0' ;
		else
			dstr1[i] = ((msg[i-1] - '0')-((dstr1[i-1] - '0')+(dstr1[i-2] -'0')))+'0';
		if(dstr1[i] > '1'|| dstr1[i] < '0')
		{
			flag1 = true;
			break;
		}
		if(i == (Length - 1))
		{
			if((msg[i]-'0') != ((dstr1[i]-'0') +(dstr1[i-1] - '0')))
			{
				flag1 = true;
			}
		}

	}
	

	i = 0;
	while((Length > 1) && (++i < Length))
	{
		if(i ==1)
			dstr2[i] = ((msg[i-1] - '0')-(dstr2[i-1] - '0')) + '0';
		else
			dstr2[i] = ((msg[i-1] - '0')-((dstr2[i-1] - '0')+(dstr2[i-2] -'0')))+'0';
		if(dstr2[i] > '1' || dstr2[i] < '0')
		{
			flag2 = true;
			break;
		}
		if(i == (Length - 1))
		{
			if((msg[i]-'0') != ((dstr2[i]-'0') +(dstr2[i-1] - '0')))
			{
				flag2 = true;
			}
		}


	}
	j = 0;

	if(Length == 1)
	{
		if(msg.find('0') == 0)
			flag2 = true;
		if(msg.find('1') == 0)
			flag1 = true;
		if((msg.find('2') == 0) || (msg.find('3') == 0))
		{
			flag1 = true;
			flag2 = true;
		}
	}
				
	if(flag1 == true)
	{
		decodedstr.push_back("None");
	}
	else
	{
		string temp;
		while(j<Length)
		{
			temp +=dstr1[j];
			j++;
		}
		decodedstr.push_back(temp);

	}
	j = 0;
	if(flag2 == true)
	{
		decodedstr.push_back("None");
	}
	else
	{
		string temp;
		while(j<Length)
		{
			temp+=dstr2[j];
			j++;
		}
		decodedstr.push_back(temp);
	}
	return decodedstr;
}

int main()
{
	string s;
	vector<string> vstr;
	binarycode bc;
	cout<<"Enter the string to be decrypted"<<endl;
	cin>>s;
	vstr = bc.decode(s);
	cout<<vstr[0]<<","<<vstr[1]<<endl;
}
	


