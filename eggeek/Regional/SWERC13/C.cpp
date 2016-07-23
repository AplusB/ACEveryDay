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
#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
/*-----------------------------------*/
#define N 220
const double eps = 1e-6;
const double INF = 4e18;
struct Point {
  int x, y, z;
};
Point p[N];
double e[N][N];
vector<pair<int, double>>g[N];
int n, m, q;

double calc_dis(int u, int v) {
  Point a = p[u];
  Point b = p[v];
  double dy = (double)(p[u].y - p[v].y);
  double dz = (double)(p[u].z - p[v].z);
  double dx = fabs((double)p[u].x - (double)p[v].x) * 5.0;
  double res = sqrt(dy*dy + dz*dz + dx*dx);
  return res;
}

void update(int u, int v, double dis) { e[u][v] = min(e[u][v], dis); }

void floyd() {
  for (int k=0; k<n; k++)
    for (int i=0; i<n; i++) if (i != k)
      for (int j=0; j<n; j++) if (j != i && j != k) {
        if (fabs(e[i][k] - INF) <= eps || fabs(e[k][j] - INF) <= eps) continue;
        e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
      }
}

void print_path(vi& path) {
  for (int i=0; i<SZ(path); i++) printf("%d%c", path[i], i+1<SZ(path)?' ': '\n');
}

void find_path(int s, int t, vi& path) {
  path.push_back(s);
  if (s == t) return;
  for (auto i: g[s]) {
    double D = e[i.first][t] + i.second;
    if (fabs(e[s][t] - D) <= eps) {
      find_path(i.first, t, path);
      return;
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i=0; i<n; i++) {
    scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].z);
  }
  for (int i=0; i<n; i++) for (int j=0; j<n; j++) e[i][j] = i==j?0.0: INF;
  for (int i=0; i<m; i++) {
    int u, v;
    char s[20];
    scanf("%d%d%s", &u, &v, s);
    if (s[0] == 'w' || s[0] == 's') {
      double dis = calc_dis(u, v);
      g[u].push_back(make_pair(v, dis));
      update(u, v, dis);
      g[v].push_back(make_pair(u, dis));
      update(v, u, dis);
    } else if (s[0] == 'l') {
      g[u].push_back(make_pair(v, 1.0));
      update(u, v, 1.0);
      g[v].push_back(make_pair(u, 1.0));
      update(v, u, 1.0);
    } else if (s[0] == 'e') {
      double dis = calc_dis(u, v);
      g[u].push_back(make_pair(v, 1.0));
      update(u, v, 1.0);
      g[v].push_back(make_pair(u, 3.0*dis));
      update(v, u, 3.0 * dis);
    }
  }
  floyd();
  scanf("%d", &q);
  while (q--) {
    int u, v;
    scanf("%d%d", &u, &v);
    vi path;
    find_path(u, v, path);
    assert(!path.empty());
    print_path(path);
  }
  return 0;
}
