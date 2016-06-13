#include<bits/stdc++.h>
using namespace std;

int main()
{
	int c,a,b;
	cin>>a>>b;
	c=a+b;
	if(c<0) 
	{
		printf("-");
		c=-c;
	}
	string s="";
	if(c<=999) printf("%d\n",c);
	else
	{
		int cnt=0;
		while(c)
		{
			int t=c%10;
			c/=10;
			s+=t+'0';
			cnt++;
			if(cnt==3&&c)
			{
				s+=',';
				cnt=0;
			}
		}
		for(int i=s.length()-1;i>=0;i--)
			printf("%c",s[i]);
		printf("\n");
	}
	return 0;
}
