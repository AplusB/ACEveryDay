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

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    LL s, x;
    cin >> s >> x;
    if (s < x || (s - x) & 1)
        return puts("0");
    LL And = (s - x) >> 1;
    if (x & And) return puts("0");
    LL ans = s == x ? -2 : 0;
    int cnt = 0;
    while (x)
    {
        if (x & 1) cnt++;
        x >>= 1;
    }
    ans += 1LL << cnt;
    cout << ans << endl;
    return 0;
}
