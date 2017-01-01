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
ll n, d, a, b;
vector<ll> x, y;
vector<pair<ll, int>> v;

int main() {
  cin >> n >> d >> a >> b;
  x.resize(n);
  y.resize(n);
  for (int i=0; i<n; i++) {
    cin >> x[i] >> y[i];
    v.push_back({x[i] * a + y[i] * b, i+1});
  }
  sort(ALL(v));
  ll tot = 0;
  vi ans;
  for (int i=0; i<n; i++) {
    if (tot + v[i].first <= d) {
      tot += v[i].first;
      ans.push_back(v[i].second);
    }
  }
  printf("%d\n", SZ(ans));
  for (int i=0; i<SZ(ans); i++) printf("%d%c", ans[i], i+1<SZ(ans)?' ': '\n');
  return 0;
}
