忘记签到，补签一下
#include <bits/stdc++.h>
using namespace std;
#define lson rt << 1
#define rson rt << 1 | 1
typedef long long LL;
const int maxn = 1e5 + 5;
LL dp[maxn];
int a[maxn];

struct SegTree{
    int l, r, id;
}tree[maxn << 2];

void push_up(int rt){
    int x = tree[lson].id;
    int y = tree[rson].id;
    if(a[x] > a[y]){
        tree[rt].id = x;
    }else{
        tree[rt].id = y;
    }
}

void build(int l, int r, int rt){
    tree[rt].l = l;
    tree[rt].r = r;
    if(l == r){
        tree[rt].id = r;
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, lson);
    build(mid + 1, r, rson);
    push_up(rt);
}

int query(int l, int r, int rt){
    if(l <= tree[rt].l && tree[rt].r <= r){
        return tree[rt].id;
    }
    int mid = (tree[rt].l + tree[rt].r) >> 1;
    int id = -1;
    if(l <= mid){
        id = query(l, r, lson);
    }
    if(mid < r){
        int t = query(l, r, rson);
        if(id == -1 || a[id] <= a[t]) id = t;
    }
    return id;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i < n; i++){
        scanf("%d", &a[i]);
    }
    a[n] = 0;
    build(1, n, 1);
    dp[n] = 0;
    LL ans = 0;
    for(int i = n - 1; i >= 1; i--){
        int j = query(i + 1, a[i], 1);
        dp[i] = dp[j] - (a[i] - j) + n - i;
        ans += dp[i];
    }
    cout << ans << '\n';
	return 0;
}
