//PRIM 

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
#define LL long long
const double pi = acos(-1.0);
#define Len 200005
#define mod 19999997
const int INF = 0x3f3f3f3f;
#define exp 1e-6

#define N 160

int ma[N][N];
int n;
int vis[N];
int dis[N];

void prim()
{
	int k,mimi;
	for(int i=2;i<=n;i++)
	{
		dis[i]=ma[1][i];
		vis[i]=0;
	}
	
	dis[1]=0;
	vis[1]=1;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		k=0;
		mimi=INF; 
		for(int j=1;j<=n;j++)
		{
			if(!vis[j]&&dis[j]<mimi)
			{
				mimi=dis[j];
				k=j;
			}
		}
		if(!k) break;
		vis[k]=1;
		
		for(int j=1;j<=n;j++)
		{
			if(!vis[j]&&dis[j]>ma[k][j])
				dis[j]=ma[k][j];
		}
	}

	for(int i=1;i<=n;i++)
		ans+=dis[i];
	printf("%d\n",ans);
}

int main()
{
	int m,a,b;
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&ma[i][j]);
	cin>>m;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		ma[a][b]=ma[b][a]=0;
	}
	prim();
}




