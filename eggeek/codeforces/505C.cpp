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
#include <unordered_map>
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
#define N 30001
int n, d, cnt[N], sum[N];
int dp[N][610], offset;

int dfs(int cur, int l) {
  int j = d - l + 300;
  if (dp[cur][j] != -1) return dp[cur][j];
  if (sum[cur] == sum[N-1]) return dp[cur][j] = cnt[cur];
  int tmp1 = 0, tmp2 = 0, tmp3 = 0;
  //printf("cur:%d l:%d sz: %d\n", cur, l, (int)h.size());
  if (l <= 2) {
    if (cur+1 < N) tmp1 = dfs(cur+1, 1);
  }
  else if (l == 3) {
    if (cur+2 < N) tmp1 = dfs(cur+2, 2);
  }
  else {
    if (l-1 > 0 && cur+l-1 < N) tmp1 = dfs(cur+l-1, l-1);
    if (cur+l+1 < N) tmp3 = dfs(cur+l+1, l+1);
    if (cur+l < N) tmp2 = dfs(cur+l, l);
  }
  int inc = max(max(tmp1, tmp2), tmp3);
  return dp[cur][j] = cnt[cur] + inc;
}


int main() {
  scanf("%d%d", &n, &d);
  memset(cnt, 0, sizeof(cnt));
  memset(dp, -1, sizeof(dp));
  for (int i=0; i<n; i++) {
    int p;
    scanf("%d", &p);
    cnt[p]++;
  }
  for (int i=1; i<N; i++) sum[i] = sum[i-1] + cnt[i];
  printf("%d\n", dfs(d, d) + cnt[0]);
  return 0;
}
