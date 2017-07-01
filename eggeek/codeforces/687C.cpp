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
#define INF 1e9
#define INF_LL 4e18
#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
/*-----------------------------------*/
#define N 505
int n, k, c[N], dp[2][N][N];

void solve() {
  dp[0][0][0] = 1;
  int idx = 0;
  for (int i=0; i<n; i++) {
    int nxt = (idx + 1) % 2;
    for (int j=0; j<=k; j++) {
      for (int x=0; x<=j; x++) if (dp[idx][j][x]) {
        dp[nxt][j][x] = 1;
        if (j + c[i+1] <= k) {
          dp[nxt][j+c[i+1]][x+c[i+1]] = 1;
          dp[nxt][j+c[i+1]][x] = 1;
        }
      }
    }
    idx = nxt;
  }
  vi res;
  for (int i=0; i<=k; i++) if (dp[idx][k][i]) res.push_back(i);
  printf("%d\n", SZ(res));
  for (int i=0; i<SZ(res); i++) printf("%d%c", res[i], i+1<SZ(res)?' ': '\n');
}

int main() {
  cin >> n >> k;
  for (int i=1; i<=n; i++) cin >> c[i];
  solve();
  return 0;
}
