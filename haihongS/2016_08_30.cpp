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
const int maxn=2e3+9;

struct II
{
	int p,q,v;
}num[maxn];

int dp[5009];

int cmp(II a,II b);

int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		for(int i=0;i<n;i++)
			scanf("%d%d%d",&num[i].p,&num[i].q,&num[i].v);
		sort(num,num+n,cmp);
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++)
		{
			for(int j=m;j>=num[i].q;j--)
			{
				dp[j]=max(dp[j],dp[j-num[i].p]+num[i].v);
			}
		}
		printf("%d\n",dp[m]);

	}
	return 0;
}

int cmp(II a,II b)
{
	return a.q-a.p<b.q-b.p;
}
