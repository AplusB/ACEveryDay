#include<iostream>
#include<string>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;

		while(s[0]!='.')
			s.erase(0,1);

		int n;
		cin>>n;

		if(n<s.length())
		{
			cout<<s[n]<<endl;
		}
		else
			cout<<0<<endl;
	}
}
