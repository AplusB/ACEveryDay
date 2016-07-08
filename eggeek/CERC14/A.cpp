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
#define N 1001
vi e[N], sub[N];
int n, p, D[N][N], F[N][N], dp[N][1024], id[N];
bool m[N][N];

void build_graph(int rt, int pa) { // O(n^2)
  for (int i: e[rt]) if (i != pa) {
    for (int subi: sub[i]) {
      F[rt][i] = max(F[rt][i], D[i][subi] + m[rt][subi]);
    }
    //printf("rt:%d, pa:%d, F[%d][%d]=%d\n", rt, pa, rt, i, F[rt][i]);
  }

  for (int i=0; i<SZ(e[rt]); i++) if (e[rt][i] != pa) {
    int u = e[rt][i];
    for (int j=i+1; j<SZ(e[rt]); j++) if (e[rt][j] != pa) {
      int v = e[rt][j];
      for (int subu: sub[u]) {
        for (int subv: sub[v]) {
          F[u][v] = max(F[u][v], D[u][subu] + D[v][subv] + (int)m[subu][subv]);
        }
      }
      F[v][u] = F[u][v];
      //printf("F[%d][%d]=%d\n", u, v, F[u][v]);
    }
  }
}

void calc_dp(int rt, int pa, int (&id)[N]) {
  int cnt = SZ(e[rt]);
  if (pa != -1) cnt--;
  int full = (1 << cnt) - 1;
  dp[rt][0] = 0;
  for (int mask=1; mask <= full; mask++) {
    dp[rt][mask] = 0;
    for (int i: e[rt]) if (i != pa && (mask & (1 << id[i]))) {
      int maski = mask - (1 << id[i]);
      dp[rt][mask] = max(dp[rt][mask], dp[rt][maski] + F[rt][i]);
      for (int j: e[rt]) if (j != pa && (maski & (1 << id[j]))) {
        int maskij = maski - (1 << id[j]);
        dp[rt][mask] = max(dp[rt][mask], dp[rt][maskij] + F[i][j]);
      }
    }
  }
}

void dfs(int rt, int pa) {
  int cnt = 0;
  sub[rt].push_back(rt);
  for (int i: e[rt]) if (i != pa) {
    id[i] = cnt++;
    dfs(i, rt);
    sub[rt].push_back(i);
    for (int j: sub[i]) sub[rt].push_back(j);
  }
  build_graph(rt, pa); // O(n^2)
  calc_dp(rt, pa, id); // O(n * 1024)
  // O(n ^ 2)
  // T(n) = 2*T(n/2) + n^2 = O(n^2);
  int full = (1 << cnt) - 1;
  D[rt][rt] = dp[rt][full];
  for (int i: e[rt]) if (i != pa){
    for (int j: sub[i]) {
      D[rt][j] = dp[rt][full - (1 << id[i])] + D[i][j];
    }
  }
  //printf("D[%d][%d]=%d, full:%d\n", rt, rt, D[rt][rt], full);
}

void do_case() {
  int debug = -1;
  memset(m, 0, sizeof(m));
  memset(D, 0, sizeof(D));
  memset(F, 0, sizeof(F));
  memset(dp, 0, sizeof(dp));
  for (int i=1; i<=n; i++) {
    e[i].clear();
    sub[i].clear();
  }
  scanf("%d", &n);
  for (int i=1; i<n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    e[u].push_back(v);
    e[v].push_back(u);
  }
  scanf("%d", &p);
  for (int i=0; i<p; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    m[u][v] = m[v][u] = true;
  }
  dfs(1, -1);
  printf("%d\n", D[1][1]);
}

int main() {
  //freopen("all.in", "r", stdin);
  int cas;
  cin >> cas;
  for (int i=1; i<=cas; i++) do_case();
  return 0;
}
