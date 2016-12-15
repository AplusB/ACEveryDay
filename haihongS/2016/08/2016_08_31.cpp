#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;
typedef long long ll;
const int maxn=2e4+9;

int num[maxn],dp[maxn],len[maxn];

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;i++)
			scanf("%d",&num[i]);
		for(int i=0;i<maxn;i++)
		{
			dp[i]=len[i]=1;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=i-1;j>=0;j--)
			{
				if(num[i]>num[j]) continue;
				else if(num[i]<num[j])
				{
					if(len[j]+1==len[i])
						dp[i]=dp[j]+dp[i];
					else if(len[j]+1>len[i])
						dp[i]=dp[j],len[i]=len[j]+1;
				}
				else
				{
					if(len[i]==1)
						dp[i]=0;
					break;
				}
			}
		}
		int maxx=0;
		for(int i=0;i<n;i++)
			maxx=max(maxx,len[i]);
		int ans=0;
		for(int i=0;i<n;i++)
		{
			if(len[i]==maxx)
				ans+=dp[i];
		}
		printf("%d %d\n",maxx,ans);
	}
	return 0;
}
