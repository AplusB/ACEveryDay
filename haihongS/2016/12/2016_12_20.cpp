#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1e5+60;
const ll inf=2e9+9;
const double eps=1e-12;

int n,m;
ll a[maxn],b[maxn];
int flag[maxn];

int judge(ll v);

int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		for(int i=0;i<n;i++)
			scanf("%lld",&a[i]);
		for(int i=0;i<m;i++)
			scanf("%lld",&b[i]);
		sort(a,a+n);
		sort(b,b+m);
		ll lt,rt,mid,ans;
		lt=0,rt=inf,ans=inf;
		while(lt<=rt)
		{
			mid=lt+(rt-lt)/2;
			if(judge(mid))
			{
				ans=min(ans,mid);
				rt=mid-1;
			}
			else
				lt=mid+1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

int judge(ll v)
{
	memset(flag,0,sizeof(flag));
	int pos=0;
	for(int i=0;i<m;i++)
	{
		while(pos<n && b[i]-v<=a[pos] && a[pos]<=b[i]+v)
		{
			flag[pos]++;
			pos++;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(flag[i]==0) return 0;
	}
	return 1;
}
