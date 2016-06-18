#include<cstdio>
#include<queue>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;


int n;
int vis[5][20];
int C[20];
int tol;

void DFS(int cur)
{
	if(cur==n)
		tol++;
	else
	{
		for(int i=0;i<n;i++)
		{
			if(!vis[0][i]&&!vis[1][i+cur]&&!vis[2][cur-i+n])
			{
				C[cur]=i;
				vis[0][i]=vis[1][i+cur]=vis[2][cur-i+n]=1;
				DFS(cur+1);
				vis[0][i]=vis[1][i+cur]=vis[2][cur-i+n]=0;
			}
		}
	}
}



int main()
{
	int DP[13];
	for(int i=1;i<=10;i++)
	{
		tol=0;
		n=i;
		memset(vis,0,sizeof(vis));
		
		DFS(0);
		DP[i]=tol;
	}
	
	while(~scanf("%d",&n)&&n)
	{
		if(n<0)
		{
			printf("0\n");
			continue;
		}
		printf("%d\n",DP[n]);
	}
	return 0;
}




