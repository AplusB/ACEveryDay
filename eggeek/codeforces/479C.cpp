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
#define N 5001
bool vis[N];
vector<pii> rs;

struct cmp {
  bool operator() (pii x, pii y) {
    if (x.first == y.first) {
      return rs[x.second].first > rs[y.second].first;
    }
    return x.first > y.first;
  }
};

priority_queue<pii, vector<pii>, cmp> p;
priority_queue<pii, vector<pii>, cmp> q;

bool check(pii c) {
 // printf("check c(id:%d time:%d)\n", c.second, c.first);
  while (!p.empty()) {
  //  printf(" p top id: %d\n", p.top().second);
    if (vis[p.top().second]) p.pop();
    else {
  //    printf("p top: %d, c: %d\n", p.top().first, c.first);
      if (p.top().first < rs[c.second].first) return false;
      else return true;
    }
  }
  return true;
}

int main() {
  int n;
  cin >> n;
  for (int i=0; i<n; i++) {
    int a, b;
    cin >> a >> b;
    rs.push_back({a, b});
  }
  int ans = 0;

  for (int i=0; i<n; i++) {
    q.push({rs[i].second, i});
    p.push({rs[i].first, i});
  }
  while (!q.empty()) {
    pii c = q.top(); q.pop();
    vis[c.second] = true;
    if (check(c)) {
      ans = max(ans, c.first);
    } else {
      vis[c.second] = false;
      q.push({rs[c.second].first, c.second});
      p.push({rs[c.second].first, c.second});
    }
  }
  cout << ans << endl;
  return 0;
}
