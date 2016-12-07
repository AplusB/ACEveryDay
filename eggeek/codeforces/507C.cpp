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
ll f[55], n, h;

ll calcF(int v) {
  if (v == 1) return f[v] = 2;
  return f[v] = 2ll * (calcF(v-1) + 1ll);
}

ll dfs(int high, ll lft, ll rht, int flag) {
  if (lft == rht) return 0;
  ll mid = lft + (1ll<<(high-1)) - 1ll;
  //printf("high:%d, lft:%lld, mid:%lld, rht:%lld\n", high, lft, mid, rht);
  if (n <= mid) {
    if (flag == 0) return dfs(high-1, lft, mid, 1-flag) + 1ll;
    else return f[high-1] + 2ll + dfs(high-1, lft, mid, 1);
  } else {
    if (flag == 1) return dfs(high-1, mid+1, rht, 1-flag) + 1ll;
    else return f[high-1] + 2ll + dfs(high-1, mid+1, rht, 0);
  }
}

int main() {
  calcF(50);
  cin >> h >> n;
  //for (int i=1; i<=h; i++) printf("f[%d]=%lld\n", i, f[i]);
  cout << dfs(h, 1ll, 1ll<<h, 0) << endl;
  return 0;
}
