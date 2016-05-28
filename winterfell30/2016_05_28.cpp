#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define LL long long
#define lowbit(x) ((x)&(-x))
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1|1
#define MP(a, b) make_pair(a, b)
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 7;
const double eps = 1e-8;
const int MOD = 1000000009;
const double PI = acos(-1.0);
int use[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
struct node
{
    int y, m, d;
}ans[2*maxn];

bool judge(int y)
{
    if (y % 400 == 0 ||(y % 4 == 0 && y % 100 != 0)) return 1;
    return 0;
}

int main()
{
   // freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, y, m, d;
        scanf("%d%d%d%d", &y, &m, &d, &n);
        int num = 1;
        ans[1].y = y, ans[1].m = m, ans[1].d = d;
        int nowy = y, nowm = m, nowd = d;
        while (1)
        {
            nowd += 7;
            sum += 7;
            if (judge(nowy) && nowm == 2)
            {
                if (nowd > 29)
                {
                    nowm++;
                    nowd %= 29;
                }
            }
            else
            {
                if (nowd > use[nowm])
                {
                    nowd %= use[nowm];
                    nowm++;
                    if (nowm > 12)
                    {
                        nowm = 1;
                        nowy++;
                    }
                }
            }
            if (nowd == d && nowm == m && (nowy - y) % 400 == 0) break;
            if (nowd == 1 || nowd == 11 || nowd == 21)
                ans[++num].y = nowy, ans[num].m = nowm, ans[num].d = nowd;
        }
        //printf("%d\n", num);
        //printf("%d %d %d\n", ans[num].y, ans[num].m, ans[num].d);
        if (n % num == 0)
        {
            int time = n / num - 1;
            printf("%d %d %d\n", time * 400 + ans[num].y, ans[num].m, ans[num].d);
        }
        else
        {
            int time = n / num;
            num = n % num;
            //printf("%d %d %d\n", num, y, ans[num].y);
            printf("%d %d %d\n", time * 400 + ans[num].y, ans[num].m, ans[num].d);
        }
    }
    return 0;
}


