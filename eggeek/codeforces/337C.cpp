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
const ll mod = 1e9 + 9;
ll n, m, k;

ll f(ll b) {
  ll res = 1;
  ll t = b + 1;
  ll p = 2ll;
  while (t) {
    if (t & 1ll) res = res * p % mod;
    p = p * p % mod;
    t >>= 1;
  }
  res = (res + mod - 2ll) % mod;
  res = res * k % mod;
  return res;
}

int main() {
  cin >> n >> m >> k;
  ll a = n - m;
  ll b = max(0ll, (m - a * (k-1l)) / k);
  ll r = max(0ll, (m - a * (k-1l)) % k);
  //printf("a:%lld, b:%lld, f(b):%lld, r:%lld\n", a, b, f(b), r);
  ll res = f(b) + max(0ll, m - b * k);
  cout << res % mod << endl;
  return 0;
}
