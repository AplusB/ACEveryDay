#include<iostream>
#include<string.h>
using namespace std;

#define maxn 100005

int head[maxn];
int vis[maxn];

struct Edge{
	int to;
	int next;
}edge[maxn];

int v;

void dfs(int now)
{
	for(int k=head[now];k!=-1;k=edge[k].next)
	{
		if(vis[k]==0)
		{
			vis[k]=1;
		dfs(edge[k].to);
		}
	}
	cout<<now<<endl;
}

int main()
{
	int m,n;
	while(cin>>m>>n)
	{
		v=0;
		memset(vis,0,sizeof(vis));
		memset(head,-1,sizeof(head));

		for(int i=0;i<n;i++)
		{
			int a,b;
			cin>>a>>b;

			edge[v].to=b;
			edge[v].next=head[a];
			head[a]=v++;

			edge[v].to=a;
			edge[v].next=head[b];
			head[b]=v++;
		}

		dfs(1);
	}
	return 0;
}
