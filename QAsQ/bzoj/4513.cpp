#include<bits/stdc++.h>
using namespace std;

#define LL long long
const int maxn = 70;

LL n[maxn],m[maxn],k[maxn];
LL p;

LL cnt[maxn][2][2][2],dp[maxn][2][2][2];
LL tw[maxn];

void biter(LL x,LL *s){
    for(int i = 0;i<maxn;i++){
        s[i] = x % 2;
        x /= 2;
    }
}

LL dfsn(int pos,bool un,bool um,bool uk){
    if(pos < 0) return 1;
    LL & ncnt = cnt[pos][un][um][uk];
    if(ncnt != -1)
        return ncnt;
    int nb = un ? n[pos] : 1;
    int mb = um ? m[pos] : 1;
    ncnt = 0;
    for(int i = 0;i<=nb;i++){
        for(int j=0;j<=mb;j++){
            LL x = i ^ j;
            if(!uk || x >= k[pos]){
                ncnt += dfsn(pos-1,un && i==nb,um && j == mb,uk && x==k[pos]);
                ncnt %= p;
            }
        }
    }
    return ncnt;
}

LL dfs(int pos,bool un,bool um,bool uk){
    if(pos < 0) return 0;
    LL & ndp = dp[pos][un][um][uk];
    if(ndp != -1)
        return ndp;
    int nb = un ? n[pos] : 1;
    int mb = um ? m[pos] : 1;
    ndp = 0;
    for(int i=0;i<=nb;i++){
        for(int j=0;j<=mb;j++){
            LL x = i ^ j;
            if(!uk || x >= k[pos]){
                LL mid = x;
                mid *= dfsn(pos-1,un && i== nb,um && j == mb,uk && x==k[pos]);
               (mid *= tw[pos]) %= p;
                ndp += mid;
                (ndp += dfs(pos-1,un && i== nb,um && j == mb,uk && x==k[pos])) %= p;
           }
        }
    }
    return ndp;
}

LL cal(LL N,LL M,LL K){
    tw[0] = 1;
    for(int i=1;i<maxn;i++){
        tw[i] = (tw[i-1] * 2 ) % p;
    }
    N--,M--;
    biter(N,n);
    biter(M,m);
    biter(K,k);
    memset(dp,-1,sizeof(dp));
    memset(cnt,-1,sizeof(cnt));
    LL tim = dfsn(maxn-1,true,true,true);
    LL val = dfs(maxn-1,true,true,true);
    K %= p;
    tim *= K % p;
    (val -= tim % p ) %= p;
    val += p;
    val %= p;
    return val;
}

int main(){
    int T;
    LL N,M,K;
    cin>>T;
    while(T-- && cin>>N>>M>>K>>p){
        cout<<cal(N,M,K)<<endl;
    }
    return 0;
}
