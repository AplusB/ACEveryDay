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

#define fr first
#define sc second
#define pb(a) push_back(a)
#define Rint(a) scanf("%d", &a)
#define Rll(a) scanf("%I64d", &a)
#define Rs(a) scanf("%s", a)
#define Fread() freopen("in", "r", stdin)
#define Fwrite() freopen("out", "w", stdout)
#define Rep(i, n) for(int i = 0; i < (n); i++)
#define For(i, a, n) for(int i = (a); i < (n); i++)
#define Cls(a) memset((a), (0), sizeof(a))
#define Clr(a, x) memset((a), (x), sizeof(a))
#define Full(a) memset((a), 0x7f7f, sizeof(a))

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
const int maxn = 8010;
int sum[maxn<<2];
int vis[maxn];
int n, a, b, c;

void pushDOWN(int rt) {
    if(sum[rt] != -1) {
        sum[rt<<1] = sum[rt<<1|1] = sum[rt];
        sum[rt] = -1;
    }
}

void update(int L, int R, int c, int l, int r, int rt) {
    if(L <= l && r <= R) {
        sum[rt] = c;
        return;
    }
    pushDOWN(rt);
    int m = (l + r) >> 1;
    if(L <= m) update(L, R, c, lson);
    if(R > m) update(L, R, c, rson);
}

int query(int p, int l, int r, int rt) {
    if(l == r) {
        return sum[rt];
    }
    pushDOWN(rt);
    int m = (l + r) >> 1;
    if(p <= m) return query(p, lson);
    else return query(p, rson);
}

int main() {
    // Fread();
    while(~Rint(n)) {
        int lo = 0x7f7f;
        Clr(sum, -1); Cls(vis);
        Rep(i, n) {
            Rint(a), Rint(b), Rint(c);
            lo = min(lo, a+1);
            update(a+1, b, c, 1, 8000, 1);
        }
        int p = query(lo, 1, 8000, 1);
        vis[p]++;
        For(i, lo+1, 8001) {
            int t = query(i, 1, 8000, 1);
            if(t == -1) {
                p = -1;
                continue;
            }
            if(t != p) {
                vis[t]++;
                p = t;
            }

        }
        Rep(i, 8001) {
            if(vis[i]) printf("%d %d\n", i, vis[i]);
        }
        printf("\n");
    }
    return 0;
}
