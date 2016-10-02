# Hdu 5909 Tree Cutting



$n(n\le 1000)$个点的树上每个点有一个权值$(0\le C_i < m,m\le 2^{10})$，定义一个子树的权值为这个子树节点的权值的异或。分别求权值为$[0,m-1]$的子树的个数$mod(10^9+7)$

----

对于一个无根树的子树，如果我们钦定一个点作为无根树的根，那么对于这个树的所有子树都可以钦定出唯一的一个点作为根。

考虑树$dp$ ,记$dp_{st,v}$为以st为根，异或和为$v$的子树个数

那么对于一个状态$dp_{st}$我们有加入$st$的一个子树$x$之后的新的状态$dp_{nst}$的值$dp_{nst,v} = dp_{st_v} + \sum\limits_{i \oplus j}dp_{st,i}\times dp_{x,j}$

---

直接这么树$dp$的复杂度是$O(n \times m^2)$的，我们意外的发现中间的这个$ \sum\limits_{i \oplus j}dp_{st,i}\times dp_{x,j}$就是一个xor卷积，于是可以用FWT将他从$O(m^2)$优化到 $O(m \times log(m))$，总的复杂度优化到$O(n \times m \times log(m))$就可以通过此题

----

```cpp
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
```

