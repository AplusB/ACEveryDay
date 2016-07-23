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
#define N 10001
struct G {
  int x0, a, b, c;
};
G g[N];
vi num[N];
bool vis[1001];
int n, k;

void gen(G c, vi& seq) {
  memset(vis, false, sizeof(vis));
  int  x = c.x0;
  while (!vis[x]) {
    vis[x] = true;
    seq.push_back(x);
    x = (c.a * x + c.b) % c.c;
  }
}

int find_max_id(vi& seq) {
  int ans = -1, id = -1;
  for (int i=0; i<SZ(seq); i++) if (seq[i] > ans) {
    ans = seq[i];
    id = i;
  }
  return id;
}

void print_ans(int ans, vi idxs) {
  printf("%d\n", ans);
  for (int i=0; i<SZ(idxs); i++) printf("%d%c", idxs[i], i+1<SZ(idxs)?' ': '\n');
}

int main() {
  //freopen("generators.in", "r", stdin);
  //freopen("generators.out", "w", stdout);
  scanf("%d%d", &n, &k);
  for (int i=0; i<n; i++) {
    scanf("%d%d%d%d", &g[i].x0, &g[i].a, &g[i].b, &g[i].c);
  }
  for (int i=0; i<n; i++) {
    num[i].clear();
    gen(g[i], num[i]);
  }
  int ans = 0;
  vi t;
  for (int i=0; i<n; i++) {
    int idx = find_max_id(num[i]);
    ans += num[i][idx];
    t.push_back(idx);
  }
  if (ans % k == 0) {
    int tmpans = -1;
    int tmpn = -1;
    int tmpidx = -1;
    for (int i=0; i<n; i++) {
      for (int j=0; j<SZ(num[i]); j++) {
        int tmp = ans - num[i][t[i]] + num[i][j];
        if (tmp % k && tmp > tmpans) {
          tmpans = tmp;
          tmpn = i;
          tmpidx = j;
        }
      }
    }
    if (tmpans == -1) printf("-1\n");
    else {
      ans = tmpans;
      t[tmpn] = tmpidx;
      print_ans(ans, t);
    }
  } else print_ans(ans, t);
  return 0;
}
