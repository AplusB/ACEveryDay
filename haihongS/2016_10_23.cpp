#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e5+202;
const int inf=2e9+9;
const ll mod=1e9+7;
const double eps=1e-9;

int d[maxn],mark[maxn],ok[maxn];
ll a[maxn];
int n,m;

int judge(int x);

int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&d[i]);
		}
		for(int i=1;i<=m;i++)
			scanf("%lld",&a[i]);
		int flag=0;
		int lt,rt,mid,ans=n;
		lt=1,rt=n;
		while(lt<=rt)
		{
			mid=lt+(rt-lt)/2;
			if(judge(mid)==1)
			{
				flag=1;
				ans=min(ans,mid);
				rt=mid-1;
			}
			else
				lt=mid+1;
		}
		if(flag==0)
			printf("-1\n");
		else
		{
			printf("%d\n",ans);
		}
	}

	return 0;
}


int judge(int x)
{
	for(int i=0;i<maxn;i++)
	{
		mark[i]=ok[i]=0;
	}
	for(int i=x;i>=1;i--)
	{
		int v=d[i];
		if(v==0) continue;
		mark[v]=max(mark[v],i);
	}
	int ff=0;
	for(int i=1;i<=x;i++)
	{
		int v=d[i];
		if(mark[v]==i)
		{
			if(ff<a[v]) return -1;
			ff-=a[v];
			ok[v]=1;
		}
		else
		{
			ff++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(ok[i]==0) return -1;
	}
	return 1;
}
