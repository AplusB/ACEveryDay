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
const double eps = 1e-6;

int n,m;

double r[10010];

bool judge(double x)
{
    int num = 0;
    for (int i = 0;i < n; ++ i)
    {
        num += (int)(r[i] * r[i] * pi / x);
    }
//    printf("xr = %lf num = %d\n",sqrt(x / pi),num);
    return num >= m + 1;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t --)
    {
        scanf("%d%d",&n,&m);
        double maxn = 0;
        for (int i = 0;i < n ;++ i)
            scanf("%lf",&r[i]),maxn = max(maxn,r[i]);
        double l = 0,r = maxn * maxn * pi;
        while (r - l > eps)
        {
            double mid = (l + r) / 2;
            if (judge(mid))
                l = mid;
            else
                r = mid;
        }
        printf("%.4f\n",l);
    }
    return 0;
}
