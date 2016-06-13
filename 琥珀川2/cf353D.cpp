#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int ch=0;
	int m=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='M')
		{
			m++;
		}
		else if(s[i]=='F')
		{
			if(m>0)
			{
				ch=max(ch+1,m);
			}
		}
	}
	cout<<ch<<endl;
	return 0;
}
