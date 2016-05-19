#include <bits/stdc++.h>
using namespace std;
const int maxn = 4005;
typedef long long LL;

struct Point{
    LL x, y, len;
    Point(){}
    Point(LL _x, LL _y): x(_x), y(_y) {}
    Point(LL _x, LL _y, LL _len): x(_x), y(_y), len(_len) {}
    Point operator-(const Point& tmp) const{
        return Point(x - tmp.x, y - tmp.y);
    }
    LL operator*(const Point& tmp) const{
        return x * tmp.y - y * tmp.x;
    }
}p[maxn], p0;

struct Point2{
    int x0, x1, y;
    void read(){
        scanf("%d%d%d", &x0, &x1, &y);
        if(x0 > x1) swap(x0, x1);
    }
}a[maxn];

LL dis2(const Point& p1, const Point& p2){
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

bool cmp(const Point& p1, const Point& p2){
    LL tmp = (p1 - p0) * (p2 - p0);
    if(!tmp){
        if(p1.len * p2.len < 0)
            return p1.len > p2.len;
        return dis2(p1, p0) < dis2(p2, p0);
    }
    return tmp > 0;
}

LL solve(Point p[], int n){
    sort(p, p + n, cmp);
    LL ans = p0.len, sum = p0.len;
    for(int i = 0; i < n; i++){
        sum += p[i].len;
        ans = max(ans, sum);
    }
    return ans;
}

int main(){
    int n, x0, x1, y;
    while(scanf("%d", &n) != EOF){
        for(int i = 1; i <= n; i++){
            a[i].read();
        }
        LL ans = 0;
        for(int i = 1; i <= n; i++){
            for(int t = 0; t < 2; t++){
                int tol = 0;
                for(int j = 1; j <= n; j++) if(i != j){
                    if(a[j].y == a[i].y) continue;
                    if(a[j].y > a[i].y){
                        p[tol++] = Point(a[j].x0, a[j].y, a[j].x0 - a[j].x1);
                        p[tol++] = Point(a[j].x1, a[j].y, a[j].x1 - a[j].x0);
                    }else{
                        x0 = 2 * a[i].x0 - a[j].x0;
                        x1 = 2 * a[i].x0 - a[j].x1;
                        y = 2 * a[i].y - a[j].y;
                        if(x0 > x1) swap(x0, x1);
                        p[tol++] = Point(x0, y, x0 - x1);
                        p[tol++] = Point(x1, y, x1 - x0);
                    }
                }
                p0 = Point(a[i].x0, a[i].y, abs(a[i].x1 - a[i].x0));
                ans = max(ans, solve(p, tol));
                swap(a[i].x0, a[i].x1);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
/*
5
100 180 20
30 60 30
70 110 40
10 40 50
0 80 70
3
50 60 10
-42 -42 20
25 0 10

5
-5 5 0
1 5 2
-1 -5 -2
-1 -5 2
1 5 -2
*/
