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

double x,y,l,d;

double judge(double the)
{
    double s = l * sin(the) + d * cos(the) - x;
    return s / tan(the) + d * sin(the);
}

int main()
{
    while (~scanf("%lf%lf%lf%lf",&x,&y,&l,&d))
    {
        if (d > x)
        {
            puts("no");
            continue;
        }
        double l = 0,r = pi / 2;
        double ans = 0;
        while (r - l > eps)
        {
            double mid = (l + r) / 2;
            double midmid = (mid + r) / 2;
            double ans1 = judge(mid);
            double ans2 = judge(midmid);
            if (ans1 > ans2)
                r = midmid;
            else
                l = mid;
            ans = max(ans1,ans2);
        }
        puts(ans > y ? "no" : "yes");
    }
    return 0;
}
