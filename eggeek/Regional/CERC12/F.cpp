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
#define N 100010
typedef pair<ll, int> pli;
int n, m;
struct Edge {
  int to, c;
};
struct Point {
  ll x, y;
};
map<pii, int> h;
vector<Edge> e[N];
priority_queue<pli, vector<pli>, greater<pli>> q;
ll dis[N], X[N], Y[N];
Edge pre[N];

void dijkstra(int s, ll (&cod)[N]) {
  for (int i=1; i<=n; i++) dis[i] = -1, pre[i] = Edge{-1, -1};
  dis[s] = 0;
  q.push(make_pair(0, s));
  while (!q.empty()) {
    pli c = q.top(); q.pop();
    int u = c.second;
    for (Edge i: e[u]) {
      int v = i.to;
      if (dis[v] == -1 || dis[v] > c.first + (ll)i.c) {
        pre[v] = Edge{u, i.c};//
        dis[v] = c.first + (ll)i.c;
        q.push(make_pair(dis[v], v));
      }
    }
  }
  for (int i=1; i<=n; i++) cod[i] = dis[i];
}

ll calc_sum(vector<ll>& arr, ll v) {
  ll ans = 0;
  for (ll i: arr) {
    if (i > v) ans += i - v;
    else ans += v - i;
  }
  return ans;
}

vector<ll> x, y;
ll calc() {
  x.clear();
  y.clear();
  for (int i=1; i<=n; i++) {
    // |xi - xj| + |yi - yj| = 2 * max{|Xi - Xj|, |Yi - Yj|}
    x.push_back(X[i] - Y[i]);
    y.push_back(X[i] + Y[i]);
  }
  ll sumx = -1, sumy = -1;
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  int mid = x.size() / 2;
  if (x[mid] < -X[2] || x[mid] > X[2]) {
    ll v = -X[2];
    for (int i=0; i<mid; i++) if ((x[i] >= -X[2] && x[i] <= X[2])) v = x[i];
    ll tmp = calc_sum(x, v);
    sumx = sumx == -1? tmp: min(sumx, tmp);
    v = X[2];
    for (int i=n-1; i>mid; i--) if ((x[i] >= -X[2] && x[i] <= X[2])) v = x[i];
    tmp = calc_sum(x, v);
    sumx = min(sumx, tmp);
  } else sumx = calc_sum(x, x[mid]);

  mid = y.size() / 2;
  if (y[mid] < X[2]) {
    int v = X[2];
    for (int i=mid+1; i<n; i++) if (y[i] >= X[2]) { v = y[i]; break; }
    sumy = calc_sum(y, v);
  } else sumy = calc_sum(y, y[mid]);
  return sumx + sumy;
}

void do_case() {
  scanf("%d%d", &n, &m);
  for (int i=1; i<=n; i++) e[i].clear();
  for (int i=0; i<m; i++) {
    int u, v, c;
    scanf("%d%d%d", &u, &v, &c);
    e[u].push_back(Edge{v, c});
    e[v].push_back(Edge{u, c});
  }
  h.clear();
  dijkstra(1, X);
  dijkstra(2, Y);
  double ans = calc() / (2.0 * (double)n);
  printf("%.8lf\n", ans);
}

int main() {
//  freopen("test.in", "r", stdin);
  int cas;
  cin >> cas;
  while (cas--) do_case();
  return 0;
}
