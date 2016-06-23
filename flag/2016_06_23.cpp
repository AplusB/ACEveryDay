#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 50005;

struct Point{
    int x, y;
    void read(){
        scanf("%d%d", &x, &y);
    }
    Point(){}
    Point(int _x, int _y): x(_x), y(_y) {}

    Point operator-(const Point& tmp) const{
        return Point(x - tmp.x, y - tmp.y);
    }

    int operator*(const Point& tmp) const{
        return x * tmp.y - y * tmp.x;
    }

}p[maxn], S[maxn];
int top;

int dis2(const Point& p1, const Point& p2){
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

bool cmp(const Point& a, const Point& b){
    int tmp = (a - p[0]) * (b - p[0]);
    if(!tmp) return dis2(p[0], a) < dis2(p[0], b);
    return tmp > 0;
}

void Graham(Point p[], int n){
    top = -1;
    S[++top] = p[0];
    S[++top] = p[1];
    for(int i = 2; i < n; i++){
        while(top > 0 && (p[i] - S[top - 1]) * (S[top] - S[top - 1]) > 0) top--;
        S[++top] = p[i];
    }
}

double rotating_calipers(Point p[], int n){
    int ans = 0, j = 1, k = 1;
    Point v;
    for(int i = 0; i < n; i++){
        v = p[i] - p[j];
        while((v * (p[(k + 1) % n] - p[k])) < 0)
            k = (k + 1) % n;
        v = p[k] - p[i];
        while((v * (p[(j + 1) % n] - p[j])) < 0)
            j = (j + 1) % n;
        v = p[i] - p[j];
        while((v * (p[(k + 1) % n] - p[k])) < 0)
            k = (k + 1) % n;
        ans = max(ans, abs((p[k] - p[i]) * (p[j] - p[i])));
    }
    return 1.0 * ans / 2.0;
}

int main(){
    int n, id;
    while(scanf("%d", &n) && n != -1){
        id = 0;
        for(int i = 0; i < n; i++){
            p[i].read();
            if(i)
            if(p[i].y < p[id].y || p[i].y == p[id].y && p[i].x < p[id].x)
                id = i;
        }
        swap(p[0], p[id]);
        sort(p + 1, p + n, cmp);
        Graham(p, n);
        printf("%.2f\n", rotating_calipers(S, top + 1));
    }
    return 0;
}
/*
6
4 -5
6 -2
5 2
-4 5
-6 2
-5 -2
*/
