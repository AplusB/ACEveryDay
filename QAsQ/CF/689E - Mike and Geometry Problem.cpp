#include<bits/stdc++.h>
using namespace std;

#define LL long long 
const int mod = 1000000007;

map<LL,LL> M;
const int maxn = 212345 * 2;
LL com[maxn];

LL pmod(LL x,int n){
    LL ret = 1;
    while(n){
        if(n&1) (ret *= x) %= mod;
        (x *= x) %= mod;
        n >>= 1;
    }
    return ret;
}

LL rev(LL x){
    return pmod(x,mod-2);
}

void init(LL k,LL n){
    com[0] = 1;
    for(int i=1;i<=n;i++){
        com[i] = (com[i-1] * (i+k)) % mod;
        (com[i] *= rev(i)) %= mod;
    }
}

LL C(LL v){
    if(v < 0) return 0;
    return com[v];
}

LL nod[maxn],cnt[maxn];

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    init(k,n);
    LL l,r;
    M.clear();
    for(int i=0;i<n;i++){
        scanf("%I64d %I64d",&l,&r);
        M[l]++,M[r+1]--;
    }
    int len = 0;
    for(auto x : M){
        nod[len] = x.first;
        cnt[len] = x.second;
        len++;
    }
    for(int i=1;i<len;i++){
        cnt[i] += cnt[i-1];
    }
    LL ans = 0;
    for(int i=0;i<len-1;i++){
        (ans += (C(cnt[i] - k) * (nod[i+1] - nod[i])) % mod) %= mod;
        assert(nod[i+1] >= nod[i]);
    }
    printf("%I64d\n",ans);
    return 0;
}
