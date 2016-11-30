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
#define N 303
int m, t, r;
vi w;
bool vis[N];
deque<int> q;

void clear(int cur) {
  while (!q.empty()) {
    if (q.front() + t - 1 < cur) q.pop_front();
    else break;
  }
}

bool check(int cur, int nxt) {
  if (nxt>= m) return false;
  if (cur + t < w[nxt]) return false;
  int cnt = (int)q.size();
  for (int d: q) if (d + t - 1 < w[nxt]) cnt--;
  return r - cnt >= w[nxt] - cur;
}

void solve() {
  int cnt = 0, nxt = 0;
  for (int i=w[0]-r; i<=300; i++) {
    if (i > 0) {
      clear(i);
      if (vis[i]) {
        if (q.size() < r) {
          printf("-1\n");
          return;
        }
        nxt++;
      }
    }
    if (check(i, nxt)) {
      //printf("time:%d lighting [%d, %d]\n", i, i+1, i+t);
      q.push_back(i+1);
      cnt++;
    }
  }
  printf("%d\n", cnt);
}

int main() {
  cin >> m >> t >> r;
  w.resize(m);
  for (int i=0; i<m; i++) cin >> w[i];
  for (int i=0; i<m; i++) vis[w[i]] = true;
  sort(ALL(w));
  solve();
  return 0;
}
