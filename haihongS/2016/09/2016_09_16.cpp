#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;
const int maxn=3000+9;
const ll inf=1e13+9;

int a[maxn];
int id[maxn],pos;
ll dp[maxn][maxn];
map<int,int> aha;


int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		aha.clear();
		pos=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			a[i]-=i;
			id[pos++]=a[i];
		}
		sort(id,id+pos);
		for(int i=0;i<maxn;i++)
		{
			for(int j=0;j<maxn;j++)
			{
				if(i==0) dp[i][j]=0;
				else dp[i][j]=inf;
			}
		}

		for(int i=1;i<=n;i++)
		{
			ll minn=inf;

			for(int j=0;j<pos;j++)
			{
				minn=min(minn,dp[i-1][j]);
				dp[i][j]=minn+(ll)abs(a[i]-id[j]);
			}
		}

		ll ans=inf;
		for(int i=0;i<pos;i++)
		{
			ans=min(ans,dp[n][i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

