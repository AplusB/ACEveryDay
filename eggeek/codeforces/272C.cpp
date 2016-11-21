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
#define N 100010
int n, m;

class FenwickTree {
  private:
    ll t[N];
  public:
    void add(int p, ll v) {
      while (p <= n) {
        t[p] = max(t[p], v);
        p += LOWB(p);
      }
    }

    ll prefix(int p) {
      ll ans = 0;
      while (p) {
        ans = max(ans, t[p]);
        p -= LOWB(p);
      }
      return ans;
    }
}f;

int main() {
  scanf("%d", &n);
  for (int i=1; i<=n; i++) {
    int a;
    scanf("%d", &a);
    f.add(i, a);
  }
  scanf("%d", &m);
  for (int i=0; i<m; i++) {
    int h, w;
    scanf("%d%d", &w, &h);
    ll maxH = f.prefix(w);
    cout << maxH << endl;
    f.add(1, maxH + (ll)h);
  }
  return 0;
}
