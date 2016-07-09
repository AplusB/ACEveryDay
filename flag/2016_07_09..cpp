#include <bits/stdc++.h>
using namespace std;
#define lson rt << 1
#define rson rt << 1 | 1
typedef long long LL;
const int maxn = 3e5 + 5;
int up[maxn], n, m, k;
LL sum[maxn];
struct Opt{
    int l, r, a;
}opt[maxn];
int id[maxn], A[maxn], B[maxn], ans[maxn];
vector < int > G[maxn];

struct BIT{
    LL sum[maxn];
    int n;

    void init(int n){
        memset(sum, 0, sizeof sum);
        this->n = n;
    }

    inline int lowbit(int x){
        return x & (-x);
    }

    void Add(int l, int r, int add){
        for(int i = l; i <= n; i += lowbit(i)){
            sum[i] += add;
        }
        for(int i = r + 1; i <= n; i += lowbit(i)){
            sum[i] -= add;
        }
    }

    LL getSum(int x){
        LL res = 0;
        for(int i = x; i; i -= lowbit(i)){
            res += sum[i];
        }
        return res;
    }

}gao;

void solve(int l, int r, int L, int R){
    if(L > R) return;
    if(l == r){
        for(int i = L; i <= R; i++){
            ans[id[i]] = r;
        }
        return;
    }
    int mid = (l + r) >> 1, t1 = 0, t2 = 0;
    for(int i = l; i <= mid; i++){
        if(opt[i].l <= opt[i].r)
            gao.Add(opt[i].l, opt[i].r, opt[i].a);
        else{
            gao.Add(opt[i].l, m, opt[i].a);
            gao.Add(1, opt[i].r, opt[i].a);
        }
    }
    for(int i = L; i <= R; i++){
        sum[id[i]] = 0;
        for(int j = 0; j < G[id[i]].size(); j++){
            sum[id[i]] += gao.getSum(G[id[i]][j]);
            if(sum[id[i]] >= up[id[i]]){
                A[++t1] = id[i];
                break;
            }
        }
        if(sum[id[i]] < up[id[i]]){
            up[id[i]] -= sum[id[i]];
            B[++t2] = id[i];
        }
    }
    for(int i = l; i <= mid; i++){
        if(opt[i].l <= opt[i].r)
            gao.Add(opt[i].l, opt[i].r, -opt[i].a);
        else{
            gao.Add(opt[i].l, m, -opt[i].a);
            gao.Add(1, opt[i].r, -opt[i].a);
        }
    }
    int m = L + t1 - 1;
    for(int i = L; i <= m; i++) id[i] = A[i - L + 1];
    for(int i = m + 1; i <= R; i++) id[i] = B[i - m];
    solve(l, mid, L, m);
    solve(mid + 1, r, m + 1, R);
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++){
        int x;
        scanf("%d", &x);
        G[x].push_back(i);
    }
    for(int i = 1; i <= n; i++){
        scanf("%d", &up[i]);
        id[i] = i;
    }
    scanf("%d", &k);
    for(int i = 1; i <= k; i++){
        scanf("%d%d%d", &opt[i].l, &opt[i].r, &opt[i].a);
    }
    k++;
    opt[k].l = 1, opt[k].r = m, opt[k].a = 1e9;
    gao.init(m);
    solve(1, k, 1, n);
    for(int i = 1; i <= n; i++){
        if(ans[i] == k) puts("NIE");
        else printf("%d\n", ans[i]);
    }
    return 0;
}
