#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
#include <cctype>
#include <map>
#include <queue>
#include <cmath>
#include <set>
#include <stack>
#include <functional>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <iomanip>
#define pu system("pause")
#define ff first
#define ss second
#define clr(x) memset(x,0,sizeof (x))
#define clrs(x) memset(x,-1,sizeof (x))
#define pt(x,y) (x).push_back(y)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const double pi = acos(-1.0);
const int inf = 0x7fffffff;
const int mod = 1e8;
const double eps = 1e-8;

struct node
{
    double x,y;
}a[35];

double ans;

int n;

double judge(double mid)
{
    double x = -inf,y = -inf,xx = inf,yy = inf;
    for (int i = 0;i < n ;++ i)
    {
        x = max(x,a[i].x * cos(mid) - a[i].y * sin(mid));
        y = max(y,a[i].x * sin(mid) + a[i].y * cos(mid));
        xx = min(xx,a[i].x * cos(mid) - a[i].y * sin(mid));
        yy = min(yy,a[i].x * sin(mid) + a[i].y * cos(mid));
    }
    return max(x - xx,y - yy);
}

int main()
{
    int t;
    scanf("%d",&t);
    while (t --)
    {
        scanf("%d",&n);
        for (int i = 0;i < n ;++ i)
            scanf("%lf%lf",&a[i].x,&a[i].y);
        double l = 0,r = pi / 2;
        ans = inf;
        while (r - l > eps)
        {
            double mid = (l + r) / 2;
            double midmid = (mid + r) / 2;
//            printf("mid = %lf midmid = %lf\n",mid,midmid);
            double f1 = judge(mid);
            double f2 = judge(midmid);
            if (f1 > f2)
                l = mid;
            else
                r = midmid;
//            printf("f1 = %lf f2 = %lf\n",f1,f2);
            ans = min(f1,f2);
        }
        printf("%.2f\n",ans * ans);
    }
    return 0;
}
