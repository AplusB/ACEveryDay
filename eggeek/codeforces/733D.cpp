#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) int((a).size())
#define LOWB(x) (x & (-x))
#define UNIQUE(a) sort(ALL(a)), (a).erase(unique(ALL(a)), (a).end())
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
#define N 100010
struct Node {
  int e[3],id;
  void read(int ord) {
    id = ord;
    for (int i=0; i<3; i++) scanf("%d", &e[i]);
  }
};
int n;
Node rec[N];
map<pii, set<int>> h;

set<pii> gen_sets(vi vs) {
  sort(ALL(vs));
  set<pii> res;
  for (int i=0; i<3; i++) {
    for (int j=i+1; j<3; j++) {
      res.insert({vs[i], vs[j]});
    }
  }
  return res;
}

bool cmp(pii& lhs, pii& rhs) {
  return lhs.first > rhs.first;
}

void solve() {
  for (int i=1; i<=n; i++) {
    set<pii> s = gen_sets(vi({rec[i].e[0], rec[i].e[1], rec[i].e[2]}));
    for (auto it: s) h[it].insert(i);
  }
  vi args;
  int big = -1;
  for (auto it: h) {
    pii a = it.first;
    vector<pii> ps;
    for (auto j: it.second) {
      int c = rec[j].e[0] + rec[j].e[1] + rec[j].e[2] - a.first - a.second;
      ps.push_back({c, j});
    }
    sort(ALL(ps), cmp);
    int r = min(a.first, a.second);
    if (ps.size() == 1) {
      r = min(r, ps[0].first);
      if (r > big) {
        big = r;
        args = {ps[0].second};
      }
    } else {
      int t = ps[0].first + ps[1].first;
      r = min(r, t);
      if (r > big) {
        big = r;
        args = {ps[0].second, ps[1].second};
      }
    }
  }
  printf("%d\n", (int)args.size());
  for (int i=0; i<(int)args.size(); i++) printf("%d%c", args[i], i+1<(int)args.size()?' ': '\n');
}

int main() {
  scanf("%d", &n);
  for (int i=1; i<=n; i++) rec[i].read(i);
  solve();
  return 0;
}
