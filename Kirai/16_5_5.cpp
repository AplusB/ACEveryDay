#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>

using namespace std;

typedef long long ll;
typedef struct Node {
    ll x, y;
    ll a, b;
}Node;
const int maxn = 1000010;
ll r, n;
int pos;
Node sq[maxn];
ll sum[maxn];
ll tot;

int main() {
    // freopen("in", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%I64d %I64d", &r, &n);
        tot = 0;
        memset(sum, 0, sizeof(sum));
        memset(sq, 0, sizeof(sq));
        for(int i = 0; i < n; i++) {
            scanf("%I64d%I64d%I64d%I64d", &sq[i].x, &sq[i].y, &sq[i].a, &sq[i].b);
            tot += sq[i].a * sq[i].b;
            for(int j = sq[i].x; j < sq[i].x + sq[i].a; j++) {
                sum[j] += sq[i].b;
            }
        }
        ll cur = 0;
        for(pos = 0; cur * 2 < tot; pos++) {
            cur += sum[pos];
        }
        while(0 == sum[pos] && pos < r) pos++;
        printf("%d\n", pos);
    }
    return 0;
}