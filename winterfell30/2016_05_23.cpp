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
const int maxn = 1e3 + 7;
const double eps = 1e-8;
const int MOD = 1000000009;
const double PI = acos(-1.0);

#define dis(a, b) sqrt(sqr(a.x - b.x) + sqr(a.y - b.y))

int n, p;

inline double sqr(double x)
{
	return x * x;
}
struct Point
{
    double x,y;
    Point(){}
    Point(double _x,double _y)
    {
        x = _x;y = _y;
    }
	Point operator - (const Point &b) const
	{
		return Point(x - b.x, y - b.y);
	}
    void input()
    {
        scanf("%lf%lf",&x,&y);
    }
	double norm()
	{
		return sqrt(sqr(x) - sqr(y));
	}
}a[maxn], ch[maxn];

double mult(const Point &a, const Point &b, const Point &o) {
    return (a.x - o.x) * (b.y - o.y) >= (b.x - o.x) * (a.y - o.y);
}

bool cmp(Point a, Point b)
{
    if (a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}

double Graham(Point p[], int n, Point res[]) {
    int top = 1;
    sort(p, p + n, cmp);
    if (n == 0) return 0;
    res[0] = p[0];
    if (n == 1) return 0;
    res[1] = p[1];
    if (n == 2) return dis(p[0], p[1]) * 2;
    res[2] = p[2];
    for (int i = 2; i < n; i++) {
        while (top && (mult(p[i], res[top], res[top - 1])))
            top--;
        res[++top] = p[i];
    }
    int len = top;
    res[++top] = p[n - 2];
    for (int i = n - 3; i >= 0; i--) {
        while (top != len && (mult(p[i], res[top], res[top - 1])))
            top--;
        res[++top] = p[i];
    }
    return top;
}

int cnt(int i, int j) {
    return (abs((int)ch[i].x + (int)ch[j].x) * abs((int)ch[i].y + (int)ch[j].y)) % p;
}

int dp[maxn][maxn];
int len[maxn][maxn];



void calcost()
{
    memset(len, 0, sizeof(len));
    for (int i = 0; i < n; i++)
        for (int j = i + 2; j < n; j++)
            len[i][j] = len[j][i] = cnt(i, j);
}

int DP(int l, int r)
{
    if (~dp[l][r]) return dp[l][r];
    if (r - l <= 2) return dp[l][r] = 0;
    int ans = INF;
    for (int i = l + 1; i <= r - 1; i++)
        ans = min(ans, DP(l,i)+DP(i,r)+len[l][i]+len[i][r]);
    return dp[l][r] = ans;
}


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while (scanf("%d%d", &n, &p) != EOF)
    {
        for (int i = 0; i < n; i++)
            a[i].input();
        if (Graham(a, n, ch) < n)
            puts("I can't cut.");
        else
        {
            calcost();
            memset(dp, -1, sizeof(dp));
            printf("%d\n", DP(0, n - 1));
        }
    }
    return 0;
}
