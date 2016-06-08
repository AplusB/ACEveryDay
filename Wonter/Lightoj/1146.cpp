#include <bits/stdc++.h>
using namespace std;

typedef pair<double,double> Point;
Point a, b, c, d;

inline double Dis(Point pa, Point pb)
{
    return (pa.first - pb.first)*(pa.first - pb.first)
            +(pa.second - pb.second)*(pa.second - pb.second);
}
inline double Cal(double mid)
{
    Point p1, p2;
    p1.first = a.first + (b.first - a.first) * mid;
    p1.second = a.second + (b.second - a.second) * mid;
    p2.first = c.first + (d.first - c.first) * mid;
    p2.second = c.second + (d.second - c.second) * mid;
    double dis = Dis(p1, p2);
    return dis;
}
int main()
{
    int T, _case = 1;
    cin >> T;
    while(T--)
    {
        cin >> a.first >> a.second;
        cin >> b.first >> b.second;
        cin >> c.first >> c.second;
        cin >> d.first >> d.second;
        double left, right;
        left = 0.0, right = 1.0;
        int cnt = 100;
        while(cnt--)
        {
            double mid = (left + right) / 2;
            double mmid = (mid + right) / 2;
            if(Cal(mid) > Cal(mmid))
                left = mid;
            else
                right = mmid;
        }
        printf("Case %d: %f\n", _case++, sqrt(Cal(left)));
    }
    return 0;
}
