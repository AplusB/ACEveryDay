#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define LL long long
using namespace std;
const int maxn=1<<30;
const int SIZE=1e2+10;
int cmap[20][20],dp[17][70000];
int main()
{
    int T,n;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&cmap[i][j]);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){//第i行枚举前i-1行状态j
            for(int j=0;j<(1<<n);j++){
                int cnt=0;
                for(int k=0;k<n;k++){
                    if(j&(1<<k))cnt++;
                }
                if(cnt!=i-1)continue;
                for(int k=0;k<n;k++){
                    if(j&(1<<k))continue;
                    dp[i][j|(1<<k)]=max(dp[i][j|(1<<k)],dp[i-1][j]+cmap[i][k+1]);//注意是第k+1个位置可以放
                }
            }
        }
        printf("Case %d: %d\n",cas,dp[n][(1<<n)-1]);
    }
    return 0;
}
