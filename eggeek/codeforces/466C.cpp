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
#define N 500010
ll a[N];
int n;

ll solve() {
  ll ans = 0;
  ll sum, tot = 0;
  for (ll i: a) tot += (ll)i;
  if (tot % 3ll ) return 0;
  vi f, t;
  sum = 0;
  for (int i=1; i<=n; i++) {
    sum += (ll)a[i];
    if (sum == tot / 3) f.push_back(i);
  }
  sum = 0;
  for (int i=n; i>=1; i--) {
    sum += (ll)a[i];
    if (sum == tot / 3) t.push_back(i);
  }
  sort(ALL(t));
  for (int i: f) {
    auto lb = lower_bound(ALL(t), i+2);
    ans += (ll)(t.end() - lb);
  }
  return ans;
}

int main() {
  cin >> n;
  for (int i=1; i<=n; i++) cin >> a[i];
  ll ans = solve();
  cout << ans << endl;
  return 0;
}
