/*
author： keyboarder
time  ： 2016-05-18 12:21:26
*/ 
#include<cstdio>
#include<string.h>
#include<iostream>
#define N 110

int pre[N];
int ma[N][N];
bool vis[N];
int n;

void tuopu()
{
	int cnt=0;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
	{
		int k=-1;
		for(int j=1;j<=n;j++)
		{
			if(!pre[j]&&!vis[j])
			{
				if(!cnt)
				{
					printf("%d",j);
					cnt++;	
				}
				else
					printf(" %d",j);
				vis[j]=1;
				k=j;
				break;
			}
		}
		if(k==-1)
			break;
		for(int j=1;j<=n;j++)
		{
			if(ma[k][j]&&!vis[j])
			{
				pre[j]--;
			}
		}
	}
	puts("");
}

int main()
{
	while(~scanf("%d",&n))
	{
		int x;
		memset(ma,0,sizeof(ma));
		memset(pre,0,sizeof(pre));
		for(int i=1;i<=n;i++)
		{
			while(scanf("%d",&x))
			{
				if(!x)
				break;
				if(!ma[i][x])
				{
					ma[i][x]=1;
					pre[x]++;
				}
					
			}
		}
		tuopu();
	}
	return 0;
}
