#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
#define endl '\n'

using namespace std;

const int MAXN = 54005;
const int INF = 0x3f3f3f3f;
struct node{
	int e,v;
};

vector<node> g[MAXN];
int n,Min,Max,d[MAXN],visit[MAXN];

void spfa()
{
	memset(visit,0,sizeof(visit));
	memset(d,-0x3f,sizeof(d));
	
	queue<int> que;
	que.push(Min);
	d[Min] = 0;
	
	while(!que.empty())
	{
		int x = que.front();
		que.pop();
		
		visit[x] = 0;
		int i;
		for(i = 0;i < g[x].size();i++)
		{
			node temp = g[x][i];
			if(d[temp.e] >= d[x] + temp.v)continue;
			d[temp.e] = d[x] + temp.v;
			if(visit[temp.e])continue;
			que.push(temp.e);
			visit[temp.e] = 1;
		}
	}
}

int main()
{
	while(scanf("%d",&n) == 1)
	{
		Min = INF;
		Max = -INF;
		
		int i,u,v,w;
		
		for(i = 0;i <= MAXN;i++)g[i].clear();
		
		for(i = 0;i < n;i++)
		{
			scanf("%d %d %d",&u,&v,&w);
			node temp;
			temp.e = v + 1,temp.v = w;
			g[u].push_back(temp);
			//temp.e = u,temp.v = -w;
			//g[v + 1].push_back(temp);
			
			Min = min(Min,u);
			Max = max(Max,v + 1);
		}
		
		for(i = Min;i < Max;i++)
		{
			node temp;
			temp.e = i + 1,temp.v = 0;
			g[i].push_back(temp);
			temp.e = i,temp.v = -1;
			g[i + 1].push_back(temp);
		}
		
		spfa();
		
		cout << d[Max] << endl;
	}
	return 0;
}
/*
3
1 2 1
2 3 2
1 3 2
*/ 
