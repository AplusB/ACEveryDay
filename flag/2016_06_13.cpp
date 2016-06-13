#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 100005;

struct BIT{
    int Min[maxn], p[maxn], n;

    void Init(int n){
        memset(Min, 0x3f, sizeof Min);
        memset(p, -1, sizeof p);
        this->n = n;
    }

    inline int lowbit(int x){ return x & (-x); }

    void update(int x, int num, int pos){
        for(int i = x; i <= n; i += lowbit(i)){
            if(num < Min[i]){
                Min[i] = num;
                p[i] = pos;
            }
        }
    }

    int query(int x){
        int mx = INF, pos = -1;
        for(int i = x; i ; i -= lowbit(i)){
            if(Min[i] < mx){
                mx = Min[i];
                pos = p[i];
            }
        }
        return pos;
    }

}gao;

struct POINT{
    int x, y, id;

    void read(){
        scanf("%d%d", &x, &y);
    }

    bool operator<(const POINT& p) const{
        if(x == p.x)
            return y < p.y;
        return x < p.x;
    }

}a[maxn];
int b[maxn];

struct EDGE{
    int u, v, w;
    bool operator<(const EDGE& e) const{
        return w < e.w;
    }
}edge[maxn << 2];
int fa[maxn], tol;

void Spanning_Init(int n){
    for(int i = 1; i <= n; i++){
        fa[i] = i;
    }
    tol = 0;
}

void add_edge(int u, int v, int w){
    edge[tol].u = u;
    edge[tol].v = v;
    edge[tol].w = w;
    tol++;
}

int Find(int x){
    return x == fa[x] ? fa[x] : fa[x] = Find(fa[x]);
}

bool Merge(int x, int y){
    int fx = Find(x);
    int fy = Find(y);
    if(fx != fy){
        fa[fx] = fy;
        return true;
    }
    return false;
}

void gao1(int n){
    for(int i = 1; i <= n; i++){
        swap(a[i].x, a[i].y);
    }
}

void gao2(int n){
    for(int i = 1; i <= n; i++){
        a[i].x = -a[i].x;
    }
}

int dis(POINT p1, POINT p2){
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

void getEdge(int n){
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++){
        b[i] = -a[i].y + a[i].x;
    }
    sort(b + 1, b + 1 + n);
    int m = unique(b + 1, b + 1 + n) - b - 1;
    gao.Init(m);
    for(int i = n; i >= 1; i--){
        int tmp = lower_bound(b + 1, b + 1 + m, -a[i].y + a[i].x) - b;
        int p = gao.query(tmp);
        if(p != -1){
            add_edge(a[i].id, a[p].id, dis(a[i], a[p]));
        }
        gao.update(tmp, a[i].x + a[i].y, i);
    }
}

LL ManHaDun_Spanning(int n){
    Spanning_Init(n);
    getEdge(n);
    gao1(n);
    getEdge(n);
    gao2(n);
    getEdge(n);
    gao1(n);
    getEdge(n);
    sort(edge, edge + tol);
    LL ans = 0;
    for(int i = 0; i < tol; i++){
        if(Merge(edge[i].u, edge[i].v)){
            ans += edge[i].w;
        }
    }
    return ans;
}

int main(){
    int n, cas = 0;
    while(scanf("%d", &n) && n){
        for(int i = 1; i <= n; i++){
            a[i].read();
            a[i].id = i;
        }
        printf("Case %d: Total Weight = %lld\n", ++cas, ManHaDun_Spanning(n));
    }
    return 0;
}
