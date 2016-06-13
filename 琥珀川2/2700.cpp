#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	while(cin>>s&&s!="#")
	{
		int num=0;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='1')
			{
				num++;
			}
			if(s[i]=='0'||s[i]=='1')
			{
				cout<<s[i];
			}
		}
		if(s[s.length()-1]=='e')
		{
			if(num%2==0)
			{
				cout<<"0"<<endl;
			}
			else
			{
				cout<<"1"<<endl;
			}
		}
		else if(s[s.length()-1]=='o')
		{
			if(num%2==0)
			{
				cout<<"1"<<endl;
			}
			else
			{
				cout<<"0"<<endl;
			}
		}
	}
	return 0;
}
