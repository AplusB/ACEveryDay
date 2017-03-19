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
#define N 100010
int out[N], pre[N], n, t[N];

int go(int cur) {
  int res = 1;
  while (pre[cur] != 0 && out[pre[cur]] == 1) {
    cur = pre[cur];
    res++;
  }
  return res;
}

void print_ans(int cur, int end) {
  if (pre[cur] && out[pre[cur]] == 1) print_ans(pre[cur], end);
  printf("%d%c", cur, cur==end?'\n': ' ');
}

int main() {
  scanf("%d", &n);
  for (int i=1; i<=n; i++) scanf("%d", &t[i]);
  for (int i=1; i<=n; i++) {
    int a;
    scanf("%d", &a);
    pre[i] = a;
    out[a]++;
  }
  int maxl = 0, maxH = -1;
  for (int i=1; i<=n; i++) if (t[i]) {
    int tmp = go(i);
    if (tmp > maxl) {
      maxl = tmp;
      maxH = i;
    }
  }
  printf("%d\n", maxl);
  print_ans(maxH, maxH);
  return 0;
}
