#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <iterator>
#include <functional>
#include <queue>
#include <cmath>
#include <set>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#define ff first
#define ss second
#define pu system("pause")
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const double pi = acos(-1.0);
const ll inf = 0x7fffffff;
const ll mod = 1e9 + 7;

ll s[100010];

int n,k;

bool judge(ll mid)
{
    int cnt = 0;
    deque <ll> q;
    for (int i = 0;i < n ;++ i)
        q.push_back(s[i]);
    while (!q.empty())
    {
        ll r = q.back();
        q.pop_back();
        if (r > mid)
            return 0;
        if (q.empty())
        {
            ++ cnt;
            break;
        }
        ll l = q.front();
        if (l + r <= mid)
        {
            ++ cnt;
            q.pop_front();
        }
        else
            ++ cnt;
    }
//    printf("mid = %I64d cnt = %d\n",mid,cnt);
    return cnt > k ? 0 : 1;
}

int main()
{
    scanf("%d%d",&n,&k);
    ll maxn = 0;
    for (int i = 0;i < n; ++ i)
    {
        scanf("%I64d",&s[i]);
        maxn = max(maxn,s[i]);
    }

    ll l = maxn,r = inf,ans = 0;
    while (r >= l)
    {
        ll mid = l + r >> 1;
        if (judge(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    printf("%I64d\n",ans);
    return 0;
}
