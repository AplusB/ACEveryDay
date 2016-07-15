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
#define N 2002
int n, cnt, dp[N][N];
map<string, int> h;
vi e[N];
char a[10], b[10], c[10];
string start, query;
string v[N];

void update(char* s) {
  string str(s);
  if (!h[str]) h[str] = ++cnt, v[cnt] = str;
}

int match(string& s, int idx) {
  int cur = 0;
  while (idx < SZ(query)) {
    if (cur >= SZ(s)) return idx;
    if (s[cur] == query[idx]) idx++;
    cur++;
  }
  return idx;
}

int dfs(int s, int p) {
  if ('a' <= v[s][0] && v[s][0] <= 'z') {
    return dp[s][p] = match(v[s], p);
  }
  if (dp[s][p] != -1) return dp[s][p];
  int old_p = p;
  for (int i: e[s]) {
    int tmp = p;
    p = dfs(i, p);
  }
  return dp[s][old_p] = p;
}

void do_case() {
  scanf("%d", &n);
  h.clear();
  cnt=0;
  for (int i=1; i<=3*n; i++) e[i].clear();

  for (int i=0; i<n; i++) {
    scanf("%s = %s", a, b);
    update(a);
    update(b);
    e[h[a]].push_back(h[b]);
    if ('A' <= b[0] && b[0] <= 'Z') {
      scanf(" + %s", c);
      update(c);
      e[h[a]].push_back(h[c]);
    }
  }
  cin >> start >> query;

  for (int i=1; i<=cnt; i++)
    for (int j=0; j<=SZ(query); j++) dp[i][j] = -1;

  int ans = dfs(h[start], 0);
  printf("%s\n", ans == SZ(query)?"YES": "NO");
}

int main() {
  // freopen("test.in", "r", stdin);
  int T;
  cin >> T;
  while (T--) do_case();
  return 0;
}
