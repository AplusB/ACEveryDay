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
#define N 20
int n, d[N][N], b[1<<N], h[1<<N];
int cnt[1<<N][N];
bool dp[1 << N];

void dfs(int mask) {
  if (dp[mask]) return;
  dp[mask] = true;
  if (b[mask] == 1) return;
  for (int t=mask; t; t-=LOWB(t)) {
    int i = h[LOWB(t)];
    if (cnt[mask][i] >= 0) continue;
    for (int k=mask; k; k-=LOWB(k)) {
      int j = h[LOWB(k)];
      cnt[mask-(1<<i)][j] = cnt[mask][j] + d[j][i];
    }
    dfs(mask - (1<<i));
  }
}

void do_case() {
  scanf("%d", &n);
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++) scanf("%d", &d[i][j]);

  for (int i=0; i<n; i++) cnt[(1<<n)-1][i] = 0;
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++) cnt[(1<<n)-1][i] -= d[i][j];

  for (int i=0; i<(1<<n); i++) dp[i] = false;
  dfs((1<<n)-1);
  vi ans;
  for (int i=0; i<n; i++) if (dp[1<<i]) ans.push_back(i+1);
  if (ans.empty()) printf("0\n");
  else {
    for (int i=0; i<SZ(ans); i++) printf("%d%c", ans[i], i+1<SZ(ans)?' ': '\n');
  }
}

int main() {
  // freopen("test.in", "r", stdin);
  b[0] = 0;
  for (int i=0; i<N; i++) {
    if ((i<<1) < N) b[i<<1] = b[i];
    if ((i<<1|1) < N) b[i<<1|1] = b[i]+1;
  }
  for (int i=0; i<N; i++) h[1<<i] = i;
  int cas;
  cin >> cas;
  while (cas--) do_case();
  return 0;
}
