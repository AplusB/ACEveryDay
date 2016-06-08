//hdoj 2845

#include<cstdio>
#include<queue>
#include<math.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
#define PI 3.1415926535898
#define INF 0X3f3f3f3f

#define N 200010

int a[N];
int b[N];
int dp[N];

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        memset(b,0,sizeof(b));
        memset(dp,0,sizeof(dp));

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
                scanf("%d",&a[j]);
            dp[1]=a[1];
            for(int j=2;j<=m;j++)
            {
                dp[j]=max(dp[j-1],dp[j-2]+a[j]);
            }
            b[i]=dp[m];
        }

        memset(dp,0,sizeof(dp));
        dp[1]=b[1];
        for(int i=2;i<=n;i++)
        {
            dp[i]=max(dp[i-2]+b[i],dp[i-1]);
        }

        printf("%d\n",dp[n]);
    }
    return 0;
}

