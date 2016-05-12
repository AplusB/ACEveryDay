//lightoj 1193 - Dice (II)
//前缀和推得快吐了！！！
#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int mod=1e8+7;
LL dp[2][15010],sum[15010];
int main()
{
//    freopen("in.in","r",stdin);
//    freopen("out.out","w",stdout);
    int t,cas=1,n,s,k;
    cin>>t;
    while(t--){
        scanf("%d%d%d",&n,&k,&s);
        memset(dp,0,sizeof dp);
        for(int i=1;i<=s;i++)
            dp[0][i]=dp[0][i-1]+(i<=k?i:0);
        int now=0;
        for(int i=2;i<=n;i++){
            now^=1;
            for(int j=1;j<=s;j++){
                if(j<=k) dp[now][j]=(dp[now][j-1]+sum[j-1])%mod;
                else dp[now][j]=((dp[now][j-1]+sum[j-1]-sum[j-k-1]-dp[now^1][j-k-1]*k)%mod+mod)%mod;
                sum[j]=(sum[j-1]+dp[now^1][j])%mod;
            }
        }
        printf("Case %d: %d\n",cas++,((dp[now][s]-dp[now][s-1])%mod+mod)%mod);
    }
    return 0;
}
