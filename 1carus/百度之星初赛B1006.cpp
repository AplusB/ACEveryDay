#include <iostream>
#include <cstdio>
#define endl '\n'

using namespace std;

const int MAXN = 10005;

int SUM[MAXN * 2],*sum,n,num[MAXN];

int main()
{
	sum = SUM + MAXN;
	while(scanf("%d",&n) == 1)
	{ 
		int i;
		for(i = 0;i < n;i++)
		{
			scanf("%d",&num[i]);
		}
		
		int j;
		for(i = 0;i < n;i++)
		{
			int ans = 0;
			sum[0]++;
			int d = 0;
			for(j = i - 1;j >= 0;j--)
			{
				d +=(num[j] < num[i] ? -1 : 1),sum[d]++;
			}
			
			ans = sum[0];
			d = 0;
			for(j = i + 1;j < n;j++)
			{
				d += (num[j] < num[i] ? -1 : 1),ans += sum[-d];
			}
			
			for (j=-n;j<=n;j++) sum[j]=0;
            printf("%d%c",ans,i<n - 1?' ':'\n');
		}
	}
	return 0;
} 
