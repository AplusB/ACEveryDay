#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 5e4 + 5;
const int maxm = 1e5 + 5;
vector < LL > a;
LL path[maxn];
int vis[maxn];
struct Edge{
    int v, next;
    LL w;
}E[maxm << 1];
int head[maxn], tol;

void init(){
    memset(head, -1, sizeof head);
    tol = 0;
    a.clear();
    memset(vis, 0, sizeof vis);
    memset(path, 0, sizeof path);
}

void add_edge(int u, int v, LL w){
    E[tol].v = v;
    E[tol].w = w;
    E[tol].next = head[u];
    head[u] = tol++;
}

void dfs(int u, int pre, int step){
    vis[u] = step;
    for(int i = head[u]; ~i; i = E[i].next){
        int v = E[i].v;
        if(v == pre) continue;
        if(!vis[v]){
            path[v] = path[u] ^ E[i].w;
            dfs(v, u, step + 1);
        }else if(vis[v] < step){
            a.push_back(path[v] ^ path[u] ^ E[i].w);
        }
    }
}

void Gauss(){
    int n = a.size();
    int c, r = 0, k;
    for(c = 60; c >= 0; c--){
        k = -1;
        for(int i = r; i < n; i++)
            if((a[i] >> c) & 1){
                k = i;
                break;
            }
        if(k != -1){
            swap(a[r], a[k]);
            for(int i = 0; i < n; i++){
                if(i == r) continue;
                if((a[i] >> c) & 1)
                    a[i] ^= a[r];
            }
            r++;
        }
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
}

int main(){
    int T, N, M, u, v;
    LL w;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        init();
        scanf("%d%d", &N, &M);
        for(int i = 1; i <= M; i++){
            scanf("%d%d%lld", &u, &v, &w);
            add_edge(u, v, w);
            add_edge(v, u, w);
        }
        dfs(1, -1, 1);
        Gauss();
        LL ans = 0;
        for(int i = 0; i < a.size(); i++){
            ans ^= a[i];
        }
        printf("Case #%d: %lld\n", cas, ans);
    }
    return 0;
}
