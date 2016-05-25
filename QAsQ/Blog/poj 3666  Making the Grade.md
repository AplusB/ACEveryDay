# poj 3666  Making the Grade

这个题刚看到的时候也是没有什么想法

然后注意到了只有$2000$个位置

然后有了一个$O(n^3)$的做法

(为了简化问题我们只考虑把点填成单调递减的，因为对于递增的，我们把输入反过来再做一遍就好了)

首先我们把给出的路的长度离散化一下，因为对于一个位置，要么不动，要么就填到一个已经有的高度

定义$dp_{len,pos}$为把第$len$个点填到离散化之后的第$pos$高度的时候的最小花费

然后可以从$dp_{len-1,k}(k\le pos)$转移过来

----

但是这个题的范围是$2000$,我们需要复杂度更优的做法

---

注意到转移的时候我们取的是一个前缀最小值，那么在转移的同时注意维护一下前缀最小值，就可以做到$O(n^2)$了

具体见代码

```cpp
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
```

