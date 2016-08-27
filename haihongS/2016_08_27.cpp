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
const int maxn=2000000+9;
const int inf=2e9+9;

int num[maxn],fa[maxn],cnt[maxn],flag[maxn];
bool is_prime[maxn],is_prime_small[maxn];
ll prime[maxn];

void get_prime(ll a,ll b);
int findit(int node);
int uu(int x,int y);

int main()
{
	get_prime(0,maxn-1);
	int pos=0;
	for(int i=2;i<maxn;i++)
	{
		if(is_prime[i]==true)
			prime[pos++]=(ll)i;
	}
	int t;
	scanf("%d",&t);
	int cas=1;
	while(t--)
	{
		ll a,b,p;
		scanf("%lld%lld%lld",&a,&b,&p);
		for(int i=0;i<maxn;i++)
		{
			fa[i]=-1;
			cnt[i]=1;
			flag[i]=0;
		}
		for(int i=0;i<pos;i++)
		{
			ll now=prime[i];
			if(now<p) continue;
			if(now>b) break;
			ll low=a/now;
			if(a%now==0) low=a;
			else low=(low+1)*now;

			ll up=b/now*now;
			for(ll j=low+now;j<=up;j+=now)
			{
				uu((j-a),(low-a));
			}
		}
		int ans=0;
		for(int i=0;i<(int)(b-a+1);i++)
		{
			int root=findit(i);
			if(flag[root]==1) continue;
			flag[root]=1;
			ans++;
		}
		printf("Case #%d: ",cas++);
		printf("%d\n",ans);
	}

	return 0;
}


void get_prime(ll a,ll b)
{
	for(int i=0;(ll)i*i<b;i++) is_prime_small[i]=true;
	for(int i=0;i<b-a;i++) is_prime[i]=true;

	for(int i=2;(ll)i*i<b;i++)
	{
		if(is_prime_small[i])
		{
			for(int j=2*i;(ll)j*j<b;j+=i) is_prime_small[j]=false;
			for(ll j=max(2LL,(a+i-1)/i)*i;j<b;j+=i) is_prime[j-a]=false;
		}
	}
}

int uu(int x,int y)
{
	int fx=findit(x),fy=findit(y);
	if(fx==fy) return 0;
	if(cnt[fx]<=cnt[fy])
	{
		fa[fx]=fy;
		cnt[fy]+=cnt[fx];
	}
	else
	{
		fa[fy]=fx;
		cnt[fx]+=cnt[fy];
	}
	return 0;
}

int findit(int node)
{
	if(fa[node]==-1) return node;
	return fa[node]=findit(fa[node]);
}
