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
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
/*-----------------------------------*/
#define N 100011
int n, lg[N];
ll a[N];
ll st[N][18];

void read() {
//  scanf("%d", &n);
  cin >> n;
  for (int i=0; i<n; i++) cin >> a[i];
}

ll gcd(ll a, ll b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  return gcd(b, a%b);
}

void init_st() {
  for (int i=0; i<n; i++) st[i][0] = a[i];
  for (int k=1; (1<<k) <= n; k++) {
    for (int j=0; j<n; j++) {
      int x = min(j + (1<<(k-1)), n-1);
      st[j][k] = gcd(st[j][k-1], st[x][k-1]);
    }
  }
}

ll g(int l, int r) {
  int len = r - l + 1;
  int k = lg[len];
  ll res = gcd(st[l][k], st[r-(1<<k)+1][k]);
  return res;
}

ll bsearch(ll l, ll r, ll i) {
  if (l>r) return 0;
  ll best = r;
  while (l <= r) {
    ll mid = (l+r) >> 1;
    if (g(mid, i) == g(best, i)) {
      best = mid;
      r = mid-1;
    } else {
      l = mid+1;
    }
  }
  return best;
}

ll get_ans(ll i) {
  ll l = bsearch(0, i, i);
  ll gl = a[i];
  ll len = i - l + 1l;
  ll ans = gl * len;
  while (l > 0) {
    ll j = l-1;
    ll gj = g(j, i);
    ll d = gl / gj;
    assert(d > 1l);
    ll nxtl = bsearch(0l, (i-len*d+1l), i);
    ll gnxtl = g(nxtl, i);
    ll tmp = (i-nxtl+1l) * gnxtl;
    ans = max(ans, tmp);
    assert(nxtl < l);
    len = i-nxtl+1l;
    l = nxtl;
    gl = gnxtl;
  }
  return ans;
}

void init_lg() {
  lg[1] = 0;
  for (int i=2; i<N; i++) {
    lg[i] = lg[i>>1] + 1;
  }
}

void do_case() {
  read();
  init_st();
  ll ans = 0;
  for (int i=0; i<n; i++) {
    ans = max(ans, get_ans(i));
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  init_lg();
  int T;
  cin >> T;
  while (T--) do_case();
  return 0;
}
