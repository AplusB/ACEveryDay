#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cstdlib>
#define endl '\n'

using namespace std;

const int MAXN = 1e5 + 5;
struct node
{
	int v;
	int w;
	int next;
}edge[MAXN * 4];

int head[MAXN * 4],d[MAXN],visit[MAXN],n,m,cur;
int cnt[MAXN];

void add_edge(int u,int v,int w)
{
	edge[cur].v = v;
	edge[cur].w = w;
	edge[cur].next = head[u];
	head[u] = cur++;
}

bool spfa()
{
	memset(visit,0,sizeof(visit));
	memset(cnt,0,sizeof(cnt));
	memset(d,-0x3f,sizeof(d));
	
	int cont = 0;
	queue<int> que;
	d[0] = 0;
	que.push(0);
	
	while(!que.empty())
	{
		int x = que.front();
		que.pop();
		visit[x] = 0;
		
		int i;
		for(i = head[x];i != -1;i = edge[i].next)
		{
			if(d[edge[i].v] < d[x] + edge[i].w)
			{
				d[edge[i].v] = d[x] + edge[i].w;
				if(visit[edge[i].v])continue;
				que.push(edge[i].v);
				visit[edge[i].v] = 1;
				cnt[edge[i].v]++;
				if(cnt[edge[i].v] > n)return false;
			}
		}
	}
	
	return true;
}
int main()
{
	while(scanf("%d %d",&n,&m) == 2)
	{
		memset(head,-1,sizeof(head));
		cur = 0;
		int i,u,v,w;
		char ch;
		for(i = 0;i < m;i++)
		{
			getchar();
			scanf("%c",&ch);
			if(ch == 'P')
			{
				scanf("%d %d %d",&u,&v,&w);
				add_edge(u,v,w);
				add_edge(v,u,-w);
			}
			else
			{
				scanf("%d %d",&u,&v);
				add_edge(u,v,1);
				//add_edge(v,u,-1);
			}
		}
		
		for(i = 1;i <= n;i++)
		{
			add_edge(0,i,0);
		}
		
		if(spfa())cout << "Reliable" << endl;
		else cout << "Unreliable" << endl; 
		
		//for(i = 1;i <= n;i++)cout << " " << d[i];
		//cout << endl;
	}
	return 0;
}
