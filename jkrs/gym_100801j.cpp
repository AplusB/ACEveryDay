#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
#include <cctype>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <string>
#define ff first
#define ss second
#define pu system("pause")
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll inf = 0x7fffffff;
const double pi = acos(-1.0);
const ll mod = 998244353;
ll dp[50010];
struct node
{
    ll  d,p;
}a[50010];
struct noden
{
    ll  index, cost;
    noden(ll  a, ll  b) : index(a), cost(b) {};
    bool operator < (const noden& a) const
    {
        return cost > a.cost;
    }
};
ll  time[50010];
stack <node> s;

ll  n,m;
bool judge(ll  r)
{
    fill(dp, dp + n + 1, inf);
    dp[1] = 0;
    priority_queue<noden> q;
//    cout << "*****" << endl;
    while (!q.empty())
        q.pop();
//    cout << "*****" << endl;
    q.push(noden(1, -1));
    for (ll  i = 2; i <= n; ++i)
    {
//        cout << "****" << endl;
        while (!q.empty())
        {
//            cout << "*****" << endl;
            noden cur = q.top();
//            cout << "index = " << cur.index << " cost = " << cur.cost << endl;
            q.pop();
            if (i - cur.index <= r)
            {
//                cout << "****" << endl;
                if (dp[i] > i + cur.cost)
                {
//                    cout << ">>>>>>>>>>>" << endl;
                    dp[i] = i + cur.cost;
                    q.push(noden(i, dp[i] - i + time[i]));
                }
                q.push(cur);
                break;
            }
            else
                continue;
        }
    }
//    for (ll  i = 1; i < n; ++i)
//    {
//        cout << dp[i] << "  ";
//    }
//    cout << endl;
    if (dp[n] <= m)
        return true;
    else
        return false;
}


int main()
{
    freopen("journey.in", "r", stdin);
    freopen("journey.out", "w", stdout);

    scanf("%I64d%I64d",&n,&m);
    for (ll  i = 1;i <= n - 1; ++ i)
    {
        scanf("%I64d",&a[i].p);
        a[i].d = i;
        while (!s.empty() && (s.top().d <= a[i].d && s.top().p > a[i].p))
            s.pop();
        s.push(a[i]);
    }

    for (ll  i = 2;i <= n - 1; ++ i)
        scanf("%I64d",&time[i]);
    ll  k = 0;
    while (!s.empty())
    {
        a[k ++] = s.top();
        s.pop();
    }
    reverse (a,a + k);
//    for (ll  i = 0;i < k; ++ i)
//        prll f("a[%I64d].d = %I64d p = %I64d\n",i,a[i].d,a[i].p);
    ll  l = 0,r = k;
    ll  ans = 0;
    while (r >= l)
    {
        ll  mid = l + r >> 1;
        if (judge(a[mid].d))
        {
            ans = a[mid].p;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
//    cout << "**&&&&&&&&&&&&&&&&&&&&&&**))))))))))))))*" << endl;
//    cout << judge(2) << endl;
    printf("%I64d\n",ans);
    return 0;
}
