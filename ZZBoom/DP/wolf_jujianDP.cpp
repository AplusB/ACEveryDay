//hdoj5115

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const double eps=1e-5;
const double pi=acos(-1.0);
const int mod=998244353;
const LL INF=0x3f3f3f3f;

const int N=110;
LL dp[N*2][N*2];
int a[N*2];
int b[N*2];
int n;

int main()
{
    int t,i,k,j;
    int cas=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(i=1;i<=n;i++)
            scanf("%d",&b[i]);
        memset(dp,0,sizeof(dp));

        for(i=1;i<=n;i++)
            for(j=i;j<=n;j++)
                dp[i][j]=INF;
        for(int f=0;f<=n;f++){
            for(i=1;i<n+1-f;i++){
                j=i+f;
                for(k=i;k<=j;k++){
                    dp[i][j]=min(dp[i][j],dp[i][k-1]+dp[k+1][j]+a[k]+b[i-1]+b[j+1]);
                }
            }
        }
        printf("Case #%d: %lld\n",cas++,dp[1][n]);
    }
}


