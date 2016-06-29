#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = (int)(3e5 + 5);
const int maxm = (int)(1e7 + 5);
int phi[maxm], p[maxm];
bool isp[maxm];

void getPhi(){
    memset(isp, true, sizeof isp);
    isp[1] = false;
    phi[1] = 1;
    int tol = 0;
    for(int i = 2; i < maxm; i++){
        if(isp[i]){
            p[tol++] = i;
            phi[i] = i - 1;
        }
        for(int j = 0; j < tol && i * p[j] < maxm; j++){
            isp[i * p[j]] = false;
            if(i % p[j] == 0){
                phi[i * p[j]] = phi[i] * p[j];
                break;
            }else{
                phi[i * p[j]] = phi[i] * (p[j] - 1);
            }
        }
    }
}

#define lson rt << 1
#define rson rt << 1 | 1
struct SegTree{
    int l, r, num, cover;
    LL sum;
    int mid(){ return (l + r) >> 1; }
    void Cover(int cv){
        cover = cv;
        num = cv;
        sum = (LL)cv * (r - l + 1);
    }
}tree[maxn << 2];

void push_down(int rt){
    if(tree[rt].cover != -1){
        tree[lson].Cover(tree[rt].cover);
        tree[rson].Cover(tree[rt].cover);
        tree[rt].cover = -1;
    }
}

void push_up(int rt){
    tree[rt].num = tree[lson].num == tree[rson].num ? tree[lson].num : 0;
    tree[rt].sum = tree[lson].sum + tree[rson].sum;
}

void build(int l, int r, int rt){
    tree[rt].l = l;
    tree[rt].r = r;
    tree[rt].num = 0;
    tree[rt].sum = 0;
    tree[rt].cover = -1;
    if(l == r){
        scanf("%d", &tree[rt].num);
        tree[rt].sum = tree[rt].num;
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, lson);
    build(mid + 1, r, rson);
    push_up(rt);
}

void Phi(int l, int r, int rt){
    if(tree[rt].num && l <= tree[rt].l && tree[rt].r <= r){
        tree[rt].Cover(phi[tree[rt].num]);
        return;
    }
    push_down(rt);
    int mid = tree[rt].mid();
    if(l <= mid) Phi(l, r, lson);
    if(mid < r) Phi(l, r, rson);
    push_up(rt);
}

void Cover(int l, int r, int rt, int c){
    if(l <= tree[rt].l && tree[rt].r <= r){
        tree[rt].Cover(c);
        return;
    }
    push_down(rt);
    int mid = tree[rt].mid();
    if(l <= mid) Cover(l, r, lson, c);
    if(mid < r) Cover(l, r, rson, c);
    push_up(rt);
}

LL getSum(int l, int r, int rt){
    if(l <= tree[rt].l && tree[rt].r <= r){
        return tree[rt].sum;
    }
    push_down(rt);
    int mid = tree[rt].mid();
    LL sum = 0;
    if(l <= mid) sum += getSum(l, r, lson);
    if(mid < r) sum += getSum(l, r, rson);
    return sum;
}

int main(){
    getPhi();
    int T, n, m, l, r, x, ope;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &m);
        build(1, n, 1);
        for(int i = 1; i <= m; i++){
            scanf("%d", &ope);
            if(ope == 1){
                scanf("%d%d", &l, &r);
                Phi(l, r, 1);
            }else if(ope == 2){
                scanf("%d%d%d", &l, &r, &x);
                Cover(l, r, 1, x);
            }else{
                scanf("%d%d", &l, &r);
                printf("%lld\n", getSum(l, r, 1));
            }
        }
    }
    return 0;
}

