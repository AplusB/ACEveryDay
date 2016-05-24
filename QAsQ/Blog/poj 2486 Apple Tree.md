# poj 2486 Apple Tree

给出一个树，每次跨过一条边记做走一步，可以往回走，每个点有一些苹果，问从根出发在$k$步之内最多能拿到多少苹果

-----

对于每一个节点，我们记

$Vgo_x$为从这个点出发走x步不回到这个点最多能拿到的苹果数

$Vback_x$为从这个点出发走x步回到这个点最多能拿到的苹果数

$Val$为这个点上的苹果数

-----

对于每个点，能不走就拿到的苹果数目其实就是这个点的苹果数

也就是$Vgo_0=Vback_0=Val$

然后对于一个节点，我们考虑他和他子节点的关系

这部分的转移就不细说了

------

还有一些磨人的细节

因为我们定义的是正好走这么多步之后能拿到的苹果，所以我们还要考虑不到$k$步就拿到了最优解的情况

还有就是建议开一个辅助数组而不是直接在$dp$数组上进行转移，因为每次添加一个子树$x$转移的时候需要用到的是含有$x$作为子树之前的一些值和含有x作为子树之后的一些值。

这部分就具体见代码吧

```cpp
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn = 110;
const int maxk = 250;
vector<int> edge[maxn];
void init(int n){
    for(int i=0;i<=n;i++){
        edge[i].clear();
    }
}
void Link(int st,int ed){
    edge[st].push_back(ed);
    edge[ed].push_back(st);
}
int k;
int val[maxn];
int dp[maxn][2][maxk]; // 0 back 1 notback

void upd(int &a,int b){
    if(a<b) a=b;
}

void dfs(int st,int fa){
    int valer[2][maxk];
    memset(valer,0,sizeof(valer));
    dp[st][0][0] = dp[st][1][0] = val[st];
    for(vector<int>::iterator it = edge[st].begin();it!=edge[st].end();it++){
        int x = *it;
        if(x == fa) continue;
        dfs(x,st);
        for(int i=0;i<=k;i++){
            for(int j=0;j<=i-1;j++){
                upd(valer[1][i],dp[st][0][j]+dp[x][1][i-1-j]);
                if(j==i-1) continue;
                upd(valer[0][i],dp[st][0][j]+dp[x][0][i-2-j]);
                upd(valer[1][i],dp[st][1][j]+dp[x][0][i-2-j]);
            }
        }
        for(int i=0;i<=k;i++){
            upd(dp[st][0][i],valer[0][i]);
            upd(dp[st][1][i],valer[1][i]);
        }
    }
}

int main(){
    int n;
    while(~scanf("%d %d",&n,&k)){
        init(n);
        int u,v;
        for(int i=1;i<=n;i++){
            scanf("%d",&val[i]);
        }
        for(int i=1;i<n;i++){
            scanf("%d %d",&u,&v);
            Link(u,v);
        }
        memset(dp,0,sizeof(dp));
        dfs(1,0);
        int ans = *max_element(dp[1][1],dp[1][1]+k+1);
        printf("%d\n",ans);
    }
    return 0;
}

```

