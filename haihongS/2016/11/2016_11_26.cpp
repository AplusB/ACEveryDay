#include <bits/stdc++.h>

using namespace std;
const int maxn=2e5+9;
const int inf=2e9+9;
typedef long long ll;

struct II
{
	ll a,b,c,d;
}num[maxn],qq[maxn];

ll dp[maxn];

int cmp(II x,II y);
int bi(int l1,int r1,ll v);

int main()
{
	ll n,m,k;
	while(~scanf("%lld%lld%lld",&n,&m,&k))
	{
		ll x,s;
		scanf("%lld%lld",&x,&s);
		for(int i=0;i<m;i++)
			scanf("%lld",&num[i].a);
		for(int i=0;i<m;i++)
			scanf("%lld",&num[i].b);
		num[m].a=x,num[m].b=0;

		sort(num,num+m+1,cmp);
		dp[m]=num[m].a;
		for(int i=m-1;i>=0;i--)
			dp[i]=min(dp[i+1],num[i].a);

		for(int i=0;i<k;i++)
			scanf("%lld",&qq[i].c);
		for(int i=0;i<k;i++)
			scanf("%lld",&qq[i].d);
		
		ll ans=n*x;
		int pp=bi(0,m,s);
		ans=min(ans,dp[pp]*n);
		for(int i=0;i<k;i++)
		{
			if(qq[i].d>s) continue;
			ll own=s-qq[i].d;
			ll now=qq[i].c;
			if(now>=n)
			{
				ans=0;break;
			}
			now=n-now;
			int pos=bi(0,m,own);
			now=now*dp[pos];
			ans=min(ans,now);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

int bi(int l1,int r1,ll v)
{
	int lt=l1,rt=r1,mid,ans=r1;
	while(lt<=rt)
	{
		mid=lt+(rt-lt)/2;
		if(num[mid].b<=v)
		{
			ans=mid;
			rt=mid-1;
		}
		else
			lt=mid+1;
	}
	return ans;
}

int cmp(II x,II y)
{
	if(x.b==y.b)
		return x.a>y.a;
	return x.b>y.b;
}
