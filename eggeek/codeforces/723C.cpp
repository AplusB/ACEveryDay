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
#define N 2002
int n, m;
int a[N], b[N];
map<int, int> ca;

void solve() {
  int change = 0;
  int minV = n / m;
  int idx = 1;
  int need = 0;
  vi buf;
  for (int i=1; i<=n; i++) ca[a[i]]++;
  for (int i=1; i<=n; i++) b[i] = a[i];
  for (int i=1; i<=m; i++)
    if (ca[i] < minV)
      need += minV - ca[i];
  for (int i=1; i<=n && SZ(buf) < need; i++) {
    if (a[i] > m) {
      buf.push_back(i);
    } else if (a[i] <= m && ca[a[i]] > minV) {
      buf.push_back(i);
      ca[a[i]]--;
    }
  }
  for (int i=1; i<=m; i++) {
    while (ca[i] < minV) {
      assert(!buf.empty());
      int p = buf.back(); buf.pop_back();
      b[p] = i;
      ca[i]++;
    }
  }
  printf("%d %d\n", minV, need);
  for (int i=1; i<=n; i++) printf("%d%c", b[i], i==n?'\n': ' ');
}

int main() {
  cin >> n >> m;
  for (int i=1; i<=n; i++) cin >> a[i];
  solve();
  return 0;
}
