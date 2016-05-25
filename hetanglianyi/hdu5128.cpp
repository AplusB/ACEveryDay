#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <queue>
using namespace std;
struct ty
{
    int x, y;
}a[50];
int has[300][300];
bool in(int x1, int y1, int x2, int y2, int x, int y)
{

    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
//    cout << x1 <<' '<< y1 <<' '<<x2 <<' '<< y2 <<' '<< x <<' '<<y<< endl;
    if (x >= x1 && x <= x2 && y >= y1 && y <= y2) return 1;
    return 0;
}
bool huizixin(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    if (x3 > x4) swap(x3, x4);
    if (y3 > y4) swap(y3, y4);
    if (x1 < x3 && x2 > x3 && x1 < x4 && x2 > x4 &&
        y1 < y3 && y2 > y3 && y1 < y4 && y2 > y4)
            return 1;
    return 0;
}
int myabs(int a)
{
    if (a < 0) a= -a;
    return a;
}
int main()
{
    int n;
    while (scanf("%d", &n) != EOF && n != 0)
    {
        memset(has, 0, sizeof(has));
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &a[i].x, &a[i].y);
            has[a[i].x][a[i].y] = i;
        }

        int maxn = -1;
        for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (i == j || a[i].x == a[j].x || a[i].y == a[j].y) continue;
            int x1 = a[i].x, x2 = a[j].x, y1 = a[i].y, y2 = a[j].y;
            int k = has[x1][y2], l = has[x2][y1];

            if (l*k == 0 || k == i || k == j || l == i || l == j || l == k) continue;

            for (int p = 1; p <= n; p++)
            for (int q = 1; q <= n; q++)
            {
                if (p == i || p == j || p == k || p == l) continue;
                if (q == i || q == j || q == k || q == l) continue;
                if (p == q || a[p].x == a[q].x || a[p].y == a[q].y) continue;
                int x3 = a[p].x, x4 = a[q].x, y3 = a[p].y, y4 = a[q].y;
                int r = has[x3][y4], s = has[x4][y3];
                if (r == i || r == j || r == k || r == l) continue;
                if (s == i || s == j || s == k || s == l) continue;
                if (r*s == 0 || r == p || r == q || s == p || s == q || r == s) continue;
                if (huizixin(x1,y1,x2,y2,x3,y3,x4,y4))
                {
                    int tmp = myabs(x1 - x2) * myabs(y1 - y2);
                    maxn = max(maxn, tmp);
                    continue;
                }
                if (huizixin(x3,y3,x4,y4,x1,y1,x2,y2))
                {
                    int tmp = myabs(x3 - x4) * myabs(y3 - y4);
                    maxn = max(maxn, tmp);
                    continue;
                }
                if (in(x1,y1,x2,y2, x3,y3)) continue;
                if (in(x1,y1,x2,y2, x4,y4)) continue;
                if (in(x1,y1,x2,y2, x3,y4)) continue;
                if (in(x1,y1,x2,y2, x4,y3)) continue;

                if (in(x3,y3,x4,y4, x1,y1)) continue;
                if (in(x3,y3,x4,y4, x2,y2)) continue;
                if (in(x3,y3,x4,y4, x2,y1)) continue;
                if (in(x3,y3,x4,y4, x1,y2)) continue;

                int tmp = myabs(x3 - x4) * myabs(y3 - y4) + myabs(x1 - x2) * myabs(y1 - y2);
                maxn = max(maxn, tmp);
            }
        }
        if (maxn == -1) printf("imp\n");
        else printf("%d\n", maxn);
    }
    return 0;
}
