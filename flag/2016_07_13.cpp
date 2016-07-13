#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define lson rt << 1
#define rson rt << 1 | 1
const LL INF = 1e16;
const int maxn = 50005;
LL sum[maxn], pre[maxn];
int a[maxn], Left[maxn], Right[maxn], sz;
vector < int > neg;

struct SegTreeNode{
    int l, r;
    pair < LL, int > Min;
};

class SegTree{
private:
    SegTreeNode tree[maxn << 2];

    void push_up(int rt){
        tree[rt].Min = min(tree[lson].Min, tree[rson].Min);
    }

public:
    void build(int l, int r, int rt){
        tree[rt].l = l;
        tree[rt].r = r;
        tree[rt].Min = make_pair(INF, r);
        if(l == r) return;
        int mid = (l + r) >> 1;
        build(l, mid, lson);
        build(mid + 1, r, rson);
    }

    void update(int p, int rt, LL val){
        if(p == tree[rt].l && tree[rt].r == p){
            tree[rt].Min.first = val;
            return;
        }
        int mid = (tree[rt].l + tree[rt].r) >> 1;
        if(p <= mid)
            update(p, lson, val);
        else
            update(p, rson, val);
        push_up(rt);
    }

    pair < LL, int > query(int l, int r, int rt){
        if(l <= tree[rt].l && tree[rt].r <= r){
            return tree[rt].Min;
        }
        int mid = (tree[rt].l + tree[rt].r) >> 1;
        pair < LL, int > res(INF, 0);
        if(l <= mid)
            res = min(res, query(l, r, lson));
        if(mid < r)
            res = min(res, query(l, r, rson));
        return res;
    }

}gao1, gao2;

void __main(){
    int n, m, cnt = 0;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    a[n + 1] = -INF;
    LL s1 = 0, s2 = 0;
    int flag = 1;
    sz = 0;
    for(int i = 1; i <= n + 1; i++){
        if(a[i] >= 0){
            s1 += a[i];
            flag = 0;
            cnt++;
        }
        if(a[i] < 0){
            if(!flag){
                sum[++sz] = s1;
                pre[sz] = s2;
                s1 = s2 = 0;
                flag = 1;
            }
            s2 += a[i];
            neg.push_back(a[i]);
        }
    }
    LL ans = 0;
    for(int i = 1; i <= sz; i++){
        ans += sum[i];
    }
    if(m >= n || cnt >= m && sz <= m){
        printf("%lld\n", ans);
        return;
    }
    if(cnt < m){
        sort(neg.begin(), neg.end());
        for(int i = neg.size() - 1; i >= 0 && cnt < m; i--, cnt++){
            ans += neg[i];
        }
        printf("%lld\n", ans);
        return;
    }
    gao1.build(1, sz, 1);
    gao2.build(1, sz, 1);
    pre[1] = -INF;
    for(int i = 1; i <= sz; i++){
        gao1.update(i, 1, -pre[i]);
        gao2.update(i, 1, sum[i]);
        Left[i] = i - 1;
        Right[i] = i + 1;
    }
    int tmp = sz;
    while(tmp > m){
        pair < LL, int > u = gao1.query(1, sz, 1);
        pair < LL, int > d = gao2.query(1, sz, 1);
        if(u.first <= d.first){
            ans -= u.first;
            gao1.update(u.second, 1, INF);
            gao2.update(u.second, 1, INF);
            if(Left[u.second]){
                sum[Left[u.second]] += sum[u.second] + pre[u.second];
                gao2.update(Left[u.second], 1, sum[Left[u.second]]);
            }
            Left[Right[u.second]] = Left[u.second];
            Right[Left[u.second]] = Right[u.second];
        }else{
            ans -= d.first;
            gao1.update(d.second, 1, INF);
            if(Right[d.second] <= sz){
                pre[Right[d.second]] += sum[d.second] + pre[d.second];
                gao1.update(Right[d.second], 1, -pre[Right[d.second]]);
            }
            gao2.update(d.second, 1, INF);
            Left[Right[d.second]] = Left[d.second];
            Right[Left[d.second]] = Right[d.second];
        }
        tmp--;
    }
    printf("%lld\n", ans);
}

int main(){
    __main();
    return 0;
}
/*
7 9
2
11
-4
13
5
-6
-2
*/


