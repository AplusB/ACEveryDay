//poj1915

#include<cstdio>
#include<queue>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define N 310
#define INF 0X3f3f3f3f

bool vis[N][N];
int n,m;
int sx,sy;
int ex,ey;

int dx[8]={1,1,2,2,-1,-1,-2,-2};
int dy[8]={-2,2,1,-1,-2,2,-1,1};

struct asd{
	int x,y;
	int step;
};
queue<asd>q;

void BFS()
{
	while(!q.empty())
		q.pop();
	
	asd no,ne;
	no.x=sx;
	no.y=sy;
	no.step=0;
	q.push(no);

	while(!q.empty())
	{
		no=q.front();q.pop();
		if(no.x==ex&&no.y==ey)
		{
			printf("%d\n",no.step);
			return; 
		}
		for(int i=0;i<8;i++)
		{
			int aa=dx[i]+no.x;
			int bb=dy[i]+no.y;
			if(aa<0||bb<0||aa>=n||bb>=n||vis[aa][bb])
				continue;
			vis[aa][bb]=1;
			ne.step=no.step+1;
			ne.x=aa;
			ne.y=bb;
			q.push(ne);
		}
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(vis,0,sizeof(vis));
		scanf("%d%d",&sx,&sy);
		scanf("%d%d",&ex,&ey);
		BFS();
	}
	return 0;
}


