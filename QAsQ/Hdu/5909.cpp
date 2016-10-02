#include<bits/stdc++.h>
using namespace std;

#define LL int 
const int maxn = 1123,mod = 1e9+7;
const int v2 = (mod + 1) / 2;

vector<int> edge[maxn];
int val[maxn],m;

LL dp[maxn][maxn];
LL tem[maxn];

void fwt (LL a[] , int n ) {
    for ( int d = 1 ; d < n ; d <<= 1 ) {
        for ( int k = d << 1 , i = 0 ; i < n ; i += k ) {
            for ( int j = 0 ; j < d ; ++ j ) {
                LL x = a[i + j] , y = a[i + j + d] ;
                a[i + j] = ( x + y ) % mod ;
                a[i + j + d] = ( x - y + mod ) % mod ;
            }
        }
    }
}

void ufwt (LL a[] , int n ) {
    for ( int d = 1 ; d < n ; d <<= 1 ) {
        for ( int k = d << 1 , i = 0 ; i < n ; i += k ) {
            for ( int j = 0 ; j < d ; ++ j ) {
                LL x = a[i + j] , y = a[i + j + d] ;
                a[i + j] = 1LL * ( x + y ) * v2 % mod ;
                a[i + j + d] = 1LL * ( x - y + mod ) * v2 % mod ;
            }
        }
    }
}

void solve(LL *a,LL *b){
    for(int i=0;i<m;i++) tem[i] = a[i]; 
    fwt(a,m),fwt(b,m);
    for(int i=0;i<m;i++)
        a[i] = (1ll * a[i] * b[i]) % mod;
    ufwt(a,m),ufwt(b,m);
    for(int i=0;i<m;i++) 
        a[i]=(a[i]+tem[i]) %mod;
}

void dfs(int st,int fa){
    dp[st][val[st]] = 1;
    for(auto x : edge[st]){
        if(x == fa) continue;
        dfs(x,st);
        solve(dp[st],dp[x]);
    }
}

LL ans[maxn];

int main(){
    int T,n;
    scanf("%d",&T);
    while(T-- && ~scanf("%d %d",&n,&m)){
        for(int i=0;i<=n;i++) edge[i].clear();
        int x,y;
        for(int i = 1;i <= n;i++) scanf("%d",&val[i]);
        int l,r;
        for(int i=1;i<n;i++){
            scanf("%d %d",&l,&r);
            edge[l].push_back(r);
            edge[r].push_back(l);
        }
        memset(dp,0,sizeof(dp));
        dfs(1,-1);
        memset(ans,0,sizeof(ans));
        for(int i=0;i<m;i++){
            for(int j=1;j<=n;j++)
                (ans[i] += dp[j][i]) %= mod;
        }
        for(int i=0;i<m;i++)
            printf(i<m-1?"%d ":"%d\n",ans[i]);
    }
    return 0;
}
