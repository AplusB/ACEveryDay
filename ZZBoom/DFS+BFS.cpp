// poj 3083

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;
#define LL __int64
#define N 50

char ma[N][N];
bool vis[N][N];
int n,m;

int bx,by;
int ex,ey;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int dl[][2]={{0,-1},{-1,0},{0,1},{1,0}};
int dr[][2]={{0,1},{-1,0},{0,-1},{1,0}};

struct asd{
	int x,y;
	int step;
};
asd q[1000010];
int head,tail;

int ans1,ans2,ans3;

int BFS()
{
	head=0;tail=1;
	q[head].x=bx;
	q[head].y=by;
	q[head].step=0;
	memset(vis,0,sizeof(vis));
	while(head<tail)
	{
		int a=q[head].x;
		int b=q[head].y;
		if(a==ex&&b==ey)
			return q[head].step;
		for(int i=0;i<4;i++)
		{
			int aa=a+dx[i];
			int bb=b+dy[i];
			if(aa<0||bb<0||aa>=n||bb>=m||vis[aa][bb]||ma[aa][bb]=='#')
				continue;
			vis[aa][bb]=1;
			q[tail].x=aa;
			q[tail].y=bb;
			q[tail].step=q[head].step+1;
			tail++;
		}
		head++;
	}
}

int flag;

int dfs(int x,int y,int d,int step,int dir[][2])
{
	for(int i=0;i<4;i++)
	{
		int j=((d-1+4)%4+i)%4;
		int aa=x+dir[j][0];
		int bb=y+dir[j][1];
		if(aa<0||bb<0||aa>=n||bb>=m||ma[aa][bb]=='#')
			continue;

		if(aa==ex&&bb==ey)
		{
			return step+1;
		}
		return dfs(aa,bb,j,step+1,dir);
	}
}



int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&m,&n);
		for(int i=0;i<n;i++)
			scanf("%s",ma[i]);
		int f1,f2;
		f1=f2=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(ma[i][j]=='S')
				{
					bx=i;by=j;
					f1=1;	
				}
				if(ma[i][j]=='E')
				{
					ex=i;ey=j;
					f2=1;
				}
				if(f1&&f2)
					break;
			}
			if(f1&&f2)
				break;
		}
		int d1,d2;
		if(bx == 0){
			d1 = 3;
			d2 = 3;
		}
        else if(bx == n-1){
			d1 = 1; 
			d2 = 1; 
		}
        else if(by == 0){
			d1 = 2;
			d2 = 0;
		}
		else if(by == m-1){
			d1 = 0;
			d2 = 2;
		}
		ans1=dfs(bx,by,d1,1,dl);
		ans2=dfs(bx,by,d2,1,dr);
		ans3=BFS();
		printf("%d ",ans1);
		printf("%d ",ans2);
		printf("%d\n",ans3+1);
	}
}

