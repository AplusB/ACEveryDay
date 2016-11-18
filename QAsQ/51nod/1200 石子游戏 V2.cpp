#include<bits/stdc++.h>
using namespace std;

const int maxn = 112345;
#define LL long long 
const int mod = 1e9 + 7,rev_2 = (mod + 1) / 2;

void fwt (LL a[] , int n ,bool on) {
    for ( int d = 1 ; d < n ; d <<= 1 ) {
        for ( int k = d << 1 , i = 0 ; i < n ; i += k ) {
            for ( int j = 0 ; j < d ; ++ j ) {
                LL x = a[i + j] , y = a[i + j + d] ;
                if(on){
                    a[i + j] = ( x + y ) % mod ;
                    a[i + j + d] = ( x - y + mod ) % mod ;
                }
                else{
                    a[i + j] = ( x + y ) * rev_2% mod ;
                    a[i + j + d] = ( x - y + mod ) * rev_2% mod ;
                }
            }
        }
    }
}

LL pmod(LL x,LL n){
    LL ret = 1;
    while(n){
        if(n&1) (ret *= x) %= mod;
        (x *= x) %= mod;
        n >>= 1;
    }
    return ret;
}

bool vis[maxn];
void sieve(){
    memset(vis,0,sizeof(vis));
    vis[0] = vis[1] = true;
    for(int i = 2; i < maxn;i++){
        if(vis[i] == false){
            for(int j = i * 2; j < maxn; j += i) 
                vis[j] = true;
        }
    }
}

LL a[maxn];

int main(){
    sieve();
    int n,m;
    scanf("%d %d",&n,&m);
    memset(a,0,sizeof(a));
    for(int i = 0 ; i <= m ; i++){
        a[i] = !vis[i];
    }
    int bnd = 1;
    while(bnd <= m) bnd<<=1;
    fwt(a,bnd,true);
    for(int i = 0 ; i < bnd;i++) a[i] = pmod(a[i],n);
    fwt(a,bnd,false);
    printf("%lld\n",a[0]);
    return 0;
}
