#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1009;

int fa[maxn];
vector<int> G[maxn];
int flag[maxn];

int findit(int x);
void uu(int x,int y);

int main()
{
	int n,m,x,y;
	while(~scanf("%d%d%d%d",&n,&m,&x,&y))
	{
		for(int i=0;i<maxn;i++)
		{
			fa[i]=-1;
			G[i].clear();
			flag[i]=-1;
		}
		for(int i=0;i<m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for(int i=0;i<x;i++)
		{
			int v;
			scanf("%d",&v);
			flag[v]=1;
		}
		for(int i=0;i<y;i++)
		{
			int v;
			scanf("%d",&v);
			flag[v]=0;
		}
		int ok=1;
		for(int i=1;i<=n;i++)
		{
			int len=G[i].size();
			if(len==0)
			{
				if(flag[i]==-1)
				{
					ok=0;break;
				}
			}
			else
			{
				int fir=G[i][0];
				for(int j=1;j<len;j++)
				{
					int nx=G[i][j];
					uu(fir,nx);
				}
			}
		}
		if(ok==0)
		{
			printf("NO\n");continue;
		}
		for(int i=1;i<=n;i++)
		{
			if(flag[i]==-1) continue;
			int up=findit(i);
			if(flag[up]==-1) flag[up]=flag[i];
			else if(flag[up]!=flag[i])
			{
				ok=0;break;
			}
		}
		if(ok==0)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}

void uu(int x,int y)
{
	int fx=findit(x),fy=findit(y);
	if(fx==fy) return ;
	if(abs(fa[x])>=abs(fa[y]))
	{
		fa[x]+=fa[y];
		fa[y]=x;
	}
	else
	{
		fa[y]+=fa[x];
		fa[x]=y;
	}
	return ;
}

int findit(int x)
{
	if(fa[x]==-1) return x;
	return fa[x]=findit(fa[x]);
}
