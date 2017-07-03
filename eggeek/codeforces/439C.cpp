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
#define N 100010
int a[N], n, k, p;
vi v[2], ans[N];

void solve() {
  for (int i=0; i<n; i++) v[a[i] % 2].push_back(a[i]);
  for (int i=0; i<k-p; i++) {
    if (!v[1].empty()) {
      ans[i].push_back(v[1].back());
      v[1].pop_back();
    } else {
      printf("NO\n");
      return;
    }
  }
  if (SZ(v[1]) % 2 || SZ(v[1]) / 2 + SZ(v[0]) < p) {
    printf("NO\n");
    return;
  }
  for (int i=k-p; i<k; i++) {
    if (SZ(v[1]) >= 2) {
      for (int j=0; j<2; j++) {
        ans[i].push_back(v[1].back());
        v[1].pop_back();
      }
    } else {
      ans[i].push_back(v[0].back());
      v[0].pop_back();
    }
  }
  for (int i: v[1]) ans[k-1].push_back(i);
  for (int i: v[0]) ans[k-1].push_back(i);
  printf("YES\n");
  for (int i=0; i<k; i++) {
    printf("%d", SZ(ans[i]));
    for (int j: ans[i]) printf(" %d", j);
    printf("\n");
  }
}

int main() {
  cin >> n >> k >> p;
  for (int i=0; i<n; i++) cin >> a[i];
  solve();
  return 0;
}
