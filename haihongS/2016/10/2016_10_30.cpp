#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=203;
const int inf=2e9+9;

int g,b,s;

int a[30][30];
int flag[1<<21];

int dfs(int now);

int main()
{
	while(~scanf("%d%d%d",&g,&b,&s) && g+b+s)
	{
		memset(a,0,sizeof(a));
		for(int i=0;i<b;i++)
		{
			int n;
			scanf("%d",&n);
			while(n--)
			{
				int x;
				scanf("%d",&x);
				a[i][x]++;
			}
		}
		int len=(1<<b)-1;
		for(int i=0;i<=len;i++)
			flag[i]=-inf;
		dfs(len);
		printf("%d\n",flag[len]);
	}
	return 0;
}

int dfs(int now)
{
	if(flag[now]!=-inf) return flag[now];
	if(now==0) return flag[now]=0;
	int all[20]={0};
	for(int i=0;i<b;i++)
	{
		if((now&(1<<i))==0)
		{
			for(int j=1;j<=g;j++)
			{
				all[j]+=a[i][j];
				all[j]%=s;
			}
		}
	}
	
	int nx[20];
	int ans=-inf;
	for(int i=0;i<b;i++)
	{
		int go=0;
		if((now&(1<<i))!=0)
		{
			for(int j=1;j<=g;j++)
				nx[j]=all[j]+a[i][j],go+=nx[j]/s;
			if(go>0)
				ans=max(ans,go+dfs(now^(1<<i)));
			else
				ans=max(ans,go-dfs(now^(1<<i)));
		}
	}
	flag[now]=ans;
	return ans;
}
