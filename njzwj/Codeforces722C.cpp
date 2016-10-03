#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;
int n, a[N], seq[N];
struct Seg {
    int l, r;
    ll sum;
    Seg() {}
    Seg(int _l, int _r, ll _sum): l(_l), r(_r), sum(_sum) {}
    bool operator<(const Seg &rhs) const {
        return l<rhs.l;
    }
};
int le[N], ri[N], tot, stk[N], tot2;
Seg segs[N];
set<ll> sums;
ll ans[N];

void ins(int x) {
    int tar;
    Seg ns;
    ns=Seg(x, x, a[x]);
    if (ri[x-1]>=0) {
        tar=ri[x-1];
        ns.l=segs[tar].l;
        ns.sum+=segs[tar].sum;
        sums.erase(segs[tar].sum);
        stk[tot2++]=tar;
    }
    if (le[x+1]>=0) {
        tar=le[x+1];
        ns.r=segs[tar].r;
        ns.sum+=segs[tar].sum;
        sums.erase(segs[tar].sum);
        stk[tot2++]=tar;
    }
    sums.insert(ns.sum);
    if (tot2) {
        tar=stk[--tot2];
    }else tar=tot++;
    segs[tar]=ns;
    le[ns.l]=tar;
    ri[ns.r]=tar;
}

int main() {
    tot2=tot=0;
    memset(le, 0xff, sizeof le);
    memset(ri, 0xff, sizeof ri);
    scanf("%d", &n);
    for (int i=1;i<=n;++i) scanf("%d", a+i);
    for (int i=0;i<n;++i) scanf("%d", seq+i);

    ans[n-1]=0;
    for (int i=n-1;i>0;--i) {
        // INSERT
        ins(seq[i]);
        // CALCULATE
        set<ll>::iterator it;
        it=sums.end();
        --it;
        ans[i-1]=*it;
    }
    for (int i=0;i<n;++i) printf("%I64d\n", ans[i]);
    return 0;
}
