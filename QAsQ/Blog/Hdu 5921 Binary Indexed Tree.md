# Hdu 5921 Binary Indexed Tree

[题解链接](https://async.icpc-camp.org/d/582-2016)

---

题意搬运:

> 用树状数组维护一个序列，在给区间 $[l,r]$ 加上一个$t$的时候，要给 $[1,r]$加上 $t$，给 $[1,l−1]$ 减去 $t$，两次操作后值真正发生变化的节点个数就是这一次区间修改的代价，现在要修改每一个$[1,n]$的子区间，求总代价对 $10^9+7$取模后的结果。

题解搬运

>记$cnt_i$表示$i$的二进制表达式中$1$的个数，$lcp(i,j)$表示$i$和$j$的二进制表示的最长公共前缀（如果长度不同，右对齐之后在左边补0），那么就是求$$\sum_{r=1}^{n}\sum_{l=0}^{r-1}(cnt_l+cnt_r-2cnt_{lcp(l,r)})=\frac{1}{2}\sum_{l=0}^{n}\sum_{r=0}^{n}(cnt_l+cnt_r-2cnt_{lcp(l,r)})$$考虑逐位计算贡献，对于第$i$位，枚举两个数$l$和$r$，如果前$i$位都相同那么没有贡献，否则贡献是$l$和$r$在第$i$位的数之和，于是$dp[i][0/1][0/1][0/1]$表示已经考虑了最高$i$位，现在$l$和$r$的前缀是否相等以及各自是否等于$n$的前缀的方案数，计算贡献时要补上后缀，观察到$l$和$r$的后缀是相互独立的，只需考虑前缀是否等于$n$的前缀。

---

其实dp数组就是前i位是否开始统计，l和r是否卡到上界的状态

每次统计的时候，当前位的能产生的贡献次数就是后面能接的后缀的个数

```cpp
#include<bits/stdc++.h>
using namespace std;

const int maxn = 63,mod = 1e9+7;
#define LL long long

int inser(int *s,LL *v,LL x){
    memset(s,0,sizeof(int)*maxn);
    int len = 0;
    while(x)
        s[len++] = x & 1, x >>= 1;
    v[0] = s[0];
    for(int i=1;i<len;i++)
        v[i] = v[i-1]+((1ll*s[i])<<i);
    for(int i=0;i<len;i++)
        v[i] = (v[i] + 1) % mod;
    return len;
}

LL dp[maxn][2][2][2], lr[maxn];
int lrs[maxn];

LL tim(int pos,bool lnd,bool rnd){
    if(pos < 0) return 1;
    LL full = (1ll << (pos+1)) % mod, ret = 1;
    if(lnd) (ret *= lr[pos]) %= mod;
    else (ret *= full) %= mod;
    if(rnd) (ret *= lr[pos]) %= mod;
    else (ret *= full) %= mod;
    return ret;
}

LL dfs(int pos,bool lbnd,bool rbnd,bool scnt){
    if(pos < 0) return 0;
    LL & ndp = dp[pos][lbnd][rbnd][scnt];
    if(ndp != -1) return ndp;
    int lb = lbnd ? lrs[pos] : 1, rb = rbnd ? lrs[pos] : 1;
    ndp = 0;
    for(int i=0;i<=lb;i++){
        for(int j=0;j<=rb;j++){
            (ndp += dfs(pos-1
                       ,lbnd && i == lb
                       ,rbnd && j == rb
                       ,scnt || (i != j)) ) %= mod;
            (ndp += (scnt||(i!=j))*(i+j) 
                    * tim(pos-1 
                         ,lbnd && i == lb 
                         ,rbnd && j == rb) ) %= mod;
        }
    }
    return ndp;
}

LL cal(LL num){
    memset(dp,-1,sizeof(dp));
    int n = inser(lrs,lr,num);
    return dfs(n-1,true,true,false);
}

int main(){
    int T,icase = 1;
    scanf("%d",&T);
    LL n;
    memset(dp,-1,sizeof(dp));
    while(T-- && ~scanf("%lld",&n)){
        LL rev = (mod + 1) / 2;
        LL ans = cal(n)* rev % mod;
        printf("Case #%d: %lld\n",icase++,ans);
    }
    return 0;
}
```

