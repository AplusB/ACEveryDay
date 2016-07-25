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
/*-----------------------------------*/
#define N 250001
const double EPS = 1e-6;
struct P {
  double x, y;
  P() {};
  P(double a, double b): x(a), y(b) {}
  void read() {
    cin >> x >> y;
  }
  double add(double a, double b) {
    if (fabs(a + b) < EPS * (abs(a) + abs(b))) return 0;
    return a + b;
  }
  P operator + (P p) { return P(add(x,p.x), add(y,p.y)); }
  P operator - (P p) { return P(add(x,-p.x), add(y,-p.y)); }
  P operator * (double d) { return P(x*d, y*d); }
  double dot(P p) { return add(x*p.x, y*p.y); }
  double det(P p) { return add(x*p.y, -y*p.x); }
};

bool on_seg(P p1, P p2, P q) {
  return (p1 - q).det(p2 - q) == 0 && (p1 - q).dot(p2 - q) <= 0;
}

P intersection(P p1, P p2, P q1, P q2) {
  return p1 + (p2 - p1) * ((q2 - q1).det(q1 - p1) / (q2 - q1).det(p2 - p1));
}

bool is_intersect_on_seg(P p1, P p2, P q1, P q2) {
  if (fabs((p1 - p2).det(q1 - q2)) > EPS) {
    P p = intersection(p1, p2, q1, q2);
    return on_seg(p1, p2, p) && on_seg(q1, q2, p);
  }
  if (on_seg(p1, p2, q1) ||
      on_seg(p1, p2, q2) ||
      on_seg(q1, q2, p1) ||
      on_seg(q1, q2, p2)) return true;
  return false;
}

P sen[N], pr[N];
map<pii, int> h;
pair<P, P> wall[11];
int s, r, w, pn;

void read() {
  cin >> s >> r >> w >> pn;
  h.clear();
  for (int i=0; i<s; i++) {
    int x, y;
    cin >> x >> y;
    h[make_pair(x, y)] = i;
    sen[i] = P((double)x, (double)y);
  }
  for (int i=0; i<w; i++) {
    wall[i].first.read();
    wall[i].second.read();
  }
  for (int i=0; i<pn; i++) pr[i].read();
}

void print_covers(vector<P>& ps) {
  printf("%d", SZ(ps));
  for (int i=0; i<SZ(ps); i++) {
    printf(" (%d,%d)", (int)ps[i].x, (int)ps[i].y);
  }
  printf("\n");
}

bool check(P ss, P p) {
  double dx = (ss.x - p.x);
  double dy = (ss.y - p.y);
  double dis = sqrt(dx*dx + dy*dy);
  if ((double)r < dis) return false;
  int cnt = 0;
  for (int i=0; i<w; i++)
    if (is_intersect_on_seg(p, ss, wall[i].first, wall[i].second)) cnt++;
  if ((double)(r - cnt) < dis) return false;
  return true;
}

void find_covers(vector<P>& cs, P p) {
  for (int x=-r; x<=r; x++) {
    for (int y=-r; y<=r; y++) {
      pii tmp = make_pair(p.x + x, p.y + y);
      if (h.find(tmp) != h.end()) {
        int sid = h[tmp];
        if (check(sen[sid], p)) cs.push_back(sen[sid]);
      }
    }
  }
}

void do_case() {
  read();
  vector<P> covers;
  for (int i=0; i<pn; i++) {
    covers.clear();
    find_covers(covers, pr[i]);
    print_covers(covers);
  }
}

int main() {
  int cas;
  cin >> cas;
  while (cas--) do_case();
  return 0;
}
