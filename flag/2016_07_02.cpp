#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int maxn = 505;
struct Point{
    double x, y;
    void read(){
        scanf("%lf%lf", &x, &y);
    }
    Point(){}
    Point(double _x, double _y): x(_x), y(_y) {}

    Point operator+(const Point& tmp) const{
        return Point(x + tmp.x, y + tmp.y);
    }

    Point operator-(const Point& tmp) const{
        return Point(x - tmp.x, y - tmp.y);
    }

    Point operator*(const double t) const{
        return Point(x * t, y * t);
    }

    double dot(const Point& tmp) const{
        return x * tmp.x + y * tmp.y;
    }

    double det(const Point& tmp) const{
        return x * tmp.y - y * tmp.x;
    }

    Point unit_vector(){
        int len = sqrt(x * x + y * y);
        return Point(x / len, y / len);
    }

}p[maxn];

int sgn(double x){
    if(fabs(x) < eps) return 0;
    return x > 0.0 ? 1 : -1;
}

int LineCrossCircle(Point o, double r, Point A, Point B, Point& p1, Point& p2){ //P = A + t(B - A);
    double a = (B - A).dot(B - A);
    double b = (B - A).dot(A - o) * 2.0;
    double c = (A - o).dot(A - o) - r * r;
    double delta = b * b - 4.0 * a * c;
    double t1, t2;
    if(delta < 0) return 0;
    if(delta == 0){
        t1 = (-b - sqrt(delta)) / (2.0 * a);
        p1 = p2 = A +  (B - A) * t1;
        return 1;
    }
    t1 = (-b - sqrt(delta)) / (2.0 * a);
    t2 = (-b + sqrt(delta)) / (2.0 * a);
    p1 = A + (B - A) * t1;
    p2 = A + (B - A) * t2;
    return 2;
}

double dist2(const Point& p1, const Point& p2){
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

bool OnSeg(Point p0, Point A, Point B){
    return sgn((A - p0).det(B - p0)) == 0 && sgn((A - p0).dot(B - p0)) < 0;
}

double SectorArea(Point o, double r, Point A, Point B){
    double a = dist2(o, A), b = dist2(o, B), c = dist2(A, B);
    return acos((a + b - c) /  (2.0 * sqrt(a) * sqrt(b))) * r * r * 0.5;
}

double TriangleArea(Point A, Point B, Point C){
    return fabs((B - A).det(C - A) * 0.5);
}

double Area(Point A, Point B, Point o, double r){
    int t1 = sgn(dist2(A, o) - r * r), t2 = sgn(dist2(B, o) - r * r);
    Point p1, p2;
    if(t1 <= 0 && t2 <= 0){
        return TriangleArea(o, A, B);
    }
    if(t1 * t2 <= 0){
        LineCrossCircle(o, r, A, B, p1, p2);
        if(!OnSeg(p1, A, B)) swap(p1, p2);
        if(t1 < 0) swap(A, B);
        return TriangleArea(o, p1, B) + SectorArea(o, r, A, p1);
    }
    if(LineCrossCircle(o, r, A, B, p1, p2) != 2)
        return SectorArea(o, r, A, B);
    Point D = ((A - o).unit_vector() * r) + o;
    Point E = ((B - o).unit_vector() * r) + o;
    return SectorArea(o, r, D, E) - SectorArea(o, r, p1, p2) + TriangleArea(o, p1, p2);
}

double Area(Point p[], int n, Point o, double r){
    p[n] = p[0];
    double ans = 0;
    for(int i = 0; i < n; i++){
        ans += Area(p[i], p[i + 1], o, r) * sgn((p[i] - o).det(p[i + 1] - o));
    }
    return fabs(ans);
}

int main(){
    int n, cas = 0;
    double k, D, E, F, r;
    Point o, A, B;
    while(scanf("%d%lf", &n, &k) != EOF){
        for(int i = 0; i < n; i++) p[i].read();
        A.read(); B.read();
        D = (-2.0 * k * k * A.x + 2.0 * B.x) / (k * k - 1.0);
        E = (-2.0 * k * k * A.y + 2.0 * B.y) / (k * k - 1.0);
        F = (A.x * A.x * k * k - B.x * B.x + A.y * A.y * k * k - B.y * B.y) / (k * k - 1.0);
        o = Point(-D / 2.0, -E / 2.0);
        r = sqrt((D * D + E * E - 4 * F) / 4.0);
        printf("Case %d: %.10lf\n", ++cas, Area(p, n, o, r));
    }
    return 0;
}

/*
4 0.5000
-1 -1
1 -1
1 1
-1 1
0 0
-1 0

4 0.5000
-1 -1
1 -1
1 1
-1 1
0 0
1 1


*/
