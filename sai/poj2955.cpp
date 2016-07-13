#include<iostream>
#include<string>
#include<string.h>
using namespace std;

int dp[105][105];

int main()
{
	string s;
	while(cin>>s)
	{
		if(s=="end")break;
		memset(dp,0,sizeof(dp));
		int len=s.length();

		for(int i=len-2;i>=0;i--)
		{
			for(int j=i+1;j<len;j++)
			{
				dp[i][j]=dp[i+1][j];
				for(int k=i+1;k<=j;k++)
				{
					if((s[i]=='('&&s[k]==')')||(s[i]=='['&&s[k]==']'))
					{
						dp[i][j]=max(dp[i][j],dp[i+1][k-1]+dp[k][j]+2);
					}
				}
			}
		}
		cout<<dp[0][len-1]<<endl;
	}
	return 0;
}
