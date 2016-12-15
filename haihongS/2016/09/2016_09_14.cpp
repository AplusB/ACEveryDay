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
const int maxn=1e5+200;
const double eps=1e-9;
const ll inf=1e12;

vector<int> G[maxn];
int root,rr[maxn];
int vs[2*maxn],ff[2*maxn],ee[2*maxn],sz;
ll a[maxn];

vector<ll> dat[8*maxn];


void add_edge(int u,int v);
void dfs(int node);
void build(int node,int l,int r);
int query(int i,int j,ll x,int k,int l,int r);


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		for(int i=0;i<maxn;i++)
		{
			G[i].clear();
			rr[i]=0;
		}
		for(int i=0;i<8*maxn;i++)
		{
			dat[i].clear();
		}
		int n;
		ll k;
		scanf("%d%lld",&n,&k);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(int i=0;i<n-1;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add_edge(u,v);
			rr[v]++;
		}
		for(int i=1;i<=n;i++)
		{
			if(rr[i]==0)
			{
				root=i;break;
			}
		}
		sz=0;
		dfs(root);
		build(0,0,sz);
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			int l=ff[i]+1,r=ee[i];
			if(l>=r) continue;
			int v;
			if(a[i]==0)
				v=query(l,r,inf,0,0,sz);
			else
				v=query(l,r,k/a[i],0,0,sz);
			ans+=(ll)v;
		}
		printf("%lld\n",ans/2);
	}
	return 0;
}

int query(int i,int j,ll x,int k,int l,int r)
{
	if(j<=l || r<=i)
		return 0;
	else if(i<=l && r<=j)
		return upper_bound(dat[k].begin(),dat[k].end(),x)-dat[k].begin();
	else
	{
		int lc=query(i,j,x,k*2+1,l,(l+r)/2);
		int rc=query(i,j,x,k*2+2,(l+r)/2,r);
		return lc+rc;
	}
}

void build(int node,int l,int r)
{
	if(r-l==1)
	{
		dat[node].push_back(a[vs[l]]);
		return ;
	}
	int lt=2*node+1,rt=2*node+2;
	build(lt,l,(l+r)/2);
	build(rt,(l+r)/2,r);
	dat[node].resize(r-l);
	merge(dat[lt].begin(),dat[lt].end(),
		  dat[rt].begin(),dat[rt].end(),
		  dat[node].begin()
		 );
}

void dfs(int node)
{
	vs[sz]=node;
	ff[node]=sz;
	sz++;
	int len=G[node].size();
	for(int i=0;i<len;i++)
	{
		int nx=G[node][i];
		dfs(nx);
	}
	vs[sz]=node;
	ee[node]=sz;
	sz++;
}

void add_edge(int u,int v)
{
	G[u].push_back(v);
}
