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
const int INF = 1e9 + 2;
const ll INF_LL = 4e18;
const double pi = acos(-1.0);
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
/*-----------------------------------*/
#define N 200010
struct Point {
  int x, y;
};

struct Query {
  int l, r, y;
};
vector<Query> q;
vector<Point> p[N];
Point s[N];
vi nums;
vi bit;
map<int, int> h;
int n, k;

bool cmpx(Point a, Point b) {
  if (a.x == b.x) return a.y < b.y;
  return a.x < b.x;
}

bool cmpy(Query a, Query b) { return a.y < b.y; }
bool p_cmpy(Point a, Point b) { return a.y < b.y; }

void gen_query(const vector<Point>& c) {
  int rhs = 0;
  s[rhs++] = Point{0, 0};
  for (int i=0; i<SZ(c); i++) {
    int minY = INF;
    for (int j=rhs-1; j>=0; j--) {
      if (c[i].y <= s[j].y) {
        q.push_back(Query{s[j].x+1, c[i].x-1, minY});
        minY = s[j].y - 1;
      } else {
        q.push_back(Query{s[j].x+1, c[i].x-1, minY});
        q.push_back(Query{s[j].x+1, c[i].x, c[i].y-1});
        rhs = j+1;
        break;
      }
    }
    s[rhs++] = c[i];
  }
  Point r = Point{INF, 0};
  int minY = INF;
  for (int j=rhs-1; j>=0; j--) {
    q.push_back(Query{s[j].x+1, r.x-1, minY});
    minY = s[j].y-1;
  }
}

void process() {
  for (Query i: q) {
    nums.push_back(i.l);
    nums.push_back(i.r);
  }
  UNIQUE(nums);
  h.clear();
  for (int i=0; i<nums.size(); i++) {
      h[nums[i]] = i + 1;
  }
}

void insert(int pos) {
  while (pos <= nums.size()) {
    bit[pos] += 1;
    pos += LOWB(pos);
  }
}

int prefix(int pos) {
  if (pos < 0) return 0;
  int res = 0;
  while (pos) {
    res += bit[pos];
    pos -= LOWB(pos);
  }
  return res;
}

int query(int l, int r) {
  if (l > r) return 0;
  return prefix(r) - prefix(l-1);
}

Point tot[N];
void answer() {
  int idx = 0;
  for (int i=1; i<=k; i++) {
    for (Point j: p[i]) tot[idx++] = j;
  }
  sort(tot, tot+n, p_cmpy);
  sort(q.begin(), q.end(), cmpy);
  bit.resize(nums.size() + 1);
  for (int i=0; i<SZ(bit); i++) bit[i] = 0;

  idx = 0;
  int ans = 1;
  for (Query i: q) {
    while (idx < n && tot[idx].y <= i.y) insert(h[tot[idx++].x]);
    ans = max(ans, query(h[i.l], h[i.r]));
  }
  printf("%d\n", ans);
}

void do_case() {
  scanf("%d%d", &n, &k);
  q.clear();
  nums.clear();
  bit.clear();
  for (int i=1; i<=k; i++) p[i].clear();

  for (int i=0; i<n; i++) {
    int x, y, c;
    scanf("%d%d%d", &x, &y, &c);
    p[c].push_back(Point{x, y});
  }
  for (int i=1; i<=k; i++) sort(p[i].begin(), p[i].end(), cmpx);
  for (int i=1; i<=k; i++) gen_query(p[i]);
  process();
  answer();
}

int main() {
  int cas;
  cin >> cas;
  while (cas--) do_case();
  return 0;
}
