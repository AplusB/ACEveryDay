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
const ll mod = 1000000007ll;

int dfs(int n, int k, vi& v) {
  if (n == 0) return v[n] = 1;
  if (v[n]) return v[n];
  ll res = 0;
  for (int i=1; i<=k; i++) if (n-i>=0) {
    res += (ll)dfs(n-i, k, v);
    if (res >= mod) res %= mod;
  }
  return v[n] = (int)res;
}

int main() {
  int n, k, d;
  cin >> n >> k >> d;
  vi a(n+1);
  vi b(n+1);
  ll x = dfs(n, k, a);
  ll y = dfs(n, d-1, b);
  cout << (x - y + mod) % mod << endl;
  return 0;
}
