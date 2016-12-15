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
const int maxn=300+200;
const ll inf=2e13+9;
const double eps=1e-9;

ll key[maxn],v[maxn],pre[maxn];
ll dp[maxn][maxn];

ll gcd(ll a,ll b);

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%lld",&key[i]);
		for(int i=1;i<=n;i++)
			scanf("%lld",&v[i]);
		pre[0]=0;
		for(int i=1;i<=n;i++)
			pre[i]=pre[i-1]+v[i];
		memset(dp,0,sizeof(dp));

		for(int len=2;len<=n;len++)
		{
			for(int i=1;i<=n;i++)
			{
				int j=i+len-1;
				if(j>n) break;
				for(int k=i;k<=j;k++)
					dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
				if(gcd(key[i],key[j])>1)
				{
					if(i+1==j)
						dp[i][j]=v[i]+v[j];
					else if(dp[i+1][j-1]==pre[j-1]-pre[i])
						dp[i][j]=max(dp[i][j],dp[i+1][j-1]+v[i]+v[j]);
				}
			}
		}
		printf("%lld\n",dp[1][n]);


	}

	return 0;
}

ll gcd(ll a,ll b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
