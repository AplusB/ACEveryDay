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
                while(S.top()!=x){
                    forLink(forcnt,S.top());
                    S.pop();
                }
                S.pop();
                forLink(forcnt,x);
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
}


