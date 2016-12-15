/* ***********************************************
Author        :shootPlane
Created Time  :2016年06月08日 星期三 22时05分57秒
File Name     :4725.cpp
Blog          :http://haihongblog.com
************************************************ */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <stack>
#include <utility>

using namespace std;
typedef long long ll;
const int maxn=1e5+9;
const int inf=0x3f3f3f3f;

typedef pair<int,int> P;

struct edge
{
	int to,cost;
};

int n,m,c;

vector<edge> G[3*maxn];
int d[3*maxn];

void Dijkstra();
void add(int x,int y,int w);

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
	scanf("%d",&t);
	int cass=1;
	while(t--)
	{
		for(int i=0;i<3*maxn;i++) G[i].clear();
		scanf("%d%d%d",&n,&m,&c);
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			add(i,n+2*x-1,0);
			add(n+2*x,i,0);
		}

		for(int i=0;i<m;i++)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w);
			add(v,u,w);
		}
		
		for(int i=1;i<n;i++)
		{
			add(n+i*2-1,n+2*(i+1),c);
			add(n+2*(i+1)-1,n+2*i,c);
		}

		Dijkstra();
		printf("Case #%d: ",cass++);

		if(d[n]==inf)
			printf("-1\n");
		else
			printf("%d\n",d[n]);
	}
    return 0;
}


void Dijkstra()
{
	priority_queue<P,vector<P>,greater<P> > go;
	while(!go.empty()) go.pop();
	
	for(int i=0;i<3*maxn;i++) d[i]=inf;
	d[1]=0;
	go.push(P(0,1));

	while(!go.empty())
	{
		P tp=go.top();go.pop();
		int v=tp.second;
		if(d[v]<tp.first) continue;
		for(int i=0;i<G[v].size();i++)
		{
			edge next=G[v][i];
			if(d[next.to]>d[v]+next.cost)
			{
				d[next.to]=d[v]+next.cost;
				go.push(P(d[next.to],next.to));
			}
		}
	}
}

void add(int x,int y,int w)
{
	edge tmp;
	tmp.cost=w;
	tmp.to=y;
	G[x].push_back(tmp);
}

