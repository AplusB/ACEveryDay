#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const double INF = 1e10;
const double eps = 1e-9;
const int maxn = 1e5 + 5;

int sgn(double x){
    if(fabs(x) < eps) return 0;
    return x > 0.0 ? 1 : -1;
}

struct Point{
    double x, y;

    bool operator<(const Point& tmp) const{
        return sgn(x - tmp.x) < 0 || !sgn(x - tmp.x) && sgn(y - tmp.y) < 0;
    }

}p[maxn], tp[maxn];

struct Day{
    double a, b, r, k;
    int id;
    bool operator<(const Day& tmp) const{
        return sgn(k - tmp.k) < 0;
    }
}d[maxn], td[maxn];
double dp[maxn];
int q[maxn], head, tail;

double getSlope(int i, int j){
    if(!sgn(p[i].x - p[j].x)) return -INF;
    return (p[i].y - p[j].y) / (p[i].x - p[j].x);
}

void solve(int l, int r){
    if(l == r){
        dp[l] = max(dp[l], dp[l - 1]);
        p[l].y = dp[l] / (d[l].a * d[l].r + d[l].b);
        p[l].x = p[l].y * d[l].r;
        return;
    }
    int mid = (l + r) >> 1, t1 = l - 1, t2 = mid;
    for(int i = l; i <= r; i++){
        if(d[i].id <= mid) td[++t1] = d[i];
        else td[++t2] = d[i];
    }
    for(int i = l; i <= r; i++) d[i] = td[i];
    solve(l, mid);
    head = tail = 0;
    for(int i = l; i <= mid; i++){
        while(tail - head > 1 && sgn(getSlope(i, q[tail - 1]) - getSlope(q[tail - 1], q[tail - 2])) > 0)
            tail--;
        q[tail++] = i;
    }
    for(int i = r; i > mid; i--){
        while(tail - head > 1 && sgn(-d[i].a / d[i].b - getSlope(q[head], q[head + 1])) < 0)
            head++;
        dp[d[i].id] = max(dp[d[i].id], d[i].a * p[q[head]].x + d[i].b * p[q[head]].y);
    }
    solve(mid + 1, r);
    t1 = l, t2 = mid + 1;
    for(int i = l; i <= r; i++){
        if(t1 <= mid && (t2 > r || p[t1] < p[t2])) tp[i] = p[t1++];
        else tp[i] = p[t2++];
    }
    for(int i = l; i <= r; i++) p[i] = tp[i];
}

int main(){
    int n;
    scanf("%d%lf", &n, &dp[0]);
    for(int i = 1; i <= n; i++){
        scanf("%lf%lf%lf", &d[i].a, &d[i].b, &d[i].r);
        d[i].k = -d[i].a / d[i].b;
        d[i].id = i;
    }
    sort(d + 1, d + 1 + n);
    solve(1, n);
    printf("%.3lf\n", dp[n]);
    return 0;
}
