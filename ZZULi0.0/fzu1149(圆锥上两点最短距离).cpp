#include<iostream>

#include<cstring>

#include<cmath>
#include <cstdio>

using namespace std;
const int N = 3e5 +5;
const double eps = 1e-8;
const double PI = acos(-1.0);

int main(void)
{
    double r,h,da,db,ca,cb;
    while(cin>>r>>h>>da>>ca>>db>>cb)
    {
        if(ca > cb)
        {
            swap(cb,ca);
            swap(db,da);
        }

        double ang = (cb - ca)/180.0*PI;
        double tmp = ang*r;
        double x = sqrt(h*h+r*r);
        double ang2 = tmp/x;
        double ans = sqrt(da*da+db*db - 2.0*da*db*cos(ang2));
        double ang3 = 2.0*PI*r/x - ang2;
        ans = min(ans,sqrt(da*da+db*db - 2.0*da*db*cos(ang3)));
        printf("%.2f\n",ans);
    }
    return 0;
}
