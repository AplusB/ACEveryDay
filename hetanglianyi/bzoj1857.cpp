#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;
template <typename _Tp>
class Point  //学习自王哥高二的代码……
{
    private:
        _Tp _x, _y;
    public:
        Point() {_x = _y = 0; }
        Point(_Tp x, _Tp y)
        {
            _x = x;
            _y = y;
        }
        _Tp x();
        _Tp y();
        Point &operator=(Point p)
        {
            _x = p.x();
            _y = p.y();
            return *this;
        }
        Point operator+(Point b) const
        {
            Point c(_x + b.x(), _y + b.y());
            return c;
        }
        Point operator-(Point b) const
        {
            Point c(_x - b.x(), _y - b.y());
            return c;
        }
        Point operator*(_Tp p)
        {
            Point c(_x * p, _y * p);
            return c;
        }
        Point operator/(_Tp p)
        {
            Point c(_x / p, _y / p);
            return c;
        }
        Point &operator+=(Point b)
        {
            _x += b.x();
            _y += b.y();
            return *this;
        }
        Point &operator-=(Point b)
        {
            _x -= b.x();
            _y -= b.y();
            return *this;
        }
        Point &operator*=(_Tp p)
        {
            _x *= p;
            _y *= p;
            return *this;
        }
        Point &operator/=(_Tp p)
        {
            _x /= p;
            _y /= p;
            return *this;
        }
};
const double zero = 1e-12;
int xa, xb, xc, xd, ya, yb, yc, yd;
Point <double> A, B, C, D;
double p,q,r;

template <typename _Tp>
_Tp Point <_Tp> ::x()
{
    return _x;
}

template <typename _Tp>
_Tp Point <_Tp> ::y()
{
    return _y;
}

inline double dist(Point <double> a, Point <double> b)
{
    Point <double> tmp = b - a;
    return sqrt((tmp.x()*tmp.x()) + (tmp.y() * tmp.y()));
}

double dist3(Point <double> E, Point <double> F)
{
    return dist(A, E) / p + dist(E, F) / r + dist(F, D) / q;
}

double calc_F(Point <double> E)
{
    Point <double> l = C, r = D, mid, midmid;
    double ans = 1e190;

    while (dist(l, r) > zero)
    {
       // cout << dist(l, r) << endl;
        mid = (l+r)/2;
        midmid = (mid+r)/2;
        double tp = dist3(E, mid);
        double tq = dist3(E, midmid);
        //cout <<' '<< tp <<' '<<tq <<endl;
        //cout << l.x()<<' ' <<l.y()<<' '<<mid.x() <<' '<< mid.y() <<' '<<r.x()<<' '<<r.y()<<endl;
        if (tp > tq) l = mid;
        else r = midmid;
        if (tp < ans) ans = tp;
        if (tq < ans) ans = tq;
    }
    if (dist(C, D) < zero) ans = dist3(E, C);
    return ans;
}

double calc_E()
{
    Point <double> l = A, r = B, mid, midmid;
    double ans = 1e190;
      //cout << dist (l, r)<< endl;
    while (dist(l, r) > zero)
    {
        mid = (l+r)/2;
        midmid = (mid+r)/2;
        double tp = calc_F(mid);
        double tq = calc_F(midmid);
        //cout << tp <<' '<<tq <<endl;
        if (tp > tq) l = mid;
        else r = midmid;
        if (tp < ans) ans = tp;
        if (tq < ans) ans = tq;
    }
    if (dist(A, B) < zero) ans = calc_F(A);
    return ans;
}

int main()
{
    scanf("%d%d%d%d%d%d%d%d",&xa, &ya, &xb, &yb, &xc, &yc, &xd, &yd);
    scanf("%lf%lf%lf", &p, &q, &r);
    A = Point <double> (xa, ya);
    B = Point <double> (xb, yb);
    C = Point <double> (xc, yc);
    D = Point <double> (xd, yd);
    printf("%.2lf\n", calc_E());
	return 0;
}
