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
#define N 2001
int n, k, x, cnt[2][N];

void solve() {
  int cur=0, nxt;
  for (int i=0; i<k; i++) {
    int idx = 0;
    nxt = 1 - cur;
    for (int j=0; j<N; j++) cnt[nxt][j] = 0;
    for (int j=0; j<N; j++) if (cnt[cur][j]) {
      int num;
      if (idx % 2) num = cnt[cur][j] / 2;
      else num = (cnt[cur][j] + 1) / 2;
      cnt[nxt][j] += cnt[cur][j] - num;
      cnt[nxt][j ^ x] += num;
      idx += cnt[cur][j];
    }
    cur = nxt;
  }
  int minv=N, maxv=-1;
  for (int i=0; i<N; i++) if (cnt[cur][i]) {
    minv = min(minv, i);
    maxv = max(maxv, i);
  }
  printf("%d %d\n", maxv, minv);
}

int main() {
  scanf("%d%d%d", &n, &k, &x);
  for (int i=0; i<n; i++) {
    int a;
    scanf("%d", &a);
    cnt[0][a]++;
  }
  solve();
  return 0;
}
