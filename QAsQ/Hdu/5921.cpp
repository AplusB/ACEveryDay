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
