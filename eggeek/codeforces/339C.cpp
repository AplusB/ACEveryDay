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
#define N 1010
vi w, ans;
int m, dp[N][11][22];

int dfs(int cur, int pre, int dif) {
  if (cur == m) return true;
  if (dp[cur][pre][dif + 10] != -1) return dp[cur][pre][dif + 10];
  //printf("cur:%d pre:%d dif:%d\n", cur, pre, dif);
  if (cur % 2 == 0) {
    for (int i: w) if (i != pre && dif + i > 0) {
      if (dfs(cur+1, i, dif + i)) {
        ans.push_back(i);
        return dp[cur][pre][dif + 10] = true;
      }
    }
  } else {
    for (int i: w) if (i != pre && dif - i < 0) {
      if (dfs(cur+1, i, dif - i)) {
        ans.push_back(i);
        return dp[cur][pre][dif + 10] = true;
      }
    }
  }
  return dp[cur][pre][dif + 10] = false;
}

int main() {
  string s;
  cin >> s >> m;
  for (int i=1; i<=10; i++) if (s[i-1] == '1') w.push_back(i);
  memset(dp, -1, sizeof(dp));
  if (dfs(0, 0, 0)) {
    printf("YES\n");
    reverse(ans.begin(), ans.end());
    for (int i=0; i<m; i++) printf("%d%c", ans[i], i+1<m?' ': '\n');
  } else printf("NO\n");
  return 0;
}
