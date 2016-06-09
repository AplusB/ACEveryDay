#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const double eps = 1e-9;
const int INF = 0x3f3f3f3f;
const int maxn = 205;
vector < pair < double, double> > a;
vector < double > p;
#define lson rt << 1
#define rson rt << 1 | 1
struct SegTree{
    int l, r;
    double mi;
    int mid() { return (l + r) >> 1; }
}tree[maxn << 2];

void push_up(int rt){
    tree[rt].mi = min(tree[lson].mi, tree[rson].mi);
}

void build(int l, int r, int rt){
    tree[rt].l = l;
    tree[rt].r = r;
    tree[rt].mi = 0;
    if(l == r){
        tree[rt].mi = a[l - 1].second;
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, lson);
    build(mid + 1, r, rson);
    push_up(rt);
}

double query(int l, int r, int rt){
    if(l <= tree[rt].l && tree[rt].r <= r){
        return tree[rt].mi;
    }
    int mid = tree[rt].mid();
    double mi = 1.0 * INF;
    if(l <= mid) mi = min(mi, query(l, r, lson));
    if(mid < r) mi = min(mi, query(l, r, rson));
    return mi;
}

int sgn(double x){
    if(fabs(x) < eps) return 0;
    return x > 0.0 ? 1 : -1;
}

double dis[maxn], pri[maxn];

int main(){
    int T, m;
    double d, d2, n, x, pp;
    scanf("%d", &T);
    while(T--){
        scanf("%lf%lf%lf%d", &d, &n, &d2, &m);
        for(int i = 1; i <= m; i++){
            scanf("%lf", &dis[i]);
        }
        for(int i = 1; i <= m; i++){
            scanf("%lf", &pri[i]);
        }
        a.clear();
        p.clear();
        for(int i = 1; i <= m; i++){
            a.push_back(make_pair(dis[i], pri[i]));
            p.push_back(dis[i]);
        }
        a.push_back(make_pair(d, 0));
        p.push_back(d);
        sort(a.begin(), a.end());
        sort(p.begin(), p.end());
        build(1, a.size(), 1);
        double now = 0, j, c;
        double cost = 0;
        int flag = 0;
        for(int i = 0; i < a.size() - 1; i++){ //first: dis; second: price
            int pos = upper_bound(p.begin(), p.end(), a[i].first + n * d2) - p.begin();
            if(pos - (i + 1) <= 0){
                cost = -1.0;
                flag = 1;
                break;
            }
            double mi = query(i + 2, pos, 1);
            if(mi >= a[i].second){ //find not the cheeper price one
                cost += (n - now) * a[i].second;
                now = n - (a[i + 1].first - a[i].first) / d2;
            }else{
                j = i + 1;
                while(a[j].second >= a[i].second) j++;
                c = (a[j].first - a[i].first) / d2;
                if(sgn(c - now) <= 0) now -= c;
                else{
                    cost += (c - now) * a[i].second;
                    now = 0;
                }
                i = j - 1;
            }
        }
        if(flag) puts("No Solution");
        else printf("%.1lf\n", cost);
    }
    return 0;
}
