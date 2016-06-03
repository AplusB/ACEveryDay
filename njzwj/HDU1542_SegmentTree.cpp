#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define lch p<<1
#define rch p<<1|1
using namespace std;
const double eps=1e-8;
const int maxn=205;
inline int sgn(double x) { return (x>-eps)-(x<eps); }
int cnt[maxn<<2], n, m, sz;
double sum[maxn<<2], pos[maxn];
map<double, int> mp;
struct EG {
    double a, b, x;
    int type;
    EG() {}
    EG(double a, double b, double x, int type):a(a), b(b), x(x), type(type) {}
    bool operator<(const EG& rhs) const {
        return (!sgn(x-rhs.x))?type>rhs.type:x<rhs.x;
    }
}in[maxn];

void pushup(int p, int l, int r) {
    if (cnt[p]) {
        sum[p]=pos[r+1]-pos[l];
    }else if (l==r) sum[p]=0.0;
    else sum[p]=sum[lch]+sum[rch];
}

void update(int p, int l, int r, int x, int y, int c) {
    if (x<=l&&r<=y) {
        cnt[p]+=c;
        pushup(p, l, r);
        return;
    }
    int mid=(l+r)>>1;
    if (x<=mid) update(lch, l, mid, x, y, c);
    if (mid<y) update(rch, mid+1, r, x, y, c);
    pushup(p, l, r);
}

int main() {
    int icase=1;
    while (scanf("%d", &n)&&n) {
        m=0;
        for (int i=0;i<n;++i) {
            double a, b, c, d;
            scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
            in[m]=EG(b, d, a, 1);
            pos[m++]=b;
            in[m]=EG(b, d, c, -1);
            pos[m++]=d;
        }
        sort(pos, pos+m);
        sort(in, in+m);
        sz=unique(pos, pos+m)-pos;
        mp.clear();
        for (int i=0;i<sz;++i) mp[pos[i]]=i;

        double ans=0.0;
        memset(cnt, 0, sizeof(cnt));
        for (int i=0;i<m;++i) {
            update(1, 0, sz-1, mp[in[i].a], mp[in[i].b]-1, in[i].type);
            if (i<m-1) ans+=sum[1]*(in[i+1].x-in[i].x);
        }
        printf("Test case #%d\nTotal explored area: %.2f\n\n", icase++, ans);
    }
    return 0;
}