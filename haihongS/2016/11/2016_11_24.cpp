#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=2e5+60;
const double inf=1e9;
const double eps=1e-12;

struct II
{
	ll a,b;
}num[maxn];

int cmp(II x,II y);

int main()
{
	int n;
	ll r,avg;
	while(~scanf("%d%lld%lld",&n,&r,&avg))
	{
		ll sum=0;
		for(int i=0;i<n;i++)
		{
			scanf("%lld%lld",&num[i].a,&num[i].b);
			sum+=num[i].a;
		}
		sort(num,num+n,cmp);
		ll del=n*avg-sum;
		ll ans=0;
		for(int i=0;i<n;i++)
		{
			if(del<=0) break;
			if(num[i].a==r) continue;
			ll d1=r-num[i].a;
			ll d2=del;
			ll dd=min(d1,d2);
			del-=dd,num[i].a+=dd;
			ans+=dd*num[i].b;
		}
		printf("%lld\n",ans);

	}
	return 0;
}

int cmp(II x,II y)
{
	return x.b<y.b;
}
