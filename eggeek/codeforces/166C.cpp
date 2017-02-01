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
#define N 501
int n, x, a[N];

int main() {
  cin >> n >> x;
  for (int i=1; i<=n; i++) cin >> a[i];
  sort(a+1, a+1+n);
  int u = 0, v = 0, ans = N * 2;
  for (int i=1; i<=n; i++) if (a[i] < x) u++;
  for (int i=1; i<=n; i++) if (a[i] <= x) v++;
  //printf("u: %d, v: %d\n", u, v);
  for (int l=0; l<=n; l++) {
    for (int r=0; r<=n; r++) {
      int med = (l + r + n + 1) / 2;
      int idxu = u + 1;
      int idxv = v + l;
      if (idxu <= med && med <= idxv) {
        //printf("l: %d, r: %d, idxu: %d, idxv: %d, med: %d\n", l, r, idxu, idxv, med);
        ans = min(ans, l + r);
      }
    }
  }
  assert(ans != N * 2);
  cout << ans << endl;
  return 0;
}
