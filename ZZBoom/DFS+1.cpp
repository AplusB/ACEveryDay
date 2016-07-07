//HDOJ 2952

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;
#define LL __int64

#define N 110

int n,m;
char ma[N][N];
/*
void DFS(int x,int y)
{
	if(x<0||y<0||x>=n||y>=m)
		return;
	if(ma[x][y]=='#')
		ma[x][y]='.';
	else
		return;
	DFS(x-1,y);
	DFS(x+1,y);
	DFS(x,y+1);
	DFS(x,y-1);
}
*/
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

void DFS(int x,int y)
{
	for(int i=0;i<4;i++)
	{
		int aa=x+dx[i];
		int bb=y+dy[i];
		if(aa<0||bb<0||aa>=n||bb>=m||ma[aa][bb]=='.')
			continue;
		ma[aa][bb]='.';
		DFS(aa,bb);
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		
		for(int i=0;i<n;i++)
		{
			scanf("%s",ma[i]);
		}
		
		int ans=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(ma[i][j]=='#')
				{
					ma[i][j]='.';
					DFS(i,j);
					ans++;	
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}



