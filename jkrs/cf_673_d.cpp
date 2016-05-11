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

bool h[1010];

int main()
{
    int n,k,a,b,c,d;
    scanf("%d%d%d%d%d%d",&n,&k,&a,&b,&c,&d);
    for (int i = 1;i <= n; ++ i)
        h[i] = 1;
    h[a] = h[b] = h[c] = h[d] = 0;
    if (n + 1 > k)
        puts("-1");
    else if (n == 4)
    {
        puts("-1");
    }
    else
    {
        printf("%d %d ",a,c);
        for (int i = 1;i <= n; ++ i)
            if (h[i])
                printf("%d ",i);
        printf("%d %d\n",d,b);
        printf("%d %d ",c,a);
        for (int i = 1;i <= n; ++ i)
            if (h[i])
                printf("%d ",i);
        printf("%d %d\n",b,d);
    }
    return 0;
}
