//lightoj1422 - Halloween Costumes
#include <bits/stdc++.h>
using namespace std;
const int MAXN=110;
int a[MAXN];
int dp[MAXN][MAXN];
int main()
{
    int T;
    int n;
    scanf("%d",&T);
    int iCase=0;
    while(T--)
    {
        iCase++;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++)
                dp[i][j]=j-i+1;
        for(int i=n-1;i>=1;i--)
            for(int j=i+1;j<=n;j++)
            {
                dp[i][j]=dp[i+1][j]+1;
                for(int k=i;k<=j;k++)
                    if(a[i]==a[k])
                        dp[i][j]=min(dp[i][j],dp[i+1][k-1]+dp[k][j]);
            }
        printf("Case %d: %d\n",iCase,dp[1][n]);
    }
    return 0;
}
