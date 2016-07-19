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
const ll mod = 998244353;
const double eps = 1e-6;

ll b[100010],c[100010];

ll mul(ll a,ll b)
{
    if (a >= mod)
        a -= mod;
    if (b >= mod)
        b -= mod;
    ll ans = 0;
    while (b)
    {
        if (b & 1)
            ans += a;
        a += a;
        b >>= 1;
        if (ans >= mod)
            ans -= mod;
    }
    return ans;
}

int main()
{
    int t;
    scanf("%d",&t);
    while (t --)
    {
        int n;
        scanf("%d",&n);
        for (int i = 1;i <= n ;++ i)
            scanf("%lld",&b[i]);
        for (int i = 1;i <= n;++ i)
            scanf("%lld",&c[i]);
        bool flag = 1;
        if (b[1] != c[1])
            flag = 0;
        ll ans = 1;
        for (int i = 2;i <= n && flag; ++ i)
        {
            if (b[i] > c[i] || b[i] > b[i - 1] || c[i] < c[i - 1])
            {
                flag = 0;
                break;
            }
            if (b[i] < b[i - 1] && c[i] > c[i - 1])
            {
                flag = 0;
                break;
            }
            if (b[i] == b[i - 1] && c[i] == c[i - 1])
            {
                if (c[i] - b[i] + 2 - i <= 0)
                {
                    flag = 0;
                    break;
                }
                ans = (ans * (c[i] - b[i] + 2 - i)) % mod;
            }
        }
        printf("%lld\n",flag ? ans : 0);
    }
    return 0;
}
