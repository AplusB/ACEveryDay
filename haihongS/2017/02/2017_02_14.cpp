#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=100+3;
const ll mod=1e9+7;
const int inf=2e9+9;
double eps=1e-9;
double pi=acos(-1.0);

typedef pair<int,int> P;

int ans[maxn][maxn],dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,v;
		scanf("%d%d%d",&n,&m,&v);
		memset(ans,-1,sizeof(ans));
		for(int i=1;i<=n-2;i++)
		{
			if(v==0) break;
			for(int j=1;j<=m-2;j++)
			{
				if(v==0) break;
				v--;
				ans[i][j]=1;
			}
		}
		for(int i=1;i<=n-2;i++)
		{
			for(int j=1;j<=m-2;j++)
			{
				if(ans[i][j]==1)
				{
					for(int k=0;k<4;k++)
					{
						int x=i+dx[k],y=j+dy[k];
						if(ans[x][y]==-1) ans[x][y]=0;
					}
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(ans[i][j]==1) ans[i][j]=0;
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(ans[i][j]==-1) ans[i][j]=1;
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(j!=0) printf(" ");
				printf("%d",ans[i][j]);
			}
			puts("");
		}
	}
	return 0;
}
