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
#define N 11
int n, k, it[N], tot;
vi p[N];

int propose(int hard, int& sum) {
  if (hard >= sum) {
    sum += hard;
    return 1;
  }
  return 0;
}

bool check() {
  for (int i=1; i<=n; i++) if (it[i] < SZ(p[i])) return false;
  return true;
}

void solve() {
  for (int i=1; i<=n; i++) p[i].clear();
  for (int i=1; i<=n; i++) {
    int num;
    it[i] = 0;
    scanf("%d", &num);
    for (int j=1; j<=num; j++) {
      int val;
      scanf("%d", &val);
      p[i].push_back(val);
    }
    p[i].push_back(50);
  }
  tot = 0;
  int cnt = 0, sum = 0;
  while (cnt < k) {
    if (check()) {
      sum += (k - cnt) * 50;
      break;
    }
    for (int i=1; i<=n; i++) {
      if (it[i] < SZ(p[i]))
        cnt += propose(p[i][it[i]++], sum);
      if (cnt == k) break;
    }
  }
  printf("%d\n", sum);
}

int main() {
  //freopen("easy.in", "r", stdin);
  //freopen("easy.out", "w", stdout);
  while (scanf("%d%d", &n, &k) != EOF) solve();
  return 0;
}
