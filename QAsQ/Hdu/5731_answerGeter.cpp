#include<bits/stdc++.h>
using namespace std;

#define LL long long  

const int bit = 17, maxn = 1<<bit;
const int mod = 1000000007;
LL any[bit][bit];
LL dp[bit][bit][maxn];

inline bool get(int x,int pos){
    return (x>>(pos-1))&1;
}
inline int sub(int x,int pos){
    return x & (~(1<<(pos-1)));
}
inline int rev(int x,int pos){
    return x ^ (1<<(pos-1));
}

void cdp(int m){
    int bnd = 1<<m;
    dp[0][m][bnd-1] = 1;
    for(int i=1;i<bit;i++){
        for(int j=1;j<=m;j++){
            LL *pdp = j==1 ? dp[i-1][m]:dp[i][j-1];
            for(int mask=0;mask<bnd;mask++){
                dp[i][j][mask] = pdp[rev(mask,j)];
                if(j>1 && get(mask,j-1) && get(mask,j))
                    (dp[i][j][mask] += pdp[sub(mask,j-1)])%=mod;
            }
        }
    }
}

void init(){
    for(int j=1;j<bit;j++){
        cdp(j);
        int bnd = 1<<j;
        for(int i=1;i<bit;i++){
            any[i][j] = dp[i][j][bnd-1];
        }
    }
}

LL mas[bit],mlen;
LL anym(int n){
    LL ret = 1;
    for(int i=0;i<mlen;i++){
        (ret *= any[n][mas[i]]) %= mod;
    }
    return ret;
}
LL tdp[bit];

LL calexc(int n,int mask,int m){
    mlen = 0;
    mas[mlen] = 1;
    for(int i=1;i<=m-1;i++){
        if(mask & 1){
            mlen++;
            mas[mlen] = 0;
        }
        mask >>= 1;
        mas[mlen]++;
    }
    mlen++;
    for(int i=1;i<=n;i++){
        tdp[i] = anym(i);
        for(int j=1;j<i;j++){
            (tdp[i] -= (1ll * tdp[i-j] * anym(j)) %mod ) %=mod;
            (tdp[i] += mod) %= mod;
        }
    }
    return tdp[n];
}

int sig(int x){
    int ret = 1;
    while(x){
        if(x & 1) ret *= -1;
        x >>= 1;
    }
    return ret;
}
LL cal(int n,int m){
    LL ans = 0;
    for(int i=0;i<(1<<(m-1));i++){
       (ans += sig(i) * calexc(n,i,m))%=mod;
       (ans += mod) %= mod;
    }
    return ans;
}
void out(){
    for(int i=1;i<bit;i++){
        printf("{");
        for(int j=1;j<bit;j++){
            printf(j<bit-1?"%lld,":"%lld},\n",cal(i,j));
        }
    }
}
            
int main(){
    init();
    freopen("ans.out","w",stdout);
    out();
    return 0;
}
