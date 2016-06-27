#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cstdio>
#include <random>
#include <cmath>
#include <ctime>
#include <functional>
#include <algorithm>
#include <complex>
#include <numeric>
#include <limits>
#include <bitset>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <array>
#include <list>
#include <map>
#include <set>
using namespace std;
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) int((a).size())
#define MP(x, y) make_pair((x),(y))
#define FI first
#define SE second
#define LOWB(x) (x & (-x))
#define UNIQUE(a) sort(ALL(a)), (a).erase(unique(ALL(a)), (a).end())
#define HEIGHT(n) (sizeof(int) * 8 - __builtin_clz(n)) //height of range n segment tree
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template<class T> inline T min(T a, T b, T c) {return min(min(a,b),c);}
template<class T> inline T min(T a, T b, T c, T d) {return min(min(a,b),min(c,d));}
template<class T> inline T max(T a, T b, T c) {return max(max(a,b),c);}
template<class T> inline T max(T a, T b, T c, T d) {return max(max(a,b),max(c,d));}
const int INF = 1e9;
const ll INF_LL = 4e18;
const double pi = acos(-1.0);
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
/*-----------------------------------*/
#define N 300010
vi g[N];
int n, qs, sz[N], max_son[N], q[N], ans[N];
bool inq[N];
set<pii> h; // first: sz, second: id

void dfs_init(int rt) {
    sz[rt] = 1;
    max_son[rt] = -1;
    for (int i: g[rt]) {
        dfs_init(i);
        sz[rt] += sz[i];
        max_son[rt] = max(max_son[rt], sz[i]);
    }
}

void process_query(int l, int r, int rt) {
    auto itl = h.lower_bound(make_pair(l, 0));
    auto itr = h.upper_bound(make_pair(r, n));
    for (auto it=itl; it != itr; it++) {
        if (it == h.end()) break;
        ans[it->second] = rt;
    }
    h.erase(itl, itr);
}

void dfs_solve(int rt) {
    if (inq[rt]) h.insert(make_pair(sz[rt], rt));
    if (max_son[rt] == -1) {
        if (inq[rt]) ans[rt] = rt;
        return;
    }
    int l, r;
    // SZi in [SZc+SZi, 2*SZi]
    l = max_son[rt] + sz[rt];
    r = 2 * sz[rt];
    process_query(l, r, rt);

    // SZi in [2*SZc, SZc+SZi]
    l = 2 * max_son[rt];
    r = max_son[rt] + sz[rt];
    process_query(l, r, rt);

    for (int i: g[rt])
        dfs_solve(i);
}

int main() {
//    freopen("test.in", "r", stdin);
    scanf("%d%d", &n, &qs);
    for (int i=2; i<=n; i++) {
        int p;
        scanf("%d", &p);
        g[p].push_back(i);
    }
    for (int i=0; i<qs; i++) {
        scanf("%d", &q[i]);
        inq[q[i]] = true;
    }
    dfs_init(1);
    dfs_solve(1);
    for (int i=0; i<qs; i++) printf("%d\n", ans[q[i]]);
    return 0;
}
