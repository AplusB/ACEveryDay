#include <bits/stdc++.h>
using namespace std;
#define lson rt << 1
#define rson rt << 1 | 1
typedef long long LL;
const int maxn = 50005;
const int INF = 0x3f3f3f3f;
struct SegTree{
    int l, r, flag;
    LL sum, add;

    void Clear(){
        flag = 1;
        add = 0;
        sum = 0;
    }

    void Add(LL ad){
        add += ad;
        sum += (LL)(r - l + 1) * ad;
    }

}tree[maxn << 2];

void push_down(int rt){
    if(tree[rt].flag){
        tree[lson].Clear();
        tree[rson].Clear();
        tree[rt].flag = 0;
    }
    if(tree[rt].add){
        tree[lson].Add(tree[rt].add);
        tree[rson].Add(tree[rt].add);
        tree[rt].add = 0;
    }
}

void push_up(int rt){
    tree[rt].sum = tree[lson].sum + tree[rson].sum;
}

void build(int l, int r, int rt){
    tree[rt].l = l;
    tree[rt].r = r;
    tree[rt].add = tree[rt].sum = tree[rt].flag = 0;
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(l, mid, lson);
    build(mid + 1, r, rson);
}

void add(int l, int r, int rt, int val){
    if(l <= tree[rt].l && tree[rt].r <= r){
        tree[rt].Add(val);
        return;
    }
    push_down(rt);
    int mid = (tree[rt].l + tree[rt].r) >> 1;
    if(l <= mid)
        add(l, r, lson, val);
    if(mid < r)
        add(l, r, rson, val);
    push_up(rt);
}

void clear(int l, int r, int rt){
    if(l <= tree[rt].l && tree[rt].r <= r){
        tree[rt].Clear();
        return;
    }
    push_down(rt);
    int mid = (tree[rt].l + tree[rt].r) >> 1;
    if(l <= mid)
        clear(l, r, lson);
    if(mid < r)
        clear(l, r, rson);
    push_up(rt);
}

LL getsum(int l, int r, int rt){
    if(l <= tree[rt].l && tree[rt].r <= r){
        return tree[rt].sum;
    }
    push_down(rt);
    LL sum = 0;
    int mid = (tree[rt].l + tree[rt].r) >> 1;
    if(l <= mid)
        sum += getsum(l, r, lson);
    if(mid < r)
        sum += getsum(l, r, rson);
    return sum;
}

struct Query{
    int l, r, opt, id;
    LL c;
}query[maxn], A[maxn], B[maxn];
int ans[maxn], n;

void solve(int l, int r, int ql, int qr){
    if(ql > qr) return;
    if(l == r){
        for(int i = ql; i <= qr; i++){
            if(query[i].opt == 2)
                ans[query[i].id] = r;
        }
        return;
    }
    int mid = (l + r) >> 1, t1 = 0, t2 = 0;
    clear(1, n, 1);
    for(int i = ql; i <= qr; i++){
        if(query[i].opt == 1){
            if(query[i].c <= mid){
                add(query[i].l, query[i].r, 1, 1);
                A[++t1] = query[i];
            }else{
                B[++t2] = query[i];
            }
        }else{
            LL cnt = getsum(query[i].l, query[i].r, 1);
            if(cnt >= query[i].c){
                A[++t1] = query[i];
            }else{
                query[i].c -= cnt;
                B[++t2] = query[i];
            }
        }
    }
    int m = ql + t1 - 1;
    for(int i = ql; i <= m; i++) query[i] = A[i - ql + 1];
    for(int i = m + 1; i <= qr; i++) query[i] = B[i - m];
    solve(l, mid, ql, m);
    solve(mid + 1, r, m + 1, qr);
}

int main(){
    int q;
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= q; i++){
        scanf("%d%d%d%lld", &query[i].opt, &query[i].l, &query[i].r, &query[i].c);
        if(query[i].opt == 1) query[i].c = n - query[i].c + 1;
        query[i].id = i;
    }
    fill(ans, ans + q + 1, -INF);
    build(1, n, 1);
    solve(1, n + q, 1, q);
    for(int i = 1; i <= q; i++){
        if(ans[i] != -INF)
            printf("%d\n", n - ans[i] + 1);
    }
    return 0;
}


