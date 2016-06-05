#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cctype>
#include <map>
#include <queue>
#include <vector>
#include <set>
#define pub push_back
#define mkp make_pair
#define B(x) (1 << (x))
typedef long long LL;
const int INF = 0x3f3f3f3f;
using namespace std;
const int maxn = 200005;
int a[maxn];
struct Edge{
    int v, next;
}E[maxn << 1];
int head[maxn], tol;
int vis[maxn], sz[maxn], mx[maxn], minSize, root, n;
int S[maxn], top;
LL dis[maxn], cnt[maxn];
LL ans, DIS, CNT;
vector < int > fac[maxn];
vector < int > p;
bool isp[maxn];

void init(){
    memset(isp, true, sizeof isp);
    for(int i = 2; i < maxn; i++){
        if(isp[i]) p.pub(i);
        for(int j = 0; j < p.size() && i * p[j] < maxn; j++){
            isp[i * p[j]] = false;
            if(i % p[j] == 0) break;
        }
    }
    memset(head, -1, sizeof head);
    tol = 0;
}

void get_fac(int x){
    int m = x;
    for(int i = 0; i < p.size() && (LL)p[i] * p[i] <= x; i++){
        if(x % p[i] == 0){
            fac[m].pub(p[i]);
            while(x % p[i] == 0) x /= p[i];
        }
    }
    if(x > 1){
        fac[m].pub(x);
    }
}

void add_edge(int u, int v){
    E[tol].v = v;
    E[tol].next = head[u];
    head[u] = tol++;
}

void get_size(int u, int pre){
	sz[u] = 1;
	mx[u] = 0;
	for(int i = head[u]; ~i; i = E[i].next){
		int v = E[i].v;
		if(v == pre || vis[v]) continue;
		get_size(v, u);
		sz[u] += sz[v];
		if(sz[v] > mx[u]) mx[u] = sz[v];
	}
}

void get_root(int rt, int u, int pre){
	if(sz[rt] - sz[u] > mx[u]){
		mx[u] = sz[rt] - sz[u];
	}
	if(mx[u] < minSize){
		minSize = mx[u];
		root = u;
	}
	for(int i = head[u]; ~i; i = E[i].next){
		int v = E[i].v;
		if(v == pre || vis[v]) continue;
		get_root(rt, v, u);
	}
}

LL count(int x, int d){
    int m = fac[x].size(), ct;
    LL mul, res = 0;
    for(int mask = 1; mask < (1 << m); mask++){
        mul = 1;
        ct = 0;
        for(int i = 0; i < m; i++){
            if(mask & (1 << i)){
                mul *= fac[x][i];
                ct++;
            }
        }
        if(ct & 1) res += dis[mul] + cnt[mul] * d;
        else res -= dis[mul] + cnt[mul] * d;
    }
    return DIS + CNT * d - res;
}

void cal(int u, int pre, int d){
    ans += count(a[u], d);
    for(int i = head[u]; ~i; i = E[i].next){
        int v = E[i].v;
        if(v == pre || vis[v]) continue;
        cal(v, u, d + 1);
    }
}

void add(int u, int pre, int d){
    dis[a[u]] += d;
    cnt[a[u]]++;
    DIS += d;
    CNT++;
    S[++top] = a[u];
    for(int i = head[u]; ~i; i = E[i].next){
        int v = E[i].v;
        if(v == pre || vis[v]) continue;
        add(v, u, d + 1);
    }
}

void solve(int u){
    minSize = n + 1;
    get_size(u, -1);
    get_root(u, u, -1);
    vis[root] = 1;
    for(int i = 1; i <= top; i++){
        dis[S[i]] = 0;
        cnt[S[i]] = 0;
    }
    top = 0;
    DIS = 0;
    CNT = 1;
    dis[a[root]] = 0;
    cnt[a[root]] = 1;
    S[++top] = a[root];
    for(int i = head[root]; ~i; i = E[i].next){
        int v = E[i].v;
        if(vis[v]) continue;
        cal(v, root, 1);
        add(v, root, 1);
    }
    for(int i = head[root]; ~i; i = E[i].next){
        int v = E[i].v;
        if(vis[v]) continue;
        solve(v);
    }
}

int main(){
    int u, v;
    init();
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n; i++){
        get_fac(a[i]);
    }
    for(int i = 1; i < n; i++){
        scanf("%d%d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    ans = 0;
    solve(1);
    printf("%lld\n", ans);
    return 0;
}

