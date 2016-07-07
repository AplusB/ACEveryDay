//poj1503

#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

char s[110];
int dp[110];
int ans[110];
int num;
int Tmax;

void solve()
{
	for(int i=0;i<num;i++)
	{
		ans[i]=ans[i]+dp[i];
		if(ans[i]>=10)
		{
			ans[i]%=10;
			ans[i+1]+=1;
		}
	}
}

int main() 
{
	memset(ans,0,sizeof(ans));
	Tmax=0;
	while(scanf("%s",s))
	{
		if(strcmp(s,"0")==0)
			break;
		int len;
		len=strlen(s);
		num=0;
		for(int i=len-1;i>=0;i--)
		{
			dp[num++]=s[i]-48;
		}
		solve();
	}
	int flag=0;
	for(int i=101;i>=0;i--)
	{
		if(ans[i])
		{
			flag=1;
		}
		if(flag)
			printf("%d",ans[i]);
	}
	return 0;
} 





