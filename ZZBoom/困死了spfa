//在各种不利的因素下，我居然就这么水过了这题最短路，然而还wa了一次，因为路是双向的。。。
//这题姿势很多啊，但自从会了国产spfa就是最短路能搞的就是spfa,优点太多了！！！
//也是瞎几把打，还是在Dev C++上打完编译，执行，然后过了，困得要死。。。

#include<cstdio>
#include<iostream>
#include<string.h>
#include<queue>
#include<map>
#include<stack>
#include<algorithm>
using namespace std;
#define N 260
#define INF 0x3f3f3f3f

struct asd{
	int to;
	int w;
	int next;
};
int tol,head[N*10];
asd q[N*10];
int dis[N];
int n;
queue<int>que;
bool vis[N];
int used[N];

void add(int a,int b,int c)
{
	q[tol].to=b;
	q[tol].w=c;
	q[tol].next=head[a];
	head[a]=tol++;
}


void spfa(int s,int t)
{
	while(!que.empty())
		que.pop();
	for(int i=0;i<n;i++)
		dis[i]=INF;
	memset(vis,0,sizeof(vis));
	memset(used,0,sizeof(used));
	que.push(s);
	vis[s]=1;
	dis[s]=0;
	while(!que.empty())
	{
		int u=que.front();
		que.pop();
		used[u]++;
		vis[u]=0;
		for(int k=head[u];k!=-1;k=q[k].next)
		{
			int i=q[k].to;
			if(dis[i]>dis[u]+q[k].w)
			{
				dis[i]=q[k].w+dis[u];
				if(!vis[i])
				{
					que.push(i);
					vis[i]=1;
					used[i]++;
					if(used[i]>n)
					{
						printf("-1\n");
						return;
					}
				}
			}
		}
	}
	if(dis[t]!=INF)
	printf("%d\n",dis[t]);
	else
	printf("-1\n");
}

int main()
{
	int m;
	while(~scanf("%d%d",&n,&m))
	{
		int a,b,c;
		tol=0;
		memset(head,-1,sizeof(head));
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			add(a,b,c);
			add(b,a,c);
		}
		int s,t;
		scanf("%d%d",&s,&t);
		spfa(s,t);
	}
	return 0;
}

