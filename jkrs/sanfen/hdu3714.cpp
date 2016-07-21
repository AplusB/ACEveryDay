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
#define pt(y) push_back(y)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const double pi = acos(-1.0);
const ll inf = 0x7fffffff;
const ll mod = 1e9 + 7;
const double eps = 1e-8;

struct node
{
    double a,b,c;
}a[10010];

int n;

double f(node a,double x)
{
    return a.a * x * x + a.b * x + a.c;
}

double judge(double x)
{
    double maxn = -inf;
    for (int i = 0;i < n ;++ i)
    {
        double temp = f(a[i],x);
//        printf("a[%d].a = %d b = %d c = %d x = %lf",i,a[i].a,a[i].b,a[i].c,x);
//        printf("temp = %lf\n",temp);
        maxn = max(maxn,temp);
    }
    return maxn;
}

int main()
{
    int t;
    scanf("%d",&t);
    while (t --)
    {
        scanf("%d",&n);
        for (int i = 0;i < n; ++ i)
            scanf("%lf%lf%lf",&a[i].a,&a[i].b,&a[i].c);
        double l = 0,r = 1000;
        double ans = 0;
        while(r - l > eps)
        {
            double mid = (l + r) / 2;
            double midmid = (mid + r) / 2;
            double ans1 = judge(mid);
            double ans2 = judge(midmid);
            if (ans1 > ans2)
                l = mid;
            else
                r = midmid;
            ans = min(ans1,ans2);
        }
        printf("%.4f\n",ans);
    }
    return 0;
}
