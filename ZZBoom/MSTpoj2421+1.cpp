//kruskal

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
#define INF 0x3f3f3f3f
const double pi = acos(-1.0);

const int N=1e2+10;

struct asd{
	int x,y;
	int num;
};
asd q[N*N];
bool cmp(asd z,asd x)
{
	if(z.num<x.num)
		return 1;
	return 0;
}
int ma[N][N];
int dis[N];
int pre[N];
int vis[N];
int n;

void Init()
{
	for(int i=1;i<=n;i++)
		pre[i]=i;
}

int Find(int x)
{
	int r=x;
	while(r!=pre[r])
	{
		r=pre[r];
	}
	int i=x,j;
	while(pre[i]!=r)
	{
		j=pre[i];
		pre[i]=r;
		i=j;
	}
	return r;
}

int main()
{
	int m,a,b;
	cin>>n;
	Init();
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&ma[i][j]);	
		}
	}
	cin>>m;
	for(int i=0;i<m;i++)
	{
 		scanf("%d%d",&a,&b);
		ma[a][b]=ma[b][a]=0;
	}
	int num=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j)
			{
				q[num].x=i;q[num].y=j;q[num].num=ma[i][j];
				num++;	
			}
		}
	}
	
	sort(q,q+num,cmp);
	
	int ans=0;
	for(int i=0;i<num;i++)
	{
		int aa=Find(q[i].x);
		int bb=Find(q[i].y);
		if(aa!=bb)
		{
			pre[aa]=bb;
			ans+=q[i].num;
		}
	}
	
	cout<<ans<<endl;
	return 0;
}
