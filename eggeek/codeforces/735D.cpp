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
ll n;
ll prim[N], cnt;
bool vis[N];

void init() {
  for (ll i=2; i<N; i++) {
    if (!vis[i]) prim[cnt++] = i;
    for (int j=0; j<cnt && prim[j] * i < N; j++) {
      vis[i * prim[j]] = true;
      if (i % prim[j] == 0) break;
    }
  }
}

bool is_prim(ll var) {
  if (var < N) return !vis[var];
  for (int i=0; i<cnt; i++) {
    if (var % prim[i] == 0) return false;
    if (prim[i] * prim[i] > var) break;
  }
  return true;
}

ll solve(ll var) {
  if (is_prim(var)) return 1;
  if (var % 2 == 0) return 2;
  if (is_prim(var-2)) return 2;
  return 3;
}

int main() {
  init();
  cin >> n;
  cout << solve(n) << endl;
  return 0;
}
