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
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#define pu system("pause")
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const double pi = acos(-1.0);
const ll inf = 0x7fffffff;
const ll mod = 1e9 + 7;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int maxn = inf,minn = 0;
    for (int i = 0;i < m; ++ i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if (x > y)
        {
            maxn = min(maxn,x);
            minn = max(minn,y);
        }
        else
        {
            maxn = min(maxn,y);
            minn = max(minn,x);
        }
    }
    if (!m)
    {
        printf("%d\n",n - 1);
        return 0;
    }
    printf("%d\n",maxn - minn >= 0 ? maxn - minn : 0);
    return 0;
}
