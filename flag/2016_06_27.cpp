#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
struct Edge2{
    int u, v, w;
}edge[maxn];
struct Edge{
    int v, next;
}E[maxn << 1];
int head[maxn], tot;
int ls[maxn * 20], rs[maxn * 20], sum[maxn * 20], T[maxn], a[maxn], tol, n;
int fa[maxn][20], dep[maxn];
vector < int > p;

void init(){
    memset(head, -1, sizeof head);
    tot = tol = 0;
    p.clear();
}

void add_edge(int u, int v){
    E[tot].v = v;
    E[tot].next = head[u];
    head[u] = tot++;
}

void dfs(int u, int pre){
    if(pre == -1) dep[u] = 0;
    for(int i = head[u]; ~i; i = E[i].next){
        int v = E[i].v;
        if(v == pre) continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}

int build(int l, int r){
    int rt = ++tol;
    if(l == r) return rt;
    int mid = (l + r) >> 1;
    ls[rt] = build(l, mid);
    rs[rt] = build(mid + 1, r);
    return rt;
}

int update(int rt, int pos, int l = 1, int r = n){
    int nrt = ++tol;
    ls[nrt] = ls[rt];
    rs[nrt] = rs[rt];
    sum[nrt] = sum[rt] + 1;
    if(l == r) return nrt;
    int mid = (l + r) >> 1;
    if(pos <= mid)
        ls[nrt] = update(ls[rt], pos, l, mid);
    else
        rs[nrt] = update(rs[rt], pos, mid + 1, r);
    return nrt;
}

int query(int u, int v, int lca, int k, int l = 1, int r = n){
    if(l == r) return r;
    int mid = (l + r) >> 1;
    int cnt = sum[ls[u]] + sum[ls[v]] - 2 * sum[ls[lca]];
    if(k <= cnt)
        return query(ls[u], ls[v], ls[lca], k, l, mid);
    else
        return query(rs[u], rs[v], rs[lca], k - cnt, mid + 1, r);
}

void bfs(int rt){
    T[rt] = build(1, n);
    queue < int > q;
    q.push(rt);
    fa[rt][0] = rt;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i = 1; i < 20; i++){
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }
        for(int i = head[u]; ~i; i = E[i].next){
            int v = E[i].v;
            if(v == fa[u][0]) continue;
            q.push(v);
            fa[v][0] = u;
            a[v] = lower_bound(p.begin(), p.end(), a[v]) - p.begin();
            T[v] = update(T[u], a[v]);
        }
    }
}

int up(int u, int h){
    for(int i = 19; i >= 0; i--){
        if(h >= (1 << i)){
            h -= (1 << i);
            u = fa[u][i];
        }
    }
    return u;
}

int LCA(int u, int v){
    if(dep[u] > dep[v]) swap(u, v);
    v = up(v, dep[v] - dep[u]);
    if(u == v) return u;
    for(int i = 19; i >= 0; i--){
        if(fa[u][i] != fa[v][i]){
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}

int main(){
    int q, u, v, w;
    while(scanf("%d%d", &n, &q) != EOF){
        init();
        for(int i = 1; i < n; i++){
            scanf("%d%d%d", &u, &v, &w);
            add_edge(u, v);
            add_edge(v, u);
            edge[i].u = u;
            edge[i].v = v;
            edge[i].w = w;
        }
        dfs(1, -1);
        for(int i = 1; i < n; i++){
            if(dep[edge[i].u] > dep[edge[i].v]) swap(edge[i].u, edge[i].v);
            a[edge[i].v] = edge[i].w;
            p.push_back(edge[i].w);
        }
        p.push_back(-1);
        sort(p.begin(), p.end());
        p.erase(unique(p.begin(), p.end()), p.end());
        bfs(1);
        for(int i = 1; i <= q; i++){
            scanf("%d%d", &u, &v);
            int lca = LCA(u, v);
            int sz = dep[u] + dep[v] - 2 * dep[lca];
            printf("%d\n", p[query(T[u], T[v], T[lca], (sz + 1) / 2)]);
        }
    }
	return 0;
}
