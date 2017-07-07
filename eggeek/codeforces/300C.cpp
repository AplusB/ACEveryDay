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
#define N 1000001
const ll mod = 1000000007;
ll a, b, n, A[N];

ll p(ll v, ll t) {
  ll res = 1;
  while (t) {
    if (t % 2) res = res * v % mod;
    v = v * v % mod;
    t >>= 1;
  }
  return res;
}

void init() {
  A[0] = 1;
  for (int i=1; i<N; i++) A[i] = A[i-1] * (ll)i % mod;
}

bool is_good(ll v) {
  while (v) {
    if (v % 10 != a && v % 10 != b) return false;
    v /= 10;
  }
  return true;
}

ll inv(ll v) {
  return p(v, mod-2);
}

ll Cn(ll v) {
  return A[n] * inv(A[n-v]) % mod * inv(A[v]) % mod;
}

ll solve() {
  ll res = 0;
  for (ll z=a*n; z<=b*n; z++) if (is_good(z)) {
    if ( (b * n - z) % (b - a) ) continue;
    ll x = (b * n - z) / (b - a);
    res += Cn(x);
    res %= mod;
  }
  return res;
}

int main() {
  init();
  cin >> a >> b >> n;
  cout << solve() << endl;
  return 0;
}
