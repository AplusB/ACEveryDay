#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
const int INF = 0x7f7f7f7f;
struct ty
{
    int x, y, r;
}a[60];
bool v[60][60];
int b[60][60];
int n, k;

int dist(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}
int calc()
{
    int ans = INF;
    int r = (1 << k) - 1;
    for(int i = 0;i <= r; i++)
    {
        memset(v, 0, sizeof(v));
        int cnt = 0;
        for(int j = 1; j <= k; j++)
        {
            if(i & (1 << (j - 1)))
            {
                cnt++;
                for(int p = 1; p <= n; p++)
                for(int q = 1; q <= n; q++)
                {
                    if(dist(p, q, a[j].x, a[j].y) <= a[j].r) v[p][q] = true;
                }
            }
        }
        int boo = 0;
        for(int p = 1; p <= n; p++)
        for(int q = 1; q <= n; q++)
        {
            if (boo) break;
            if(!b[p][q] && !v[p][q])
            {
                boo = 1;
                break;
            }
        }
        if(!boo) ans = min(ans, cnt);
    }
    return ans;
}
int main()
{

    while((scanf("%d", &n) != EOF) && n != 0)
    {
        scanf("%d", &k);
        memset(b, 0, sizeof (b));
        for (int i = 1; i <= k; i++)
        {
            scanf("%d%d", &a[i].x, &a[i].y);
            b[a[i].x][a[i].y] = 1;
        }

        for (int i = 1; i <= k; i++)
        {
            scanf("%d", &a[i].r);
        }
        int t = calc();
        if (t >= INF) printf("-1\n");
        else printf("%d\n", calc());

    }

    return 0;
}
