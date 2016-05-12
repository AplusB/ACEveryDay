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
#define Lowbit(x) ((x)&(-x))
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1|1
#define MP(a, b) make_pair(a, b)
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
const int maxn = 1e5 + 10;
const double eps = 1e-8;
const double PI = acos(-1.0);
typedef pair<int, int> pii;

struct node
{
    double sub;  //bin - p
    int id;
};
node a[maxn], b[maxn];
int cmp(node x, node y)
{
    return ((x.sub - y.sub) > eps);
}

double dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    double x1, y1, x2, y2, tx, ty;
    scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &tx, &ty);
    int n;
    scanf("%d", &n);
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        double x, y;
        scanf("%lf%lf", &x, &y);
        sum += 2 * dist(x, y, tx, ty);
        double bin = dist(x, y, tx, ty);
        a[i].sub = bin - dist(x, y, x1, y1);
        b[i].sub = bin - dist(x, y, x2, y2);
        a[i].id = i;
        b[i].id = i;
    }
    sort(a, a + n, cmp);
    sort(b, b + n, cmp);
    double ans = INF;
    ans = min(sum - a[0].sub, sum - b[0].sub);
    if (a[0].id == b[0].id)
        ans = min(ans, sum - max(a[0].sub + b[1].sub, a[1].sub + b[0].sub));
    else ans = min(ans, sum - (a[0].sub + b[0].sub));
    printf("%.10f\n", ans);
    return 0;
}
