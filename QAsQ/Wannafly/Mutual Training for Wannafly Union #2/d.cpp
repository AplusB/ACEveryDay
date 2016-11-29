#include<bits/stdc++.h>
using namespace std;

const int maxn = 30;
const int mod = 1e9 + 7;
#define LL long long 

LL arr[maxn];
LL fuc[maxn];

LL rev(LL x){
    LL n = mod - 2,ret = 1;
    while(n){
        if(n & 1) (ret *= x) %= mod; 
        (x *= x) %= mod , n>>=1;
    }
    return ret;
}

LL com(LL n,LL m){
    if(m > n) return 0;
    LL ret = 1;
    for(int i = 0; i < m ; i ++){
        (ret *= (n - i) ) %= mod;
    }
    return (ret * fuc[m]) % mod;
}

LL Lucas(LL n,LL m){
    if(n <= 0) return 0;
    LL ret = 1;
    while(n && m && ret){
        (ret *= com(n % mod,m % mod) ) %= mod;
        n /= mod , m /= mod;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    fuc[0] = 1;
    for(int i = 1; i < maxn ; i ++) 
        fuc[i] = (fuc[i-1] * rev(i)) % mod;
    int n;
    LL s;
    cin>>n>>s;
    LL f;
    int len = 0;
    int cnt = 0;
    for(int i = 0 ; i < n ; i ++){
        cin>>f;
        if(f == 0) cnt++;
        else if(f < s) arr[len++] = f;
    }
    n -= cnt;
    LL ans = 0;
    LL v;
    for(int i = 0 ; i < (1<<len); i ++){
        int sig = 1;
        v = 0;
        for(int j = 0 ; j < len ; j ++){
            if((i>>j) & 1){
                sig *= -1;
                v += arr[j] + 1;
            }
        }
        (ans += Lucas(s + n - 1 - v,n - 1) % mod * sig + mod) %= mod;
    }
    if(s == 0) ans = 1;
    cout<<ans<<endl;
    return 0;
}
