#include<bits/stdc++.h>
using namespace std;

struct Point{
    double x,y;
    void input(){
        cin>>x>>y;
    }
};

const int maxn = 512345;
const double eps = 1e-8;
Point arr[maxn];

double dis(Point a,Point b){
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

double xmult(Point p1,Point p2,Point p){
    return (p1.x - p.x) *  (p2.y - p.y) - (p2.x - p.x) * (p1.y - p.y);
}
double dis(Point p,Point la,Point lb){
    Point t = p;
    t.x += la.y - lb.y ;
    t.y += lb.x - la.x ;
    if(xmult(la,t,p) * xmult(lb,t,p) > eps){
        return min(dis(p,la),dis(p,lb));
    }
    return fabs(xmult(p,la,lb) / dis(la,lb));
}
const double Pi = acos(-1.0);

int main(){
    int n;
    cin>>n;
    Point cet;
    cet.input();
    for(int i = 0 ; i < n ; i ++) arr[i].input();
    double ma,mi;
    ma = mi = dis(cet,arr[0]);
    for(int i = 1; i < n ; i ++){
        ma = max(ma,dis(cet,arr[i]));
        mi = min(mi,dis(cet,arr[i]));
    }
    for(int i = 0; i < n ; i ++){
        ma = max(ma,dis(cet,arr[(i+1)%n],arr[i]));
        mi = min(mi,dis(cet,arr[(i+1)%n],arr[i]));
    }
    double ans = Pi * (ma * ma - mi * mi);
    printf("%.10f\n",ans);
    return 0;
}
