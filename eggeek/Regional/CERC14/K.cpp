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
#define N 150010

struct P {
    int v, c;
    int val() {
        return v - c;
    }
} p[N];
int n, k, dp[N][10];

bool cmp(P x, P y) {
    if (x.v == y.v) return x.c < y.c;
    else return x.v < y.v;
}

int solve() {
    for (int i=0; i<n; i++)
        for (int j=0; j<=k; j++) dp[i][j] = 0;
    for (int i=0; i<n; i++) dp[i][0] = max(0, p[i].val());
    for (int i=1; i<=k; i++) dp[n-1][i] = 0;

    for (int i=n-2; i>=0; i--) {
        dp[i][0] = max(dp[i][0], dp[i+1][0]);
        for (int j=1; j<=k; j++) {
            int u = p[i].val();
            int v = max(dp[i+1][j-1] - p[i].c, 0);
            dp[i][j] = min(u, v);
            dp[i][j] = max(dp[i][j], dp[i+1][j]);
        }
    }
    return dp[0][k];
}

void do_case() {
    scanf("%d%d", &n, &k);
    for (int i=0; i<n; i++) {
        int v, c;
        scanf("%d%d", &v, &c);
        p[i] = P{v, c};
    }
    sort(p, p+n, cmp);
    int ans = solve();
    printf("%d\n", ans);
}

int main() {
    int cas;
//    freopen("test.in", "r", stdin);
    cin >> cas;
    while (cas--) do_case();
    return 0;
}
