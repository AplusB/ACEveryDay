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
#define N 1010
struct P {
  double x, y;
};
P p[N], pos[N], ans;
bool vis[N][2];
double dis[N][N];
int n;
double w;

void read() {
  for (int i=1; i<=n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    p[i] = P{(double)x, (double)y};
  }
}

void init() {
  for (int i=1; i<=n; i++) {
    for (int j=i+1; j<=n; j++) {
      double dx = p[i].x - p[j].x;
      double dy = p[i].y - p[j].y;
      dis[i][j] = dis[j][i] = sqrt(dx * dx + dy * dy);
    }
  }
}

P mid(P a, P b) {
  return P{(a.x+b.x)/2.0, (a.y+b.y)/2.0};
}

queue<pii> q;
bool check(double len) {
  for (int i=1; i<=n+1; i++) vis[i][0] = vis[i][1] = false;
  for (int i=1; i<=n; i++) pos[i] = P{w/2.0, 0};
  for (int i=1; i<=n; i++) {
    if (p[i].x <= len) {
      vis[i][0] = true;
      q.push(make_pair(i, 0));
    }
    if (p[i].x / 2.0 <= len) {
      vis[i][1] = true;
      q.push(make_pair(i, 1));
      pos[i] = P{p[i].x / 2.0, p[i].y};
    }
  }
  while (!q.empty()) {
    pii c = q.front(); q.pop();
    if (w - p[c.first].x <= len) {
      ans = pos[c.first];
      vis[n+1][c.second] = true;
      continue;
    }
    if (w - p[c.first].x <= 2.0 * len && c.second == 0) {
      ans = mid(p[c.first], P{w, p[c.first].y});
      vis[n+1][1] = true;
      continue;
    }
    for (int i=1; i<=n; i++) if (dis[c.first][i] <= len && !vis[i][c.second]) {
      vis[i][c.second] = true;
      if (c.second == 1) pos[i] = pos[c.first];
      q.push(make_pair(i, c.second));
    }
    if (c.second == 0) {
      for (int i=1; i<=n; i++) if (dis[c.first][i] / 2.0 <= len && !vis[i][1]) {
        vis[i][1] = true;
        pos[i] = mid(p[c.first], p[i]);
        q.push(make_pair(i, 1));
      }
    }
  }
  return vis[n+1][0] || vis[n+1][1];
}

void bsearch(double l, double r) {
  double eps = 1e-6;
  for (int i=0; i<30; i++) {
    double mid = (l + r) / 2.0;
    if (check(mid)) { r = mid; }
    else l = mid;
    if (r - l <= eps) break;
  }
}

int main() {
  //freopen("froggy.in", "r", stdin);
  //freopen("froggy.out", "w", stdout);
  scanf("%lf%d", &w, &n);
  read();
  init();
  bsearch(0.0, w/2.0);
  printf("%.3lf %.3lf\n", ans.x, ans.y);
  return 0;
}
