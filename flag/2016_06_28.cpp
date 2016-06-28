#include <bits/stdc++.h>
using namespace std;
const int maxn = 40005;
const int maxm = 100005;
int bk;
struct Edge{
    int v, next;
}E[maxn << 1];
int head[maxn], tol;
int block[maxn], dfn[maxn], S[maxn], g_cnt, top, sub;
int fa[maxn][17], dep[maxn];
int vis[maxn], cnt[maxn], col[maxn], ans;
int res[maxm];
vector < int > p;

struct Query{
    int u, v, id;
    void read(){
        scanf("%d%d", &u, &v);
        if(dfn[u] > dfn[v]) swap(u, v);
    }
    bool operator<(const Query& tmp) const{
        if(block[u] != block[tmp.u])
            return block[u] < block[tmp.u];
        return dfn[v] < dfn[tmp.v];
    }
}q[maxm];

void init(){
    memset(head, -1, sizeof head);
    tol = g_cnt = top = sub = ans = 0;
}

void add_edge(int u, int v){
    E[tol].v = v;
    E[tol].next = head[u];
    head[u] = tol++;
}

void dfs(int u, int pre){
    if(pre == -1) fa[u][0] = u;
    dfn[u] = ++g_cnt;
    for(int i = 1; i < 17; i++){
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for(int i = head[u]; ~i; i = E[i].next){
        int v = E[i].v;
        if(v == pre) continue;
        dep[v] = dep[u] + 1;
        fa[v][0] = u;
        dfs(v, u);
        if(top >= bk){
            sub++;
            while(top) block[S[top--]] = sub;
        }
    }
    S[++top] = u;
}

int up(int u, int h){
    for(int i = 0; i < 17; i++){
        if(h & (1 << i)) u = fa[u][i];
    }
    return u;
}

int LCA(int u, int v){
    if(dep[u] > dep[v]) swap(u, v);
    v = up(v, dep[v] - dep[u]);
    if(u == v) return u;
    for(int i = 16; i >= 0; i--){
        if(fa[u][i] != fa[v][i]){
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}

void update(int x){
    if(!vis[x]){
        vis[x] = 1;
        cnt[col[x]]++;
        if(cnt[col[x]] == 1) ans++;
    }else{
        vis[x] = 0;
        cnt[col[x]]--;
        if(cnt[col[x]] == 0) ans--;
    }
}

void gao(int u, int v){
    if(dep[u] < dep[v]) swap(u, v);
    while(dep[u] != dep[v]){
        update(u);
        u = fa[u][0];
    }
    while(u != v){
        update(u);
        update(v);
        u = fa[u][0];
        v = fa[v][0];
    }
}

void solve(int i){
    if(i == 1){
        gao(q[i].u, q[i].v);
    }else{
        gao(q[i - 1].u, q[i].u);
        gao(q[i - 1].v, q[i].v);
    }
    int lca = LCA(q[i].u, q[i].v);
    update(lca);
    res[q[i].id] = ans;
    update(lca);
}

int main(){
    int n, m, u, v;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &col[i]);
        p.push_back(col[i]);
    }
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    for(int i = 1; i <= n; i++){
        col[i] = lower_bound(p.begin(), p.end(), col[i]) - p.begin() + 1;
    }
    init();
    bk = sqrt(n);
    for(int i = 1; i < n; i++){
        scanf("%d%d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    for(int i = 1; i <= m; i++){
        q[i].read();
        q[i].id = i;
    }
    sort(q + 1, q + 1 + m);
    dfs(1, -1);
    if(top){
        sub++;
        while(top) block[S[top--]] = sub;
    }
    for(int i = 1; i <= m; i++){
        solve(i);
    }
    for(int i = 1; i <= m; i++){
        printf("%d\n", res[i]);
    }
    return 0;
}
