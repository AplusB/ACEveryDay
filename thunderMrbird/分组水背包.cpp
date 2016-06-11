#include<iostream>
#include <cstdio>
#include<queue>
#include<string>
#include<algorithm>
#include<map>
#include <cstring>
#include<queue>
#include<vector>
#include<cmath>
#include<set>
using namespace std;
typedef long long ll;
int a[105][105];
int dp[105];
int main()
{
        int m,n;
        while (scanf("%d %d",&m,&n) != EOF && (m||n))
        {
                for(int i=1;i<=m;i++)
                {
                        for(int j=1;j<=n;j++)
                                scanf("%d",&a[i][j]);
                }
                memset(dp,0,sizeof(dp));
                for(int i=1;i<=m;i++ )
		{
			for(int j=n;j>=0;j-- )
			{
				for(int  k=1;k<=j;k++ )
					if(j-k>=0 && dp[j] < dp[j-k]+a[i][k] )
						dp[j] = dp[j-k]+a[i][k];
			}
		}
		printf("%d\n",dp[n]);
        }
        return 0;
}
