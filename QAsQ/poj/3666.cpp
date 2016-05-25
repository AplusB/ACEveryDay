#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL long long
const LL INFF = 0x3f3f3f3f3f3f3f3fll;

const int maxn = 2123;

LL dp[maxn][maxn];
LL msp[maxn],val[maxn];
int mlen;

LL nz(LL x){
    return x < 0 ? -x : x;
}

LL cal(int n){
    for(int i=0;i<mlen;i++){
        dp[0][i] = 0;
    }
    for(int i=1;i<=n;i++){
        LL miner = INFF;
        for(int j=0;j<mlen;j++){
            miner = min(miner,dp[i-1][j]);
            dp[i][j] = miner + nz(val[i]-msp[j]);
        }
    }
    LL ans = INFF;
    for(int i=0;i<mlen;i++){
        ans = min(ans,dp[n][i]);
    }
    return ans;
}

int main(){
    int n;
    while(~scanf("%d",&n)){
        mlen = 0;
        for(int i=1;i<=n;i++){
            scanf("%lld",&val[i]);
            msp[mlen++] = val[i];
        }
        sort(msp,msp+mlen);
        mlen = unique(msp,msp+mlen)-msp;
        LL ans = cal(n);
        reverse(val+1,val+1+n);
        ans = min(ans,cal(n));
        printf("%lld\n",ans);
    }
    return 0;
}
