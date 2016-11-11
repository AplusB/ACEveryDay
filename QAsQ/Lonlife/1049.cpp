#include<bits/stdc++.h>
using namespace std;

const int mod = 1e4 + 7;
const int maxn = 112345;
#define LL long long 
LL fuc[maxn];
LL rfuc[maxn];

LL rev(LL x){
    int n = mod - 2;
    LL ret = 1;
    while(n){
        if(n&1) (ret *= x) %= mod;
        else (x *= x) %= mod;
        n >>= 1;
    }
    return ret;
}

void init(){
    fuc[0] = 1;
    for(int i = 1 ; i < maxn;i++){
        fuc[i] = (fuc[i-1] * i ) % mod;
    }
    rfuc[mod-1] = rev(fuc[mod-1]);
    for(int i = mod - 2; i >= 0;i--){
        rfuc[i] = (rfuc[i+1] * (i+1) ) % mod;
    }
}
LL Comb(LL n,LL m){
    if(m > n) return 0;
    LL ret = fuc[n];
    (ret *= rfuc[m] ) %= mod;
    (ret *= rfuc[n-m] ) %= mod;
    return ret;
}

LL Lucas(LL n, LL m)  {  
    LL ans = 1;  
    while(n && m && ans)  
    {  
        ans = (ans * Comb(n%mod, m%mod))%mod;
        n /= mod, m /= mod;  
    }  
    return ans;  
}  

LL calans(LL n,LL k){
    if(k==0) return 1;
    LL ans = Lucas(n+k,k) - Lucas(n+k,k-1);
    ((ans %= mod) += mod ) %= mod;
    return ans;
}

int main(){
    int T;
    init();
    scanf("%d",&T);
    LL x,y;
    while(T-- && ~scanf("%lld %lld",&x,&y)){
        printf("%lld\n",calans(x,y));
    }
    return 0;
}
