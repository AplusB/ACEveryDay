#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
struct Point
{
        double x,y;
        void in() {
                scanf("%lf%lf", &x, &y);
        }
        
}p;
double Distance(Point a, Point b)
{
        return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int main() {
        Point a, b, c;
        a.in(); b.in(); c.in();
        int n;
        cin >> n;
        double ret = 0;
        double mi = 1e18;
        double mia = mi, mib = mi;
        for(int i = 0; i < n; i++) {
                p.in();
                double disBin = Distance(p, c);
                ret += 2 * disBin;

                double dista = Distance(p, a) - disBin;
                double distb = Distance(p, b) - disBin;

                if(i)
                        mi = min(mi, min(distb + mia, dista + mib));
                mia = min(mia, dista);
                mib = min(mib, distb);
        }
        mi = min(mi, min(mia, mib));
        printf("%.9f\n", ret + mi);
        return 0;
}
