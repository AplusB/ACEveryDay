#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
#define lch p<<1
#define rch p<<1|1
const int maxn=2010;
const double eps=1e-8;
int cnt[maxn<<2];
double len1[maxn<<2], len2[maxn<<2];
map<double, int> mp;
inline int sgn(double x) { return (x>-eps)-(x<eps); }
struct EG {
    int type;
    double t, b;
    double x;
    EG() {}
    EG(double bot, double top, double x, int type):b(bot), t(top), x(x), type(type) {}
    bool operator<(const EG& rhs) const {
        return (!sgn(x-rhs.x))?type>rhs.type:x<rhs.x;
    }
}in[maxn];
double dis[maxn];

void pushup(int p, int l, int r) {
    if (cnt[p]>1) {
        len2[p]=dis[r+1]-dis[l];
        len1[p]=0.0;
    }else if (cnt[p]==1) {
        len1[p]=dis[r+1]-dis[l];
        if (l!=r) {
            len2[p]=len2[lch]+len2[rch]+len1[lch]+len1[rch];
        }else len2[p]=0.0;
        len1[p]-=len2[p];
    }else if (l==r) len1[p]=len2[p]=0;
    else {
        len1[p]=len1[lch]+len1[rch];
        len2[p]=len2[lch]+len2[rch];
    }
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
    int T, n, m;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        m=0;
        for (int i=0;i<n;++i) {
            double a, b, c, d;
            scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
            dis[m]=b;
            in[m++]=EG(b, d, a, 1);
            dis[m]=d;
            in[m++]=EG(b, d, c, -1);
        }
        sort(dis, dis+m);
        sort(in, in+m);
        int sz=unique(dis, dis+m)-dis;
        mp.clear();
        for (int i=0;i<sz;++i) {
            mp[dis[i]]=i;
        }
        double ans=0.0;
        memset(cnt, 0, sizeof(cnt));
        for (int i=0;i<m;++i) {
            update(1, 0, sz-1, mp[in[i].b], mp[in[i].t]-1, in[i].type); 
            if (i<m-1) ans+=(in[i+1].x-in[i].x)*len2[1];
        }
        printf("%.2f\n", ans);
    }
    return 0;
}