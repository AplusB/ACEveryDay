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
#define N 200010
int n, m, k, c[N], l[N], r[N], f[N];
vi cnt[N];

int find_fa(int cur) {
  if (f[cur] == cur) return cur;
  else return f[cur] = find_fa(f[cur]);
}

int solve() {
  for (int i=1; i<=n; i++) f[i] = i;
  for (int i=1; i<=m; i++) {
    int fu = find_fa(f[l[i]]);
    int fv = find_fa(f[r[i]]);
    if (fu != fv) f[fu] = fv;
  }
  for (int i=1; i<=n; i++) cnt[find_fa(f[i])].push_back(c[i]);
  int res = 0;
  for (int i=1; i<=n; i++) if (SZ(cnt[i])) {
    map<int, int> cor;
    int maxV = 0;
    for (int j: cnt[i]) {
      cor[j]++;
      maxV = max(maxV, cor[j]);
    }
    res += SZ(cnt[i]) - maxV;
  }
  return res;
}

int main() {
  cin >> n >> m >> k;
  for (int i=1; i<=n; i++) cin >> c[i];
  for (int i=1; i<=m; i++) cin >> l[i] >> r[i];
  cout << solve() << endl;
  return 0;
}
