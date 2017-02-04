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
#define N 200010
int n, m, a[N], r[N], t[N];

bool overlap(int pi, int pj) {
  if (r[pi] <= r[pj]) return true;
  return false;
}

void print_ans(vi ans) {
  for (int i=0; i<SZ(ans); i++) printf("%d%c", ans[i], i+1<SZ(ans)?' ': '\n');
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i=1; i<=n; i++) scanf("%d", &a[i]);
  for (int i=1; i<=m; i++) scanf("%d%d", &t[i], &r[i]);
  vi idxes;
  vi ans;
  for (int i=1; i<=m; i++) {
    while (!idxes.empty() && overlap(idxes.back(), i)) idxes.pop_back();
    if (!idxes.empty() && t[idxes.back()] == t[i]) continue;
    idxes.push_back(i);
  }
  int pl, pr, d;
  if (t[idxes[0]] == 1) {
    sort(a+1, a+1+r[idxes[0]]);
    pl = 1, pr = r[idxes[0]], d = 1;
  }
  else {
    sort(a+1, a+1+r[idxes[0]]);
    pr = r[idxes[0]], pl = 1, d = -1;
  }
  for (int i=n; i>pr; i--) ans.push_back(a[i]);

  //print_ans(ans);
  //printf("idxes: ");
  //print_ans(idxes);
  for (int i=1; i<SZ(idxes); i++) {
    int id = idxes[i];
    int num = (pr - pl + 1) - r[id];
    //printf("r[%d]: %d, r[%d]: %d\n", id, r[id], idxes[i-1], r[idxes[i-1]]);
    assert(r[id] <= r[idxes[i-1]]);
    //printf("pl: %d, pr: %d, d: %d, num: %d\n", pl, pr, d, num);
    if (d == 1) {
      for (int j=0; j<num; j++) ans.push_back(a[pr - j]);
      pr -= num;
      d = t[id] == 1? 1: -1;
    } else {
      for (int j=0; j<num; j++) ans.push_back(a[pl + j]);
      pl += num;
      d = t[id] == 1? 1: -1;
    }
    //print_ans(ans);
  }
  if (d == 1) {
    for (int j=pr; j>=pl; j--) ans.push_back(a[j]);
  } else {
    for (int j=pl; j<=pr; j++) ans.push_back(a[j]);
  }
  reverse(ALL(ans));
  print_ans(ans);
  assert(SZ(ans) == n);
  return 0;
}
