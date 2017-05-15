#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int dp[2][5000*50];
int n,a[100];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        a[i]/=1024;
    }
    memset(dp,0xff,sizeof dp);
    dp[0][0]=0;
    int m=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<5000*50;j++)
        {
            if(dp[m][j]==-1) continue;
            if(dp[m^1][j+a[i]]==-1)
            {
                dp[m^1][j+a[i]]=dp[m][j];
            }
            else
            {
                dp[m^1][j+a[i]]=min(dp[m^1][j+a[i]],dp[m][j]);
            }

            if(j<=a[i])
            {
                if(dp[m^1][a[i]-j]==-1) dp[m^1][a[i]-j]=dp[m][j]+j;
                 dp[m^1][a[i]-j]=min(dp[m^1][a[i]-j],dp[m][j]+j);
            }
            else
            {
                if(dp[m^1][j-a[i]]==-1) dp[m^1][j-a[i]]=dp[m][j]+a[i];
                 dp[m^1][j-a[i]]=min(dp[m^1][j-a[i]],dp[m][j]+a[i]);
            }
        }
        m=m^1;
        for(int j=0;j<5000*50;j++)
            dp[m^1][j]=-1;
    }
    int ans=0x7fffffff;
    for(int j=0;j<5000*50;j++)
    {
        if(dp[m][j]==-1) continue;
        //printf("%d\n",dp[n][j]);
        ans=min(ans,dp[m][j]+j);
    }
    printf("%d\n",ans*1024);
    return 0;
}
