#include <bits/stdc++.h>
using namespace std;
#define lson rt << 1
#define rson rt << 1 | 1
#define pub push_back
#define mkp make_pair
typedef long long LL;
const int maxn = 100005;
vector < pair < int, int > > p;
priority_queue < pair < int, int > > que;
int a[maxn], b[maxn], c[maxn];

struct SegTree{
    int l, r, cnt;
    LL sum;
}tree[maxn << 2];

void push_up(int rt){
    tree[rt].cnt = tree[lson].cnt + tree[rson].cnt;
    tree[rt].sum = tree[lson].sum + tree[rson].sum;
}

void build(int l, int r, int rt){
    tree[rt].l = l;
    tree[rt].r = r;
    tree[rt].sum = tree[rt].cnt = 0;
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(l, mid, lson);
    build(mid + 1, r, rson);
    push_up(rt);
}

void update(int pos, int rt){
    if(pos == tree[rt].l && tree[rt].r == pos){
        tree[rt].cnt = 1;
        tree[rt].sum = p[pos].first;
        return;
    }
    int mid = (tree[rt].l + tree[rt].r) >> 1;
    if(pos <= mid)
        update(pos, lson);
    else
        update(pos, rson);
    push_up(rt);
}

int query(int rt, int k){
    if(tree[rt].l == tree[rt].r){
        if(!tree[rt].cnt) return 0;
        return tree[rt].cnt - (tree[rt].sum <= k ? 0 : 1);
    }
    int mid = (tree[rt].l + tree[rt].r) >> 1;
    if(tree[lson].sum >= k)
        return query(lson, k);
    else
        return tree[lson].cnt + query(rson, k - tree[lson].sum);
}

void read(int &x){
    char ch;
    while((ch = getchar()) < '0' || ch > '9');
    x = ch - '0';
    while((ch = getchar()) >= '0' && ch <= '9') x = x * 10 + ch - '0';
}

int main(){
    int n, T, k, t, ans = 0;
    LL sum = 0, SUM = 0, tmp;
    read(n); read(T); read(k);
    for(int i = 1; i <= n; i++){
        read(a[i]);
    }
    for(int i = 1; i <= n; i++){
        read(b[i]);
        p.pub(mkp(b[i], i));
    }
    for(int i = 1; i <= n; i++){
        read(c[i]);
    }
    p.pub(mkp(-1, -1));
    sort(p.begin(), p.end());
    build(1, (int)p.size(), 1);
    for(int i = 1; i <= n && a[i] < T; i++){
        if(c[i]){
            que.push(mkp(b[i], i));
            sum += b[i];
            if(que.size() > k){
                sum -= que.top().first;
                t = lower_bound(p.begin(), p.end(), que.top()) - p.begin();
                update(t, 1);
                que.pop();
            }
        }else{
            t = lower_bound(p.begin(), p.end(), mkp(b[i], i)) - p.begin();
            update(t, 1);
        }
        tmp = T - a[i];
        if(sum <= tmp && que.size() == k){
            tmp -= sum;
            ans = max(ans, query(1, tmp) + k);
        }
    }
    if(!ans) ans = -1;
    printf("%d\n", ans);
    return 0;
}

