#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
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
const int MOD = 1000000007;
const int maxn = 1e5 + 10;
const double eps = 1e-8;
const double PI = acos(-1.0);
typedef pair<int, int> pii;
LL c[5*maxn];
LL n, k;

bool check2(int x)
{
    LL sum = 0;
    for (int i = n-1; i >= 0; i--)
        if (c[i] > x) sum += (c[i] - x);
    return sum <= k;
}

bool check1(int x)
{
    LL sum = 0;
    for (int i = 0; i < n; i++)
        if (c[i] < x) sum += (x - c[i]);
    return sum <= k;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    LL sum = 0;
    scanf("%lld%lld", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &c[i]);
        sum += c[i];
    }
    sort(c, c + n);
    LL mmin = sum / n;          //最小值最大
    LL mmax = mmin + (sum % n != 0);  //最大值最小
    LL l = c[0], r = mmin;
    while (l < r)               //k天后的最小值
    {
        int mid = (l + r + 1) / 2;
        //printf("%d\n", mid);
        if (check1(mid)) l = mid;
        else r = mid - 1;
    }
    LL ansmin = l;
    l = mmax, r = c[n-1];
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (check2(mid)) r = mid;
        else l = mid + 1;
    }
    LL ansmax = l;
    //printf("%lld %lld\n", ansmin, ansmax);
    printf("%lld\n", ansmax - ansmin);
    return 0;
}
