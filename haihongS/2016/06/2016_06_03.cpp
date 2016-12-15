/*
ID: shh_nam1
PROG: combo
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <stack>
using namespace std;
typedef long long ll;
const int maxn=1e5+9;
const int inf=1e9+9;

int n;
int a[5],b[5];
int use[1000000];
int ans;

int bfs();

int main()
{
    freopen("combo.in","r",stdin);
    freopen("combo.out","w",stdout);
    while(~scanf("%d",&n))
	{
		for(int i=0;i<3;i++)
		{
			scanf("%d",&a[i]);
			a[i]--;
		}
		for(int j=0;j<3;j++)
		{
			scanf("%d",&b[j]);
			b[j]--;
		}
		memset(use,0,sizeof(use));
		ans=0;
		bfs();
		printf("%d\n",ans);
	}
    return 0;
}

int bfs()
{
	for(int i=a[0]-2;i<=a[0]+2;i++)
	{
		for(int j=a[1]-2;j<=a[1]+2;j++)
		{
			for(int k=a[2]-2;k<=a[2]+2;k++)
			{
				int tmp=(i+n)%n*100+(j+n)%n*10+(k+n)%n;
				if(use[tmp]==0) ans++;
				use[tmp]=1;
			}
		}
	}

	int tmp=0;
	for(int i=b[0]-2;i<=b[0]+2;i++)
		for(int j=b[1]-2;j<=b[1]+2;j++)
			for(int k=b[2]-2;k<=b[2]+2;k++)
			{
				int tmp=(i+n)%n*100+(j+n)%n*10+(k+n)%n;
				if(use[tmp]==0) ans++;
				use[tmp]=1;
			}
	return 0;
}
