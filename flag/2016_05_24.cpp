#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define lson rt << 1
#define rson rt << 1 | 1
const int maxn = 1e5 + 5;
struct SegTree{
    int l, r, id, sum;
}tree[maxn << 2];
int a[maxn];

int _max(int x, int y){
    return a[x] >= a[y] ? x : y;
}

void push_up(int rt){
    tree[rt].id = _max(tree[lson].id, tree[rson].id);
    tree[rt].sum = tree[lson].sum + tree[rson].sum;
}

void build(int l, int r, int rt){
    tree[rt].l = l;
    tree[rt].r = r;
    if(l == r){
        tree[rt].id = r;
        tree[rt].sum = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, lson);
    build(mid + 1, r, rson);
    push_up(rt);
}

void BeZero(int p, int rt){
    if(p == tree[rt].l && tree[rt].r == p){
        a[p] = 0;
        tree[rt].sum = 0;
        return;
    }
    int mid = (tree[rt].l + tree[rt].r) >> 1;
    if(p <= mid)
        BeZero(p, lson);
    else
        BeZero(p, rson);
    push_up(rt);
}

int getLast(int rt, int k){
    if(tree[rt].l == tree[rt].r){
        return tree[rt].r;
    }
    if(tree[lson].sum >= k)
        return getLast(lson, k);
    return getLast(rson, k - tree[lson].sum);
}

int getSum(int l, int r, int rt){
    if(l <= tree[rt].l && tree[rt].r <= r){
        return tree[rt].sum;
    }
    int mid = (tree[rt].l + tree[rt].r) >> 1;
    int sum = 0;
    if(l <= mid)
        sum += getSum(l, r, lson);
    if(mid < r)
        sum += getSum(l, r, rson);
    return sum;
}

int getMax(int l, int r, int rt){
    if(l <= tree[rt].l && tree[rt].r <= r){
        return tree[rt].id;
    }
    int mid = (tree[rt].l + tree[rt].r) >> 1;
    int id = 0;
    if(l <= mid)
        id = getMax(l, r, lson);
    if(mid < r)
        id = _max(id, getMax(l, r, rson));
    return id;
}

int main(){
    int N, K;
    scanf("%d%d", &N, &K);
    for(int i = 1; i <= N; i++){
        scanf("%d", &a[i]);
    }
    build(1, N, 1);
    for(int i = 1; i <= N && K; i++){
        int p = getLast(1, K + 1);
        int id = getMax(1, p, 1);
        printf("%d\n", a[id]);
        K -= getSum(1, id, 1) - 1;
        BeZero(id, 1);
    }
    for(int i = 1; i <= N; i++){
        if(a[i] != 0) printf("%d\n", a[i]);
    }
    return 0;
}

