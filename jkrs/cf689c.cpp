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
#define mk(x,y) make_pair(x,y)
#define pf() pop_front()
#define pb() pop_back()
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;

const double pi = acos(-1.0);
const ll inf = 0x7fffffff;
const ll mod = 1e9 + 7;
const double eps = 1e-8;
const ll linf = 1e18;

ll m;

ll judge(ll n)
{
    ll cnt = 0;
    for (ll i = 2;i <= 1e6; ++ i)
    {
        ll cur = n / (i * i * i);
        if (!cur)
            break;
        cnt += cur;
    }

    return cnt;
}

int main()
{

    scanf("%I64d",&m);
    ll l = 0,r = linf;
    ll ans = -1;
    while (r >= l)
    {
        ll mid = l + r >> 1;
        ll temp = judge(mid);
        if (temp >= m)
        {
            if (temp == m)
                ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    printf("%I64d\n",ans);
    return 0;
}
