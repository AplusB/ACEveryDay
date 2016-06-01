
//http://codeforces.com/contest/676/problem/B 
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define read freopen("q.in","r",stdin)
#define LL long long
#define maxn 1500
using namespace std;
int a[maxn][maxn];
int cnt,n,t;


int main()
{
	std::ios::sync_with_stdio(false);
	
	while(~scanf("%d%d",&n,&t))
	{
		cnt=0;
		memset(a,0,sizeof(a));
		int i,j;
		a[1][1]=1024*t;
		int res=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=i;j++)
			{
				if(a[i][j]>=1024)
				{
					a[i+1][j]+=(a[i][j]-1024)/2;
					a[i+1][j+1]+=(a[i][j]-1024)/2;
					a[i][j]=1024;
					res++;
				}
			}
		}
		 
		printf("%d\n",res);
		
	}
}
