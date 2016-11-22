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
#define N (1<<17)
int n, d[N], s[N];
struct cmp {
  bool operator() (const pii a, const pii b) { return a.second > b.second; }
};
priority_queue<pii, vector<pii>, cmp> q;
int main() {
  scanf("%d", &n);
  for (int i=0; i<n; i++) scanf("%d%d", &d[i], &s[i]);
  for (int i=0; i<n; i++) if (d[i] == 1) q.push({i, d[i]});
  vector<pii> ans;
  while (!q.empty()) {
    pii c = q.top(); q.pop();
    if (d[c.first] != c.second) continue;
 //   printf("id:%d dgr:%d sum:%d\n", c.first, d[c.first], s[c.first]);
    ans.push_back({c.first, s[c.first]});
    int v = s[c.first];
    d[v] --;
    s[v] ^= c.first;
    if (d[v] == 1) {
      q.push({v, d[v]});
    }
  }
  printf("%d\n", (int)ans.size());
  for (pii i: ans) printf("%d %d\n", i.first, i.second);
  return 0;
}
