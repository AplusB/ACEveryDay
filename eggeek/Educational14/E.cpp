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
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template<class T> inline T min(T a, T b, T c) {return min(min(a,b),c);}
template<class T> inline T min(T a, T b, T c, T d) {return min(min(a,b),min(c,d));}
template<class T> inline T max(T a, T b, T c) {return max(max(a,b),c);}
template<class T> inline T max(T a, T b, T c, T d) {return max(max(a,b),max(c,d));}
const int INF = 1e9;
const ll INF_LL = 4e18;
const ll mod = 1000000007;
const double pi = acos(-1.0);
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
/*-----------------------------------*/
#define N 101
int n;
ll k, d[N][N], a[N], I[N][N];

bool check(ll v) {
  int cnt = 0;
  while (v) {
    cnt += v & 1l;
    v >>= 1l;
  }
  return cnt % 3 == 0;
}

void mul(ll (&a)[N][N], ll (&b)[N][N]) {
  ll tmp[N][N];
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++) tmp[i][j] = 0;

  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
      for (int k=0; k<n; k++) {
        tmp[i][j] = (tmp[i][j] + a[i][k] * b[k][j]);
        if (tmp[i][j] >= mod) tmp[i][j] %= mod;
      }

  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++) a[i][j] = tmp[i][j];
}

void pow(ll (&f)[N][N], ll times) {
  while (times) {
    if (times & 1l) {
      mul(I, f);
    }
    mul(f, f);
    times >>= 1l;
  }
}

void do_case() {
  for (int i=0; i<n; i++) cin >> a[i];
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++) d[i][j] = check(a[i]^a[j]);

  memset(I, 0, sizeof(I));
  for (int i=0; i<n; i++) I[i][i] = 1l;
  pow(d, k-1);
  ll ans = 0;
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++) {
      ans += I[i][j];
      if (ans >= mod) ans %= mod;
    }
  cout << ans << endl;
}

int main() {
  // freopen("test.in", "r", stdin);
  while (cin >> n >> k) do_case();
  return 0;
}
