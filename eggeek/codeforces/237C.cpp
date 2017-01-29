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
#define N 1000010
int a, b, k, prim[N], cntp, sum[N];
bool vis[N];

void init_prim() {
  for (int i=2; i<N; i++) {
    if (!vis[i]) prim[cntp++] = i;
    for (int j=0; j<cntp && (ll)prim[j] * (ll)i < N; j++) {
      vis[i * prim[j]] = true;
      if (i % prim[j] == 0) break;
    }
  }
  for (int i=2; i<N; i++) sum[i] = sum[i-1] + (!vis[i]);
}

bool check(int len) {
  //printf("check len: %d\n", len);
  for (int x=a; x <= b-len+1; x++) {
    //printf("sum[%d](%d) - sum[%d](%d) = %d\n", x+len-1, sum[x+len-1], x-1, sum[x-1], sum[x+len-1]-sum[x-1]);
    if (sum[x+len-1] - sum[x-1] < k) return false;
  }
  return true;
}

int bsearch(int l, int r) {
  int best = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      best = mid;
      r = mid - 1;
    } else l = mid + 1;
  }
  return best;
}

int main() {
  init_prim();
  cin >> a >> b >> k;
  int l = bsearch(1, b - a + 1);
  cout << l << endl;
  return 0;
}
