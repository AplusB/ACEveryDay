#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2e3+9;
const ll inf=2e9+9;
const ll mod=1e9+7;
double eps=1e-9;
double pi=acos(-1.0);

struct II
{
	ll a,b,sum;
}num[maxn];

ll pre[maxn],dp[maxn][maxn];

int cmp(II x,II y);

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld",&num[i].a,&num[i].b);
			num[i].sum=num[i].a+num[i].b;
		}
		ll h;
		scanf("%lld",&h);
		sort(num+1,num+1+n,cmp);
		pre[0]=0;
		for(int i=1;i<=n;i++)
			pre[i]=pre[i-1]+num[i].a;
		for(int i=0;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
				dp[i][j]=inf;
		}
		dp[0][0]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=i;j++)
			{
				ll t1=dp[i-1][j]-num[i].a;
				ll t2=dp[i-1][j-1];
				t2=max(t2,h-(pre[i]+num[i].b));
				dp[i][j]=min(t1,t2);
			}
		}
		for(int i=n;i>=0;i--)
		{
			if(dp[n][i]<=0)
			{
				printf("%d\n",i);break;
			}
		}
	}
	return 0;
}

int cmp(II x,II y)
{
	return x.sum>y.sum;
}
