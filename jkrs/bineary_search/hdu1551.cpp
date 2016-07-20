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

int n,k;

ll a[10010];

bool judge(ll x)
{
    int num = 0;
    for (int i = 0;i < n ;++ i)
    {
        num += a[i] / x;
    }
    return num >= k;
}

int main()
{
    while (~scanf("%d%d",&n,&k))
    {
        ll maxn = 0;
        for (int i = 0;i < n; ++ i)
        {
            double x;
            scanf("%lf",&x);
            a[i] = x * 100;
            maxn = max(maxn,a[i]);
        }
        ll l = 1,r = maxn;
        ll ans = 0;
        while (r >= l)
        {
            ll mid = l + r >> 1;
            if (judge(mid))
            {
                l = mid + 1;
                ans = mid;
            }

            else
                r = mid - 1;
        }
        printf("%.2f\n",ans * 1.0 / 100);
    }
    return 0;
}
