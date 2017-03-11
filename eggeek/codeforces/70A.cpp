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
const ll mod = 1000003;
ll f[1010];

ll p(int n) {
  ll res = 1ll;
  for (int i=0; i<n; i++) res = res * 2ll % mod;
  return res;
}

ll calc(int n) {
  if (n == 0) return 0ll;
  if (n == 1) return 3ll;
  ll res = p(n-1) * p(n-1) % mod;
  res += calc(n-1) * 3ll % mod;
  res %= mod;
  return f[n] =res;
}

int main() {
  int n;
  cin >> n;
  memset(f, -1, sizeof(f));
  ll a = calc(n);
  ll b = p(n) * p(n) % mod;
  cout << (b - a + mod) % mod << endl;
  return 0;
}
