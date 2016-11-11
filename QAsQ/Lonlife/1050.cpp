#include<bits/stdc++.h>
using namespace std;

#define LL long long 

const int maxn = 112345;
const int mod = 1e9 + 7;
LL arr[maxn];
LL dp[maxn][35];

int getb(LL x){
    int cnt = 1;
    while(x != 1){
        if(x&1) return -1;
        cnt++;
        x >>= 1;
    }
    return cnt;
}
int main(){
    int T;
    scanf("%d",&T);
    int n;
    while(T-- && ~scanf("%d",&n)){
        memset(dp,0,sizeof(dp));
        for(int i = 1; i <= n;i++){
            scanf("%lld",&arr[i]);
        }
        dp[0][0] = 1;
        for(int i = 1;i<=n;i++){
            int k = getb(arr[i]);
            for(int j = 0; j < 35;j++){
                (dp[i][j] += dp[i-1][j] ) %= mod;
            }
            if(k != -1){
                (dp[i][k] += dp[i-1][k-1]) %= mod;
            }
        }
        LL ans = 0;
        for(int i = 1 ; i < 35;i++){
            (ans += dp[n][i]) %= mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
