//hdoj  1827


//很死板的题，模板题的一样的... 

#include<cstdio>
#include<queue>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;
#define INF 9999999
#define mod 1000000007
#define N 1050
typedef long long LL;
	
struct asd{
	int to;
	int next;
};
asd q[N*2];
int head[N*2];
int tol;

int low[N];
int dfn[N];
bool vis[N];
int n,m;
int sta[N];
int cost[N];
int in[N];
int incos[N];
int ru[N];
int tp,p;
int sum;

void tarjan(int u)
{
	dfn[u]=low[u]=++tp;
	sta[++p]=u;
	vis[u]=1;
	
	for(int k=head[u];k!=-1;k=q[k].next)
	{
		int i=q[k].to;
		if(!dfn[i])
		{
			tarjan(i);
			low[u]=min(low[i],low[u]);
		}
		else if(vis[i])
		{
			low[u]=min(low[u],dfn[i]);	
		}
	}
	if(dfn[u]==low[u])
	{
		++sum;
		int temp;
		while(1)
		{
			temp=sta[p];
			vis[temp]=0;
			in[temp]=sum;
			incos[sum]=min(incos[sum],cost[temp]);
			p--;
			if(temp==u)
			{
				break;
			}
			
		}
	}
}

void solve_rudu()
{
	memset(ru,0,sizeof(ru));
	
	for(int i=1;i<=n;i++)
	{
		for(int k=head[i];k!=-1;k=q[k].next)
		{
			int ss=q[k].to;
			if(in[ss]!=in[i])
				ru[in[ss]]++;
		}
	}
	int ans=0;
	int ccs=0;
	for(int i=1;i<=sum;i++)
	{
		if(!ru[i])
		{
			ans++;
			ccs+=incos[i];
		}
	}
	printf("%d %d\n",ans,ccs);
}

void init()
{
	tol=0;
	memset(dfn,0,sizeof(dfn));
	memset(head,-1,sizeof(head));
	memset(vis,0,sizeof(vis));
	memset(incos,INF,sizeof(incos));
}

void add(int a,int b)
{
	q[tol].to=b;
	q[tol].next=head[a];
	head[a]=tol++;
}

int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&cost[i]);
		}
		init();
		for(int i=0;i<m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,b);
		}
		sum=tp=p=0;
		for(int i=1;i<=n;i++)
		{
			if(!dfn[i])
			{
				tarjan(i);
			}
		}
		solve_rudu();		
	}
}

