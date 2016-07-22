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
#define N 1000001
int n, m, ind[N], c[N], tmpD[N];
vi e[N];

queue<int> q[2];
int solve(int s) {
  for (int i=1; i<=n; i++) tmpD[i] = ind[i];
  for (int i=0; i<2; i++) while (!q[i].empty()) q[i].pop();
  for (int i=1; i<=n; i++) if (!tmpD[i]) q[c[i]].push(i);
  int cur = s, cnt = 0;
  while (true) {
    if (q[0].empty() && q[1].empty()) break;
    if (q[cur].empty()) {
      cur = 1 - cur;
      cnt++;
    }
    while (!q[cur].empty()) {
      int t = q[cur].front(); q[cur].pop();
      for (int i: e[t]) {
        tmpD[i]--;
        if (tmpD[i] == 0) q[c[i]].push(i);
      }
    }
  }
  return cnt;
}

void do_case() {
  scanf("%d%d", &n, &m);
  for (int i=1; i<=n; i++) e[i].clear();
  for (int i=1; i<=n; i++) ind[i] = 0;
  for (int i=1; i<=n; i++) {
    scanf("%d", &c[i]);
    c[i]--;
  }
  for (int i=0; i<m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    e[u].push_back(v);
    ind[v]++;
  }
  int ans = min(solve(0), solve(1));
  printf("%d\n", ans);
}

int main() {
  // freopen("test.in", "r", stdin);
  int T;
  cin >> T;
  while (T--) do_case();
  return 0;
}
