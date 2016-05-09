#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <queue>
#include <cmath>
#include <set>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#define pu system("pause")
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const double pi = acos(-1.0);
const int inf = 0x7fffffff;
const int mod = 1e9 + 7;

int h[5010],ans[5010];

int a[5010];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 1;i <= n ;++ i)
    {
        scanf("%d",&a[i]);
    }

    for (int i = 1;i <= n; ++ i)
    {
        memset(h,0,sizeof (h));
        int maxn = 0;
        int cur = 0;
        for (int j = i;j <= n; ++ j)
        {
            ++ h[a[j]];
            if (h[a[j]] > maxn || (h[a[j]] == maxn && cur > a[j]))
            {
                maxn = h[a[j]];
                cur = a[j];
            }
            ++ ans[cur];
        }

    }
    for (int i = 1;i <= n; ++ i)
    {
        printf("%d%c",ans[i],i == n ? '\n' : ' ');
    }
    return 0;
}
