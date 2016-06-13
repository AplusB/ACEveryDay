//拯救天使！！！！！！！好吧水题AC......

#include<cstdio>
#include<queue>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define N 210
#define INF 0X3f3f3f3f
char ma[N][N];
int used[N][N];
bool vis[N][N];
int n,m;
int sx,sy;

int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

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
	int ans=INF;
	while(!q.empty())
	{
		no=q.front();q.pop();
		if(ma[no.x][no.y]=='r')
		{
			ans=min(ans,used[no.x][no.y]);
		}
		for(int i=0;i<4;i++)
		{
			int aa=no.x+dx[i];
			int bb=no.y+dy[i];
			if(aa<0||bb<0||aa>=n||bb>=m||ma[aa][bb]=='#')
				continue;
			if(used[aa][bb]>no.step+1)
			{
				ne.step=no.step+1;
				ne.x=aa;
				ne.y=bb;
				if(ma[aa][bb]=='x')
					ne.step++;
				used[aa][bb]=ne.step;
				q.push(ne);
			}
		}
	}
	if(ans!=INF)
		printf("%d\n",ans);
	else
		printf("Poor ANGEL has to stay in the prison all his life.\n");
}

void Findbegin()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			used[i][j]=INF;
			if(ma[i][j]=='a')
			{
				sx=i;
				sy=j;	
			}
		}
	}
}

int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		for(int i=0;i<n;i++)
		{
			scanf("%s",ma[i]);
		}
		Findbegin();
		BFS();
	}
	return 0;
}




