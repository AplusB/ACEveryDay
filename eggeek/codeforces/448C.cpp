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
#define N 5005
int n, a[N], b[N];

int solve(int l, int r) {
  assert(r >= l);
  for (int i=l; i<=r; i++) assert(a[i] > 0);
  if (r == l) return 1;
  int ans = r - l + 1;
  int minA = 1e9+1;
  for (int i=l; i<=r; i++) minA = min(a[i], minA);
  int nxtl = -1, nxtr = -1;
  int cnt = minA;
  for (int i=l; i<=r; i++) a[i] -= minA;
  for (int i=l; i<=r; i++) {
    if (a[i]) {
      if (nxtl == -1) nxtl = i;
      nxtr = i;
    } else {
      if (nxtl != -1 && nxtr >= nxtl) cnt += solve(nxtl, nxtr);
      nxtl = nxtr = -1;
    }
  }
  if (nxtl != -1 && nxtr >= nxtl) cnt += solve(nxtl, nxtr);
  ans = min(ans, cnt);
  return ans;
}

int main() {
  cin >> n;
  for (int i=1; i<=n; i++) cin >> a[i];
  for (int i=1; i<=n; i++) b[i] = a[i];
  cout << solve(1, n) << endl;
  return 0;
}
