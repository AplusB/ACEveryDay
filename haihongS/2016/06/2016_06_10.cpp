/* ***********************************************
Author        :shootPlane
Created Time  :2016年06月10日 星期五 10时27分56秒
File Name     :1062.cpp
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
const int maxn=1e2+9;
const int inf=0x3f3f3f3f;
typedef pair<int,int> P;

struct edge
{
	int to,cost,from;
};


struct II
{
	int p,l,x;
	vector<edge> son;
}num[maxn];

int m,n;
vector<edge> G[maxn];
int d[maxn];

void add(int u,int v,int w);
int Dijkstra(int s);

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(~scanf("%d%d",&m,&n))
	{
		for(int i=0;i<maxn;i++)
		{
			num[i].son.clear();
			G[i].clear();
		}

		for(int i=1;i<=n;i++)
		{
			int p,l,x;
			scanf("%d%d%d",&p,&l,&x);
			num[i].p=p,num[i].l=l,num[i].x=x;
			for(int j=0;j<x;j++)
			{
				int t,v;
				scanf("%d%d",&t,&v);
				edge tmp;
				tmp.from=t,tmp.cost=v;
				num[i].son.push_back(tmp);
			}
		}

		int le=num[1].l;
		for(int i=1;i<=n;i++)
		{
			if(abs(le-num[i].l)>m) continue;
			add(0,i,num[i].p);
			for(int j=0;j<num[i].son.size();j++)
			{
				edge next=num[i].son[j];
				if(abs(le-num[next.from].l)>m) continue;
				add(next.from,i,next.cost);
			}
		}

		int ans=Dijkstra(0);

		printf("%d\n",ans);

	}
    return 0;
}

void add(int u,int v,int w)
{
	edge tmp;
	tmp.to=v,tmp.cost=w;
	G[u].push_back(tmp);
}

int Dijkstra(int s)
{
	int ans=inf;

	for(int i=0;i<maxn;i++)
		d[i]=inf;
	d[s]=0;

	priority_queue<P,vector<P>,greater<P> > aha;
	while(!aha.empty()) aha.pop();

	for(int j=1;j<=n;j++)
	{
		int le=num[j].l;
		aha.push(P(0,s));
		for(int i=0;i<=n;i++) d[i]=inf;
		d[0]=0;
		while(!aha.empty())
		{
			P tp=aha.top();aha.pop();
			int v=tp.second;
			if(tp.first>d[v]) continue;
			for(int i=0;i<G[v].size();i++)
			{
				edge next=G[v][i];
				if(num[next.to].l-le>m) continue;
				if(num[next.to].l<le) continue;
				if(d[next.to]>d[v]+next.cost)
				{
					d[next.to]=d[v]+next.cost;
					aha.push(P(d[next.to],next.to));
				}
			}
		}
		ans=min(ans,d[1]);
	}
	return ans;
}
