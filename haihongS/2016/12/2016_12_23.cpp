#include <bits/stdc++.h>

using namespace std;
const int maxn=2e2+9;
const int inf=2e9+9;
typedef long long ll;

int n,m;
int a[maxn][maxn],b[maxn][maxn];

void update(int x,int y);
int judge(int x,int y);

int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&a[i][j]);
		memset(b,-1,sizeof(b));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]==0)
				{
					update(i,j);
				}
			}
		}
		int flag=1;
		for(int i=1;i<=n;i++)
		{
			if(flag==0) break;
			for(int j=1;j<=m;j++)
			{
				if(flag==0) break;
				if(a[i][j]==1)
				{
					if(judge(i,j)==0)
					{
						flag=0;break;
					}
				}
			}
		}
		if(flag==0) 
		{
			printf("NO\n");continue;
		}
		printf("YES\n");
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(j!=1) printf(" ");
				printf("%d",-1*b[i][j]);
			}
			printf("\n");
		}
	}
}

int judge(int x,int y)
{
	for(int i=1;i<=n;i++)
	{
		if(b[i][y]==-1) return 1;
	}
	for(int i=1;i<=m;i++)
		if(b[x][i]==-1) return 1;
	return 0;
}

void update(int x,int y)
{
	for(int i=1;i<=n;i++)
		b[i][y]=0;
	for(int i=1;i<=m;i++)
		b[x][i]=0;
}
