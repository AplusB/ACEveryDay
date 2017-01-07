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
#define N 100010
struct Leg {
  int l, d;
};
int n, cost[N], tot;
vector<Leg> l;
vector<Leg> r[N];

int main() {
  scanf("%d", &n);
  l.resize(n);
  for (int i=0; i<n; i++) scanf("%d", &l[i].l);
  for (int i=0; i<n; i++) scanf("%d", &l[i].d);
  for (int i=0; i<n; i++) cost[l[i].l] += l[i].d;
  for (int i=0; i<n; i++) tot += l[i].d;
  for (int i=0; i<n; i++) r[l[i].l].push_back(l[i]);
  multiset<int> s;
  int ans = 1e9;
  for (int i=0; i<N; i++) if (SZ(r[i])) {
    int eng = tot - cost[i];
    int most = SZ(r[i]) - 1;
    auto it = s.rbegin();
    for (int j=0; j<most && it != s.rend(); j++, it++) {
      eng -= *it;
    }
    ans = min(ans, eng);
    for (Leg x: r[i]) s.insert(x.d);
  }
  printf("%d\n", ans);
  return 0;
}
