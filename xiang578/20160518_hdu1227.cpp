#include<bits/stdc++.h>
using namespace std;
const int inf=0xfffffff;
int dp[400][400],cost[400][400],a[400],sum[400];
int main()
{
    int n,m,cnt=0,ans;
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0) break;
        sum[0]=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            sum[i]=a[i]+sum[i-1];
        }
        memset(cost,0,sizeof(cost));

        for(int i=1; i<=n; i++)
            for(int j=i+1; j<=n; j++)
                for(int k=i+1; k<j; k++)
                {
                    cost[i][j]+=min(a[j]-a[k],a[k]-a[i]);
                }

        for(int i=0; i<=n; i++)
            for(int j=0; j<=n; j++)
                dp[i][j]=inf;
        for(int i=1;i<=n;i++)
            dp[i][1]=a[i]*(i-1)-sum[i-1];
        for(int j=2; j<=m; j++)
        {
            for(int i=j; i<=n; i++)
            {
                for(int k=j-1; k<i; k++)
                {
                    dp[i][j]=min(dp[i][j],dp[k][j-1]+cost[k][i]);
                }
            }
        }
        ans=inf;
        for(int i=1;i<=n;i++)
        {
            if(dp[i][m]==inf) continue;
            int tmp=0;
            for(int j=i+1;j<=n;j++)
            {
                tmp+=a[j]-a[i];
            }
            ans=min(dp[i][m]+tmp,ans);
        }
        printf("Chain %d\n",++cnt);
        printf("Total distance sum = %d\n",ans);
        puts("");
    }
    return 0;
}
