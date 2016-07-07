// 475B

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
#define ls 2*i
#define rs 2*i+1
#define up(i,x,y) for(i=x;i<=y;i++)
#define down(i,x,y) for(i=x;i>=y;i--)
#define mem(a,x) memset(a,x,sizeof(a))
#define w(a) while(a--)
#define LL long long
const double pi = acos(-1.0);
#define Len 200005
#define mod 19999997
const int INF = 0x3f3f3f3f;
#define exp 1e-6

struct asd{
	int to;
	int next;
};
asd q[1000010];
int tol,head[1000010];

int dfn[1010],low[1010];
int st[1010],used[1010];
bool vis[1010];
int tp,p;
int num,n,m,flag;

char a[30],b[30];

void tarjan(int u)
{
	dfn[u]=low[u]=++p;
	st[tp++]=u;
	vis[u]=1;
	
	for(int i=head[u];i!=-1;i=q[i].next)
	{
		int v=q[i].to;
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[v],low[u]);
		}
		else if(vis[v])
			low[u]=min(dfn[v],low[u]);
	}
	
	if(low[u]==dfn[u])
	{
		flag++;
		int temp;
		while(1)
		{
			temp=st[--tp];
			vis[temp]=0;
			if(temp==u)
				break; 
		}
	}
}

void init()
{
	memset(head,-1,sizeof(head));
	tol=flag=0;
	tp=p=0;
	memset(vis,0,sizeof(vis));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
}

void add(int u,int v)
{
	q[tol].to=v;
	q[tol].next=head[u];
	head[u]=tol++;
}

void add_edge()
{
	for(int i=1;i<=n;i++)
	{
		int s=(i-1)*m;
		if(a[i]=='>')
			for(int j=1;j<m;j++)
				add(s+j,s+j+1);
		else
			for(int j=m;j>1;j--)
				add(s+j,s+j-1);
	}
	for(int i=1;i<=m;i++)
	{
		int s=i;
		if(b[i]=='v')
			for(int j=1;j<n;j++)
				add(s+(j-1)*m,s+j*m);
		else
			for(int j=n;j>1;j--)
				add(s+(j-1)*m,s+(j-2)*m);
	}
}

int main()
{
	//cin>>n>>m;
	scanf("%d%d",&n,&m);
	scanf("%s%s",a+1,b+1);
	
	init();
	add_edge();
	
	for(int i=1;i<=n*m;i++)
	{
		if(!dfn[i])
			tarjan(i);
	}
	
	if(flag==1)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
/*
3 3
><>
v^v
*/
