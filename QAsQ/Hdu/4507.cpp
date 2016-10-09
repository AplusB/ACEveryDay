#include<bits/stdc++.h>
using namespace std;

#define LL long long 
const int maxn = 20,mod = 1e9 + 7;
int num[maxn];
LL ten[maxn * 2];

LL cnted[maxn][2][7][7];
LL count(int pos,bool bnd,int left,int sumer){
    if(pos < 0) return left != 0 && sumer != 0;
    LL & ncnt = cnted[pos][bnd][left][sumer];
    if(~ncnt) return ncnt;
    ncnt = 0;
    int bound = bnd ? num[pos] : 9;
    for(int i=0;i<=bound;i++){
        if(i == 7) continue;
        (ncnt += count(pos-1
                     ,bnd && bound == i
                     ,(left * 10 + i ) % 7
                     ,(sumer + i ) % 7 ) ) %= mod;
    }
    return ncnt;
}

LL sumed[maxn][2][7][7];
LL sum(int pos,bool bnd,int left,int sumer){
    if(pos < 0) return 0;
    LL & nsum = sumed[pos][bnd][left][sumer];
    if(~nsum) return nsum;
    nsum = 0;
    int bound = bnd ? num[pos] : 9;
    for(int i=0;i<=bound;i++){
        if(i == 7) continue;
        (nsum += sum (pos-1
                     ,bnd && bound == i
                     ,(left * 10 + i ) % 7
                     ,(sumer + i ) % 7 ) ) %= mod;
        (nsum += (count(pos-1
                       ,bnd && bound == i
                       ,(left * 10 + i ) % 7
                       ,(sumer + i ) % 7 )
                * i 
                * ten[pos]) % mod ) %= mod;
    }
    return nsum;
}

LL dp[maxn][2][7][7];
LL dfs(int pos,bool bnd,int left,int sumer){
    if(pos < 0) return 0;
    LL & ndp = dp[pos][bnd][left][sumer];
    if(~ndp) return ndp;
    ndp = 0;
    int bound = bnd ? num[pos] : 9;
    for(int i=0;i<=bound;i++){
        if(i == 7) continue;
        (ndp += dfs(pos-1
                   ,bnd && bound == i
                   ,(left * 10 + i ) % 7
                   ,(sumer+ i ) % 7 ) ) %= mod;
        (ndp += ((count(pos-1
                      ,bnd && bound == i
                      ,(left * 10 + i ) % 7
                      ,(sumer+ i ) % 7 )
                * i * i ) % mod
                * ten[pos * 2]) % mod ) %= mod;
        (ndp += ((sum(pos-1
                    ,bnd && bound == i
                    ,(left * 10 + i ) % 7
                    ,(sumer+ i ) % 7 )
                * i * 2 ) % mod
                * ten[pos]) % mod ) %= mod;
    }
    return ndp;
}
LL cal(LL x){
    int len = 0;
    while(x){
        num[len++] = x % 10;
        x /= 10;
    }
    memset(cnted,-1,sizeof(cnted));
    memset(sumed,-1,sizeof(sumed));
    memset(dp,-1,sizeof(dp));
    return dfs(len-1,true,0,0);
}
int main(){
    ten[0] = 1;
    for(int i=1;i<maxn * 2;i++) ten[i] = (ten[i-1] * 10 ) % mod;
    int T;
    scanf("%d",&T);
    LL l,r;
    while(T-- && ~scanf("%I64d %I64d",&l,&r)){
        printf("%I64d\n",(cal(r) - cal(l-1) + mod) % mod);
    }
    return 0;
}
