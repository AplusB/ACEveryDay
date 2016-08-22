#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
const int maxn=200+9;
const int inf=2e9+9;

int go[20][20];
int dp[100005];
int w[maxn],p[maxn],num[maxn];

void zeroone(int cost,int weight,int n);
void complete(int cost,int weight,int n);
int multi(int c[],int w[],int num[],int n,int m);

int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		memset(go,0,sizeof(go));
		for(int i=0;i<n;i++)
		{
			int nw,np;
			scanf("%d%d",&nw,&np);
			go[nw][np]++;
		}
		int pos=0;
		for(int i=1;i<=10;i++)
		{
			for(int j=1;j<=10;j++)
			{
				if(go[i][j]==0) continue;
				pos++;
				w[pos]=i,p[pos]=j,num[pos]=go[i][j];
			}
		}
		int ans=multi(w,p,num,pos,m);
		printf("%d\n",ans);
	}
	return 0;
}

int multi(int c[],int w[],int num[],int n,int m)
{
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		if(num[i]*c[i]>m)
			complete(c[i],w[i],m);
		else
		{
			int k=1;
			while(k<num[i])
			{
				zeroone(k*c[i],k*w[i],m);
				num[i]-=k;
				k<<=1;
			}
			zeroone(num[i]*c[i],num[i]*w[i],m);
		}
	}
	return dp[m];
}

void complete(int cost,int weight,int n)
{
	for(int i=cost;i<=n;i++)
		dp[i]=max(dp[i],dp[i-cost]+weight);
}

void zeroone(int cost,int weight,int n)
{
	for(int i=n;i>=cost;i--)
		dp[i]=max(dp[i],dp[i-cost]+weight);
}
