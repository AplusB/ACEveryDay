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
const double pi = acos(-1.0);
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
/*-----------------------------------*/
#define N 1000010
int n, m, p[N], ans[N];
vi e[N];
bool vis[N], used[N];

void dfs(int c, vi& pos, vi& val) {
  vis[c] = true;
  pos.push_back(c);
  val.push_back(p[c]);
  for (int i: e[c]) if (!vis[i]) dfs(i, pos, val);
}

void do_case() {
  for (int i=1; i<=n; i++) scanf("%d", &p[i]);
  for (int i=1; i<=n; i++) e[i].clear();
  for (int i=0; i<m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    e[u].push_back(v);
    e[v].push_back(u);
  }
  for (int i=1; i<=n; i++) vis[i] = false;
  for (int i=1; i<=n; i++) if (!vis[i]) {
    vi pos, val;
    dfs(i, pos, val);
    sort(pos.begin(), pos.end());
    sort(val.begin(), val.end());
    int it = SZ(val) - 1;
    for (int j=0; j<SZ(pos); j++) {
      ans[pos[j]] = val[it--];
    }
  }
  for (int i=1; i<=n; i++) printf("%d%c", ans[i], i+1<=n?' ': '\n');
}

int main() {
  // freopen("test.in", "r", stdin);
  while (cin >> n >> m) do_case();
  return 0;
}
