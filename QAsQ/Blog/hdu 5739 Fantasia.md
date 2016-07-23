#hdu 5739 Fantasia

给出一个点带权的图，定义一个联通分量的价值为所有点的权值的乘积

定义一个点的价值为这个删掉这个点之后的所有联通分量的价值的和

求所有点的价值

----

偷偷贴上[题解](http://bestcoder.hdu.edu.cn/blog/2016-multi-university-training-contest-2-solutions-by-zimpha/)

>首先求出所有的点双联通分量, 对于每一个点双联通分量$S$, 新建一个节点$s$, 向$S$中每个节点$v$连边. 这样一来, 新增的点和原来图中的点会构成一个森林(据说这个有个名字, block forest data structure). 很容易观察到, 叶子节点肯定都是非关键点, 内部节点要么是关键点, 要么是新增的节点.
>对于这个森林$F$, 删掉一个关键点或者一个叶子$i$之后, 会得到一个新森林$F_i$, 这个$F_i$对应的连通块集合和$G_i$对应的连通块集合其实是一样的(不考虑那些新增的点). 显然$G_i$的权值和$F_i$的权值也是一样的, $F_i$的权值我们很容易通过树形dp算出来, 那么$G_i$的权值也随之而出.


```cpp
#include<bits/stdc++.h>
using namespace std;
#define LL long long 
const int maxn  = 112345;
const int mod = 1000000007;

vector<int> edge[maxn];
vector<int> DccForest[maxn*2];
int dfn[maxn],low[maxn];
int _cnt,forcnt;
stack<int> S;

void init(){
    memset(low,-1,sizeof(low));
    memset(dfn,-1,sizeof(dfn));
    _cnt = 1;
    while(S.empty()==false) S.pop();
    for(int i=0;i<maxn*2;i++){
        DccForest[i].clear();
    }
}
void forLink(int st,int ed){
    DccForest[st].push_back(ed);
    DccForest[ed].push_back(st);
}

void tarjan(int st,int fa){
    low[st] = dfn[st] = _cnt++;
    S.push(st);
    for(auto x : edge[st]){
        if(x == fa) continue;
        if(dfn[x] == -1){
            tarjan(x,st);
            low[st] = min(low[st],low[x]);
            if(low[x] >= dfn[st]){
                int top;
                do{
                    top = S.top(),S.pop();
                    forLink(forcnt,top);
                }while(top != x);
                forLink(forcnt,st);
                forcnt++;
            }
        }
        else{
            low[st] = min(low[st],dfn[x]);
        }
    }
}


int getDccForest(int n){
    init();
    forcnt = n+1;
    for(int i=1;i<=n;i++)
        if(dfn[i]==-1)
            tarjan(i,0);
    return forcnt-1;
}

void initEdge(int n){
    for(int i=0;i<=n;i++){
        edge[i].clear();
    }
}
LL pmod(LL x,int n){
    LL ret = 1;
    while(n){
        if(n&1) (ret *= x) %= mod;
        (x *= x)%= mod;
        n>>=1;
    } 
    return ret;
}

LL rev(LL x){
    return pmod(x,mod-2);
}

LL w[maxn], sv[maxn*2];
bool vis[maxn*2];
int n;

LL dffs(int st,int fa){
    vis[st] = true;
    sv[st] = st > n ? 1 : w[st];
    for(auto x : DccForest[st]){
        if(x == fa) continue;
        (sv[st] *= dffs(x,st)) %= mod;
    }
    return sv[st];
}

LL anw[maxn*2];
void dfss(int st,int fa,LL all,LL lef){
    vis[st] = true;
    anw[st] = lef;

    for(auto x : DccForest[st]){
        if(x == fa) continue;
        dfss(x,st,all,lef);
        (anw[st] += sv[x]) %= mod;
    }
    if(fa != 0)
        (anw[st] += (all * rev(sv[st])) % mod) %= mod;
}

int main(){
    int T;
    int m;
    scanf("%d",&T);
    while(T-- && ~scanf("%d %d",&n,&m)){
        initEdge(n);
        for(int i=1;i<=n;i++){
            scanf("%I64d",&w[i]);
        }
        int l,r;
        while(m--){
            scanf("%d %d",&l,&r);
            edge[l].push_back(r);
            edge[r].push_back(l);
        }
        int len = getDccForest(n);
        memset(vis,0,sizeof(vis));
        LL splus = 0;
        for(int i=1;i<=n;i++){
            if(vis[i] == false){
                (splus += dffs(i,0)) %= mod;
            }
        }
        memset(vis,0,sizeof(vis));
        LL ans = 0;
        for(int i=1;i<=n;i++){
            if(vis[i]==false){
                dfss(i,0,sv[i],(splus - sv[i] + mod ) % mod);
            }
        }
        for(int i=1;i<=n;i++){
            (ans += anw[i] * i ) %= mod;
        }
        printf("%I64d\n",ans);
    }
    return 0;
```