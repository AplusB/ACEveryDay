#include<bits/stdc++.h>
using namespace std;
#define LL long long 
const int maxn = 1123;
const int mod = 1000000007;

LL tw[maxn];
LL C[maxn][maxn];
LL dp[maxn][maxn];

LL pmod(int n){
    LL ret = 1;
    LL st = 3;
    while(n){
        if(n&1) (ret *= st) %= mod;
        (st *= st) %= mod;
        n>>=1;
    }
    return ret;
}


void init(){
    memset(C,0,sizeof(C));
    C[0][0] = 1;
    for(int i=1;i<maxn;i++){
        C[i][0] = C[i-1][0];
        for(int j=1;j<=i;j++){
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
        }
    }
    int bnd = 10;
    memset(dp,0,sizeof(dp));
    dp[1][0] = dp[0][1] = 1;
    for(int i=1;i<=bnd;i++){
        for(int j=1;j<=bnd;j++){
            dp[i][j] = pmod(i*j);
            for(int a=1;a<=i;a++){
                for(int b=0;b<=j;b++){
                    if(a == i && b == j) continue;
                    LL v = C[i-1][a-1];
                    (v *= C[j][b]) %= mod;
                    (v *= pmod( (i-a) * (j-b) ) ) %= mod;
                    (v *= dp[a][b]) %= mod;
                    dp[i][j] = (dp[i][j] + mod - v) % mod;
                }
            }
        }
    }
}


int main(){
    int n,m;
    init();
    while(~scanf("%d %d",&n,&m)){
        printf("%I64d\n",dp[n][m]);
    }
    return 0;
}  
