//poj2488

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;
#define LL __int64
#define N 50
int d[8][2]={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};

bool vis[30][30];
int xx[30];
int yy[30];
int flag;
int a,b;

void DFS(int x,int y,int num)
{
	if(flag)
	return;
	if(num==a*b)
	{
		flag=1;
		for(int i=1;i<=num;i++)
		{
			printf("%c%d",xx[i]+64,yy[i]);	
		}
		puts("");
		//printf("%d\n",num);
		return;
	}
	for(int i=0;i<8;i++)
	{
		int aa=x+d[i][0];
		int bb=y+d[i][1];
		if(aa<1||bb<1||aa>b||bb>a||vis[bb][aa])
			continue;
		vis[bb][aa]=1;
		xx[num+1]=aa;
		yy[num+1]=bb;
		DFS(aa,bb,num+1);
		vis[bb][aa]=0;
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	int Case=1;
	for(Case=1;Case<=T;Case++)
	{
		scanf("%d%d",&a,&b);
		printf("Scenario #%d:\n",Case);
		flag=0;
		memset(vis,0,sizeof(vis));
		xx[1]=1;
		yy[1]=1;
		vis[1][1]=1;
		DFS(1,1,1);
		if(!flag)
		{
			printf("impossible\n");
		}
		puts("");
	}
	return 0;
}

/*
A1B3C1A2C1A2C1A2C1A2C1A2
A1C2A3B1D2B3C1A2C3D1B2D3
A1B3C1A2B4C2A3B1C3A4B2C4
*/



