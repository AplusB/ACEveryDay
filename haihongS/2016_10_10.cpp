#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;
const int maxn=2e5+9;
const int inf=1e9+9;

int a[maxn];
int dp[maxn][3];

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<maxn;i++)
            for(int j=0;j<3;j++)
                dp[i][j]=0;
        // 0~-1   1~0 2~1
        dp[1][1]=1;
        for(int i=2;i<=n;i++)
        {
            if(a[i]==a[i-1])
            {
                dp[i][0]=dp[i-1][0]+1;
                dp[i][1]=dp[i-1][1]+1;
                dp[i][2]=dp[i-1][2]+1;
            }
            else if(a[i-1]+1==a[i])
            {
                dp[i][0]=max(dp[i-1][1],dp[i-1][2])+1;
                dp[i][1]=1;
                dp[i][2]=0;
            }
            else if(a[i-1]-1==a[i])
            {
                dp[i][0]=0;
                dp[i][1]=1;
                dp[i][2]=max(dp[i-1][1],dp[i-1][0])+1;
            }
            else
            {
                dp[i][1]=1;
                dp[i][0]=dp[i][2]=0;
            }
        }
        int maxx=0;
        for(int i=1;i<=n;i++)
        {
            int now=dp[i][0];
            now=max(now,dp[i][1]);
            now=max(now,dp[i][2]);
            maxx=max(maxx,now);
        }
        printf("%d\n",maxx);

    }
    return 0;
}
