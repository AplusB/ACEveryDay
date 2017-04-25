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
#define N 110
int n, m, x, y;
ll k, cnt[N][N];

int main() {
  cin >> n >> m >> k >> x >> y;
  if (n == 1) {
    for (int i=1; i<=m; i++) cnt[1][i] = k / (ll)m;
    k %= m;
    for (int i=1; i<=m && k>0; i++) cnt[1][i]++, k--;
  } else {
    ll b = 2*(n-1) * m;
    for (int i=2; i<n; i++) for (int j=1; j<=m; j++) cnt[i][j] = k / b * 2ll;
    for (int j=1; j<=m; j++) cnt[n][j] = k / b, cnt[1][j] = k / b;
    //for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) cnt[i][j] += k / b;
    //for (int i=n-1; i>1; i--) for (int j=1; j<=m; j++) cnt[i][j] += k / b;
    k %= b;
    int curr = 1, curc = 1, d = 0;
    while (k) {
      cnt[curr][curc] ++;
      k--;
      if (curc < m) curc ++; else if (d == 0) {
        if (curr < n) {
          curr++, curc = 1;
        } else {
          curr--, curc = 1;
          d = 1;
        }
      } else {
        if (curr > 1) {
          curr--, curc = 1;
        } else {
          curr++, curc = 1;
          d = 0;
        }
      }
    }
  }

  ll maxq = cnt[1][1];
  ll minq = cnt[1][1];
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=m; j++) {
      maxq = max(maxq, cnt[i][j]);
      minq = min(minq, cnt[i][j]);
    }
  }
  cout << maxq << " "
       << minq << " "
       << cnt[x][y] << endl;
  return 0;
}
