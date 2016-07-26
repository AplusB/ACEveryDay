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
const double INF = 1e40;
const double eps = 1e-10;
/*-----------------------------------*/
#define N 2001
struct Node {
  int id, t;
  double w;
  void debug() { printf("id: %d, t: %d, w: %.5lf\n", id, t, w); }
};

struct Route { int from, m, t, p, d; };
vector<Route> rs[N];

struct cmp {
  bool operator() (const Node& a, const Node& b) { return a.w > b.w; }
};

map<string, int> h;
vector<string> strs;
string start, target;
int n;
double dis[N][60];

void insert(string s) {
  if (h.find(s) == h.end()) {
    h[s] = SZ(strs);
    strs.push_back(s);
  }
}

int wait(int t1, int t2) { return (60 + t2 - t1) % 60; }

void read() {
  h.clear();
  strs.clear();
  cin >> start >> target;
  insert(start);
  insert(target);
  cin >> n;
  for (int i=0; i<2*n; i++) rs[i].clear();
  for (int i=0; i<n; i++) {
    string from, to;
    int m, t, d, p;
    cin >> from >> to >> m >> t >> p >> d;
    insert(from);
    insert(to);
    int frid = h[from], toid = h[to];
    rs[toid].push_back(Route{frid, m, t, p, d});
  }
}

priority_queue<Node, vector<Node>, cmp> q;
double dijkstra(int s, int t) {
  for (int i=0; i<SZ(strs); i++)
    for (int j=0; j<60; j++) dis[i][j] = INF;
  for (int i=0; i<60; i++) dis[t][i] = 0.0;
  q.push(Node{t, 0, 0});
  while (!q.empty()) {
    Node c = q.top(); q.pop();
    if (fabs(c.w-dis[c.id][c.t]) > eps) continue;
    for (Route i: rs[c.id]) {
      int f = i.from;
      double p = (double)i.p / 100.0;
      double w = (1.0 - p) * (i.t + dis[c.id][(i.m+i.t) % 60]);
      for (int d=1; d<=i.d; d++) {
        w += p / (double)i.d * (i.t + d + dis[c.id][(i.m+i.t+d) % 60]);
      }
      if (fabs(w - dis[f][i.m]) > eps && w < dis[f][i.m]) {
        q.push(Node{f, i.m, w});
        for (int m=0; m<60; m++) dis[f][m] = min(dis[f][m], w + wait(m, i.m));
      }
    }
  }
  double ans = INF;
  for (int i=0; i<60; i++) ans = min(dis[s][i], ans);
  return ans;
}

void do_case() {
  read();
  double ans = dijkstra(h[start], h[target]);
  if (fabs(ans - INF) <= eps) printf("IMPOSSIBLE\n");
  else printf("%.6lf\n", ans);
}

int main() {
  int cas;
  cin >> cas;
  while (cas--) do_case();
  return 0;
}
