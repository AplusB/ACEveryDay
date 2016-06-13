#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int mp[150][150];
int vis[150];
int ans[150];
int n;

int dfs(int x)
{
	//一定要进行边界的区分处理，否则TLE
	if(x==n+1)
		return 1;
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(mp[x][i]==1&&vis[i]==0)
			{
				ans[x]=i;
				vis[i]=1;
				if(dfs(x+1)==1)//如果放入成功，就不再进行取消的操作。
					return 1;
				vis[i]=0;
			}
		}
	}
	return 0;
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		memset(ans,0,sizeof(ans));
		memset(vis,0,sizeof(vis));

		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				scanf("%d",&mp[i][j]);
			}
		}

		dfs(1);

		for(int i=1;i<=n;i++)
		{
			printf("%d%c",ans[i],(i==n?'\n':' '));
		}
	}
	return 0;
}
