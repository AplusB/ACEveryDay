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
#define N 1000010
int n, k, c[N], vis[N];
vi prim;
int fk[N], fc[N];

void init() {
  for (int i=2; i<N; i++) {
    if (!vis[i]) prim.push_back(i);
    for (int j=0; j<SZ(prim) && (ll)(i * prim[j]) < N; j++) {
      vis[i * prim[j]] = true;
      if (i % prim[j] == 0) break;
    }
  }
}

void factorize(int num, int* f) {
  for (int i=0; i<SZ(prim) && (ll)prim[i] * prim[i] <= num; i++) if (num % prim[i] == 0) {
    if (vis[num]) return;
    vis[num] = true;
    int cnt = 0;
    while (num % prim[i] == 0) {
      cnt++;
      num /= prim[i];
    }
    f[prim[i]] = max(f[prim[i]], cnt);
  }
  if (num != 1) f[num] = max(f[num], 1);
}

int main() {
  init();
  scanf("%d%d", &n, &k);
  memset(vis, false, sizeof(vis));
  factorize(k, fk);
  for (int i=0; i<n; i++) scanf("%d", &c[i]);
  memset(vis, false, sizeof(vis));
  for (int i=0; i<n; i++) {
    factorize(c[i], fc);
  }
  bool flag = true;
  for (int i=0; i<N; i++) if (fk[i]) {
    if (fk[i] > fc[i]) {
      flag = false;
      break;
    }
  }
  printf(flag?"Yes\n": "No\n");
  return 0;
}
