// 417 C
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
#define ls 2*i
#define rs 2*i+1
#define up(i,x,y) for(i=x;i<=y;i++)
#define down(i,x,y) for(i=x;i>=y;i--)
#define mem(a,x) memset(a,x,sizeof(a))
#define w(a) while(a--)
#define LL long long
const double pi = acos(-1.0);
#define Len 200005
#define mod 19999997
const int INF = 0x3f3f3f3f;
#define exp 1e-6

int num[1010];
bool vis[1010][1010];

int main()
{
	int n,k;
	cin>>n>>k;
	
	int sum=0;
	memset(vis,0,sizeof(vis));
	memset(num,0,sizeof(num));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j)
			{
				if(!vis[j][i]&&!vis[i][j]&&num[i]<k)
				{
					sum++;
					num[i]++;
					vis[i][j]=1;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(num[i]!=k)
		{
			printf("-1\n");
			return 0;
		}
	}
	printf("%d\n",sum);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(vis[i][j])
			printf("%d %d\n",i,j);
		}
	}
	return 0;
}





