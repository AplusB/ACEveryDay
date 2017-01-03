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
#include <stack>
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
const ll mod = 1e9+7;
int n, cost[N], m, minCost[N], cnt[N], flag[N];
int disc, idx[N], low_index[N], in_stack[N];
stack<int> S;
vector<vi> g;

void tarjan(int u) {
  idx[u] = low_index[u] = ++disc;
  in_stack[u] = 1;
  S.push(u);
  for (int i=0; i<g[u].size(); i++) {
    int v = g[u][i];
    if (idx[v] == -1) {
      tarjan(v);
      low_index[u] = min(low_index[v], low_index[u]);
    } else if (in_stack[v] == 1) {
      low_index[u] = min(low_index[u], idx[v]);
    }
  }
  if (idx[u] == low_index[u]) {

    while (!S.empty() && idx[u] <= low_index[S.top()]) {
      flag[S.top()] = u;
      in_stack[S.top()] = 0;
      S.pop();
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i=1; i<=n; i++) scanf("%d", &cost[i]);
  for (int i=1; i<=n; i++) flag[i] = i;
  scanf("%d", &m);
  g.resize(n+1);
  for (int i=0; i<m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
  }
  disc = 0;
  memset(idx, -1, sizeof(idx));
  memset(minCost, -1, sizeof(minCost));
  memset(cnt, 0, sizeof(cnt));
  for (int i=1; i<=n; i++) if (idx[i] == -1) tarjan(i);
  ll tot = 0, mul = 1;
  for (int i=1; i<=n; i++) {
    minCost[flag[i]] = minCost[flag[i]] == -1? cost[i]: min(cost[i], minCost[flag[i]]);
  }
  for (int i=1; i<=n; i++) if (minCost[flag[i]] == cost[i]) cnt[flag[i]]++;
  for (int i=1; i<=n; i++) {
    if (flag[i] != i) continue;
    tot += (ll)minCost[flag[i]];
    mul = mul * cnt[flag[i]] % mod;
  }
  cout << tot << " " << mul << endl;
  return 0;
}
