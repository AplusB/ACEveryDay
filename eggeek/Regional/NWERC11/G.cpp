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
const double INF = 1e18;
const double eps = 1e-3;
/*-----------------------------------*/
#define N 101
struct P {
  string name;
  int id;
  double x, y;
  void read() {
    cin >> name >> x >> y;
  }
};
P p[N];
map<string, int> h;
double d[N][N];
vector<pair<int, double>> e[N];
int n, m, ind[N];
bool vis[N];

double dis(P a, P b) {
  double dx = a.x - b.x;
  double dy = a.y - b.y;
  return sqrt(dx*dx + dy*dy);
}

void read_word(string s) {
  string w;
  cin >> w;
  assert(s == w);
}

void add_edge(int u, int v, double w) {
  //printf("add edge from %d to %d, w:%.4lf\n", u, v, w);
  d[u][v] = min(d[u][v], w);
}

void read() {
  scanf("%d%d", &n, &m);
  h.clear();
  for (int i=0; i<n; i++) {
    p[i].read();
    h[p[i].name] = i;
    p[i].id = i;
  }

  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++) d[i][j] = i == j?eps: INF;
  for (int i=0; i<n; i++) e[i].clear();
  for (int i=0; i<n; i++) ind[i] = 0;
  for (int i=0; i<n; i++) vis[i] = false;

  for (int i=0; i<m; i++) {
    string a, b, c;
    cin >> a;
    read_word("heard");
    cin >> b;
    read_word("firing");
    read_word("before");
    cin >> c;
    int ida = h[a], idb = h[b], idc = h[c];
    double Dac = dis(p[ida], p[idc]);
    double Dab = dis(p[ida], p[idb]);
    add_edge(idb, idc, Dac - Dab);
    vis[idb] = vis[idc] = true;
  }
}

bool floyd() {
  for (int k=0; k<n; k++)
    for (int i=0; i<n; i++)
      for (int j=0; j<n; j++) {
        if (fabs(d[i][k] - INF) < eps ||
            fabs(d[k][j] - INF) < eps) continue;
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
  for (int i=0; i<n; i++) if (d[i][i] < 0) return false;
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++) if (i != j && d[i][j] < 0) {
      //printf("add edge from %d to %d, w:%.6lf\n",i, j, d[i][j]);
      e[i].push_back(make_pair(j, d[i][j]));
      ind[j]++;
    }
  return true;
}

queue<int> q;
vi t_sort() {
  vi res;
  while (!q.empty()) q.pop();
  for (int i=0; i<n; i++) if (vis[i] && ind[i] == 0) { q.push(i); }
  while (!q.empty()) {
    if (q.size() > 1) {
      res.clear();
      return res;
    }
    int c = q.front(); q.pop();
    res.push_back(c);
    for (auto i: e[c]) {
      ind[i.first]--;
      if (ind[i.first] == 0) { q.push(i.first); }
    }
  }
  return res;
}
void do_case() {
  read();
  if (!floyd()) { // negative cyc
    printf("IMPOSSIBLE\n");
    return;
  }
  vi path = t_sort();
  if (SZ(path)) {
    for (int i=0; i<SZ(path); i++) {
      printf("%s%c", p[path[i]].name.c_str(), i+1<SZ(path)?' ': '\n');
    }
    return;
  } else {
    printf("UNKNOWN\n");
    return;
  }
}

int main() {
  int cas;
  cin >> cas;
  while (cas--) do_case();
  return 0;
}
