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
#define N 303
#define M 1000010
int dp[N << 1][N << 1], n;
map<int, int> hts;
vi ts;
struct P {
    int l, r, d;
} p[N];

bool cmp(P x, P y) {
    if (x.r == y.r) return x.l < y.l;
    else return x.r < y.r;
}

void pre_process() {
    ts.clear();
    hts.clear();
    ts.push_back(INF);
    ts.push_back(-INF);
    for (int i=0; i<n; i++) {
        ts.push_back(p[i].l);
        ts.push_back(p[i].r);
    }
    UNIQUE(ts);
    for (int i=0; i<SZ(ts); i++) hts[ts[i]] = i;
}

int solve(int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];
    int hid = -1;
    for (int i=0; i<n; i++) if (p[i].l > ts[l] && p[i].r < ts[r]) {
        if (hid == -1 || p[hid].d < p[i].d) hid = i;
    }
    if (hid == -1) dp[l][r] = 0;
    else {
        dp[l][r] = INF;
        for (int mid = hts[p[hid].l]; mid <= hts[p[hid].r]; mid++) {
            int a = solve(l, mid);
            int b = solve(mid, r);
            dp[l][r] = min(dp[l][r], a + b + p[hid].d);
        }
    }
    return dp[l][r];
}

void do_case() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        int l, r, d;
        scanf("%d%d%d", &l, &r, &d);
        p[i] = P{l, r, d};
    }
    pre_process();
    memset(dp, -1, sizeof(dp));
    int ans = solve(0, SZ(ts)-1);
    printf("%d\n", ans);
}

int main() {
    //freopen("test.in", "r", stdin);
    int cas;
    cin >> cas;
    while (cas--) do_case();
    return 0;
}
