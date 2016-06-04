#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define endl '\n'

using namespace std;

const int MAXN = 15;

long long dp[2][1 << MAXN];
int n,m;

int main()
{
	while(scanf("%d %d",&n,&m) == 2)
	{
		if(n == m && !m)break;
		
		memset(dp,0,sizeof(dp));
		if(n < m)swap(n,m);
		
		int i,j,k;
		int cur = 0;
		dp[cur][(1 << m) - 1] = 1;
		for(i = 0;i < n;i++)
		{
			for(j = 0;j < m;j++)
			{
				cur ^= 1;
				memset(dp[cur],0,sizeof(dp[cur]));
				for(k = 0;k < (1 << m);k++)
				{
					if(k & (1 << m - 1))dp[cur][(k << 1) ^ (1 << m)] += dp[1 - cur][k];
					if(i && !(k &(1 << m - 1)))dp[cur][(k << 1)|1] += dp[1 - cur][k];
					if(j && (k & (1 << m - 1)) && !(k & 1))dp[cur][(k << 1)^ (1 << m)|(1 << 1)^1] += dp[1 - cur][k];
				}
			}
		}
		
		cout << dp[cur][(1 << m) - 1] << endl;
	}
	return 0;
}
