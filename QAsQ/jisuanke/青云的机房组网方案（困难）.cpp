#include<bits/stdc++.h>
using namespace std;
#define LL long long

const int maxn = 212345,maxm = 212345,max_log = 18;
const int ROOT = 1;

vector<pair<int,LL> > vedge[maxn];
vector<int> edge[maxn];

LL siz[maxn];
int is[maxn];

void dffs(int st,int fa){
    siz[st] = is[st];
    for(auto x : vedge[st]){
        if(x.first != fa){
            dffs(x.first,st);
            siz[st] += siz[x.first];
        }
    }
}

LL dfss(int st,int fa,int n){
    LL ret = 0;
    for(auto it : vedge[st]){
        int x = it.first; LL v = it.second;
        if(x != fa){
            ret += dfss(x,st,n);
            ret += v * siz[x] * (n-siz[x]);
        }
    }
    return ret;
}

LL dpfs(int n){
    dffs(0,-1);
    return dfss(0,-1,siz[0]);
}

int dfn[maxn],_cnt;
int deep[maxn],fa[maxn][max_log];

void dfs(int st,int Fa,int Deep=1){
    dfn[st] = _cnt++;
    for(int i=1;i<max_log;i++)
        fa[st][i] = -1;
    fa[st][0] = Fa,deep[st] = Deep;
    for(auto x : edge[st]){
        if(x == Fa) continue;
        dfs(x,st,Deep+1);
    }
}

void init(int n){
    _cnt = 1;
    memset(fa,-1,sizeof(fa));
    dfs(ROOT,-1);
    for (int j = 1;j < max_log;j++){
        for (int i = 1;i <= n;i++){
            if (fa[i][j-1] != -1){
                fa[i][j] = fa[fa[i][j-1]][j-1];
            }
        }
    }
}

int Lca(int x,int y){
    LL ix,iy;
    ix = iy = 0;
    if (deep[x] < deep[y]) swap(x,y);
    for (int i = max_log-1;i >= 0;i--){
        if (deep[fa[x][i]] >= deep[y]){
            x = fa[x][i];
        }
    }
    if (x == y) return x; 
    for (int i = max_log-1;i >= 0;i--){
        if (fa[x][i] != fa[y][i]){
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
}

int val[maxn],cid[maxn],sid[maxn];
int cnt;

int tcid(int v){
    if(sid[v] != -1) return sid[v];
    sid[v] = cnt, cid[cnt] = v;
    return cnt++;
}

void Link(int st,int ed,int v = -1){
    if(v == -1) v = abs(deep[st] - deep[ed]);
    if(v==0) return;
    st = tcid(st),ed = tcid(ed);
    vedge[st].push_back(make_pair(ed,v));
    vedge[ed].push_back(make_pair(st,v));
}

struct Stack{
    int sta[maxn],_cnt;
    int last;
    void init(){ _cnt = 0, last = -1; }
    bool empty(){ return _cnt==0; }
    int top(){ return sta[_cnt-1]; }
    void push(int x){
        if(last != -1) 
            Link(last,x);
        sta[_cnt++] = x;
        last = -1;
    }
    void pop(){
        if(last != -1)
            Link(this->top(),last);
        last = this->top();
        _cnt--;
    } 
}S;

vector<int> hav[maxn];
LL bvtree(int k){
    sort(hav[k].begin(),hav[k].end(),[](int x,int y){return dfn[x] < dfn[y];});

    cnt = 0;
    S.init();
    for(auto x : hav[k]){
        if(S.empty()){ 
            S.push(x);
            continue;
        }
        int lca = Lca(S.top(),x);
        while(S.empty()==false && deep[S.top()] >= deep[lca])
            S.pop();
        if(S.empty() || deep[S.top()] < deep[lca])
            S.push(lca);
        if(lca != x)
            S.push(x);
    }
    while(S.empty()==false) S.pop();

    for(int i=0;i<cnt;i++)
        is[i] = val[cid[i]] % k == 0;
    LL ret = dpfs(cnt);
    for(int i=0;i<cnt;i++){
        vedge[i].clear();
        sid[cid[i]] = -1;
        cid[i] = -1;
    }
    return ret;
}

vector<int> fac[maxn];
int mu[maxn];

int main(){
    int n;
    for(int i=1;i<maxn;i++){
        for(int j=i;j<maxn;j+=i)
            fac[j].push_back(i);
    }
    memset(mu,0,sizeof(mu));
    mu[1] = 1;
    for(int i=1;i<maxn;i++){
        for(int j=2*i;j<maxn;j+=i)
            mu[j] -= mu[i];
    }

    while(~scanf("%d",&n)){
        for(int i=0;i<=n;i++)
            edge[i].clear(),hav[i].clear(),vedge[i].clear();
        int v;
        for(int i=1;i<=n;i++){
            scanf("%d",&v);
            val[i] = v;
            for(auto x : fac[v]){
                if(mu[x]) hav[x].push_back(i);
            }
        }
        int l,r;
        for(int i=1;i<n;i++){
            scanf("%d %d",&l,&r);
            edge[l].push_back(r);
            edge[r].push_back(l);
        }
        init(n);

        memset(sid,-1,sizeof(sid));
        LL ans = 0;
        for(int i=1;i<maxn;i++){
            if(hav[i].empty() == false)
                ans += mu[i] * bvtree(i);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
