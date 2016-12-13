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
int n;
vector<int> a;
set<int> ans;

bool check() {
  int d = a[1] - a[0];
  for (int i=0; i+1<SZ(a); i++) {
    if (a[i+1] - a[i] != d) return false;
  }
  return true;
}

void solve() {
  if (n == 1) return;
  ll d = (a[1] - a[0]);
  if (check()) {
    ans.insert(a[0] - d);
    ans.insert(a[n-1] + d);
  }
  ll sum = (a[0] + a[n-1]) * (ll)(n + 1);
  ll tot = 0;
  for (ll i: a) tot += i;
  if ((sum - 2ll * tot) % 2) return;
  ll inter = (sum - 2ll * tot) / 2ll;
  a.push_back(inter);
  sort(ALL(a));
  if (check()) {
    ans.insert((int)inter);
  }
}

void print_ans() {
  printf("%d\n", SZ(ans));
  vector<int> out (ans.begin(), ans.end());
  for (int i=0; i<SZ(out); i++) printf("%d%c", out[i], i+1<SZ(out)?' ': '\n');
}

int main() {
  cin >> n;
  a.resize(n);
  for (int i=0; i<n; i++) cin >> a[i];
  sort(ALL(a));
  solve();
  if (n > 1) print_ans();
  else printf("-1\n");
  return 0;
}
