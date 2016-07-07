#include <bits/stdc++.h>
using namespace std;
#define lson rt << 1
#define rson rt << 1 | 1
typedef long long LL;
const int md = 1000000007;
const int maxn = 3e5 + 5;

struct BIT{
    int sum[maxn], n;

    void init(int n){
        fill(sum, sum + n + 1, 0);
        this->n = n;
    }

    inline int lowbit(int x){
        return x & (-x);
    }

    void update(int l, int r, int add){
        for(int i = l; i <= n; i += lowbit(i)){
            sum[i] = (sum[i] + add) % md;
        }
        for(int i = r + 1; i <= n; i += lowbit(i)){
            sum[i] = (sum[i] - add + md) % md;
        }
    }

    int query(int p){
        int res = 0;
        for(int i = p; i; i -= lowbit(i)){
            res = (res + sum[i]) % md;
        }
        return res;
    }

}gao1, gao2;

int L[maxn], R[maxn], dep[maxn];
struct Edge{
    int v, next;
}E[maxn << 1];
int head[maxn], tol, cnt;

void init(){
    memset(head, -1, sizeof head);
    tol = cnt = 0;
}

void add_edge(int u, int v){
    E[tol].v = v;
    E[tol].next = head[u];
    head[u] = tol++;
}

void dfs(int u){
    L[u] = ++cnt;
    for(int i = head[u]; ~i; i = E[i].next){
        dep[E[i].v] = dep[u] + 1;
        dfs(E[i].v);
    }
    R[u] = cnt;
}

int main(){
    int n, q, p, v, x, k, opt;
    scanf("%d", &n);
    init();
    for(int i = 2; i <= n; i++){
        scanf("%d", &p);
        add_edge(p, i);
    }
    gao1.init(n);
    gao2.init(n);
    dfs(1);
    scanf("%d", &q);
    while(q--){
        scanf("%d", &opt);
        if(opt == 1){
            scanf("%d%d%d", &v, &x, &k);
            gao1.update(L[v], R[v], (x + (LL)dep[v] * k % md) % md);
            gao2.update(L[v], R[v], k);
        }else{
            scanf("%d", &v);
            int ans = (gao1.query(L[v]) - (LL)gao2.query(L[v]) * dep[v] % md + md) % md;
            printf("%d\n", ans);
        }
    }
    return 0;
}
