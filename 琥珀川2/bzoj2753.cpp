//最小树形图
#include <stdio.h>
#include <queue>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#define MAXN 100050
#define MAXM 2000050

using namespace std;

struct Line
{
	int u,v; //起点、终点
	int w; //边权
	int next; //下一条边
}edge[MAXM]; //边集

queue<int>q; //bfs用队列

int f[MAXN]; //并查集用

long long int dis=0; //dis=最短距离

int n,m;
int cnt=0,tot=0;//cnt=可经过的点总数,tot=有效边的总数.
int visit[MAXN],high[MAXN]; //visit[i]=1表示点i访问过,high[i]=点i的高度

int head[MAXM];

//先按边的终点高度降序排序，高度相同的按边权升序排序
//（简写技巧）
int cmp(Line a,Line b)
{
	return (high[b.v]<high[a.v]) || ((high[a.v]==high[b.v])&&(a.w<b.w));
}

//带路径压缩的并查集查找
int findSet(int x)
{
	if(f[x]==x)
		return x;
	return f[x]=findSet(f[x]);
}

//添加边s->t,边权为n
void AddLine(int s,int t,int n)
{
	edge[tot].u=s;
	edge[tot].v=t;
	edge[tot].w=n;
	edge[tot].next=head[s];
	head[s]=tot++;
}

void init()
{
	int i,j;

	memset(head,-1,sizeof(head));

	scanf("%d%d",&n,&m);

	for(i=1;i<=n;i++)
	{
		scanf("%d",&high[i]);
	}

	for(i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);

		//加边
		if(high[u]>=high[v])
			AddLine(u,v,w);
		if(high[v]>=high[u])
			AddLine(v,u,w);
	}
}

void bfs() //bfs找可走的路
{
	int i,x;
	q.push(1);
	visit[1]=1; //非常重要！！！*****************************************
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		cnt++;
		//注意for的用法
		for(i=head[x];i!=-1;i=edge[i].next)
		{
			int y=edge[i].v; //下一条边的终点
			if(!visit[y])
			{
				visit[y]=1;
				q.push(y); //若该点未被访问过，标记，入队
			}
		}
	}
}

//kruscal求最小生成树
void kruscal()
{
	int i,j,rootu,rootv,u,v;
	sort(edge,edge+tot,cmp);

	//并查集初始化
	for(i=1;i<=n;i++)
		f[i]=i;

	for(i=0;i<tot;i++)
	{
		u=edge[i].u;
		v=edge[i].v;

		if(!visit[u]||!visit[v])
			continue; //若边i的起点和终点未访问过，则表明边i是废边(与起点1不连通)

		rootu=findSet(u);
		rootv=findSet(v);

		if(rootu!=rootv)
		{
			f[rootu]=rootv; //没合并就合并
			dis+=edge[i].w; //累加最短距离
		}
	}
}

int main()
{
	init();
	bfs();
	kruscal();
	printf("%d %lld\n",cnt,dis);
	return 0;
}
