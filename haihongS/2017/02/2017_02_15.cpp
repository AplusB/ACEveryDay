#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=100+3;
const ll mod=1e9+7;
const int inf=2e9+9;
double eps=1e-9;
double pi=acos(-1.0);

typedef pair<int,int> P;

int n,G[maxn][maxn],fa[maxn],flag[maxn];

struct II
{
	int u,v,c;
};

vector<II> aha,ans;

int ff(int x);
void uu(int x,int y);
int cmp(II x,II y);
int dfs(int v);
int cmp1(II x,II y);

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		aha.clear();
		memset(fa,-1,sizeof(fa));
		memset(flag,0,sizeof(flag));
		ans.clear();
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&G[i][j]);
		dfs(1);
		int ok=1;
		for(int i=1;i<=n;i++)
		{
			if(flag[i]==0)
			{
				ok=0;break;
			}
		}
		if(ok==0)
		{
			puts("-1");continue;
		}

		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(G[i][j]==0) continue;
				II now;
				now.u=i,now.v=j,now.c=G[i][j];
				aha.push_back(now);
			}
		}
		sort(aha.begin(),aha.end(),cmp);
		int len=aha.size();
		for(int i=0;i<len;i++)
		{
			int u=aha[i].u,v=aha[i].v,c=aha[i].c;
			int fu=ff(u),fv=ff(v);
			if(fu==fv) continue;
			uu(u,v);
			if(u>v) swap(aha[i].v,aha[i].v);
			ans.push_back(aha[i]);
		}
		sort(ans.begin(),ans.end(),cmp1);
		len=ans.size();
		for(int i=0;i<len;i++)
		{
			if(i!=0) printf(" ");
			printf("%d %d",ans[i].u,ans[i].v);
		}
		printf("\n");
	}
	return 0;
}

int cmp1(II x,II y)
{
	if(x.u==y.u)
		return x.v<y.v;
	return x.u<y.u;
}

int dfs(int v)
{
	flag[v]=1;
	for(int i=1;i<=n;i++)
	{
		if(G[v][i]==0) continue;
		if(flag[i]==1) continue;
		dfs(i);
	}
	return 0;
}

int cmp(II x,II y)
{
	if(x.c!=y.c) return x.c<y.c;
	else if(x.u!=y.u) return x.u<y.u;
	else return x.v<y.v;
}

void uu(int x,int y)
{
	int fx=ff(x),fy=ff(y);
	if(fx==fy) return ;
	if(abs(fa[fx])>=abs(fa[fy]))
	{
		fa[fx]+=fa[fy];
		fa[fy]=fx;
	}
	else
	{
		fa[fy]+=fa[fx];
		fa[fx]=fy;
	}
}

int ff(int x)
{
	if(fa[x]<0) return x;
	return fa[x]=ff(fa[x]);
}
