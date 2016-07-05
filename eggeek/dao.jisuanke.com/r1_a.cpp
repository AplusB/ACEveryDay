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
#define N 300
int n;
short g[N<<1][N][N];
ll cnt;

void update(short& c, short& u, short& v) {
  if (u == -1 || v == -1) return;
  if (c == -1 || c > u + v) c = u + v;
}

void floyd(int l, int r, int cid, int pid) {
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++) g[cid][i][j] = g[pid][i][j];

  for (int k=l; k<r; k++) {
    for (int i=0; i<n; i++) if (i != k)
      for (int j=0; j<n; j++) if (j != k && j != i) {
        update(g[cid][i][j], g[cid][i][k], g[cid][k][j]);
      }
  }
}

int dfs(int l, int r, int idx) {
  if (l+1 == r) {
    for (int i=0; i<n; i++) if (i != l)
      for (int j=0; j<n; j++) if (j != l) cnt += (ll)g[idx][i][j];
    return idx;
  }
  int rt = idx;
  int mid = (l + r) >> 1;
  if (l < mid) {
    int ls = idx + 1;
    floyd(mid, r, ls, rt);
    idx = dfs(l, mid, ls);
  }
  if (mid < r) {
    int rs = idx + 1;
    floyd(l, mid, rs, rt);
    idx = dfs(mid, r, rs);
  }
  return idx;
}

int main() {
  //freopen("test.in", "r", stdin);
  memset(g, -1, sizeof(g));
  cin >> n;
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++) scanf("%hd", &g[0][i][j]);
  cnt = 0;
  dfs(0, n, 0);
  cout << cnt << endl;
  return 0;
}
