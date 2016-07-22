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
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
/*-----------------------------------*/
#define N 10010
int a[N], n, idx[N];
vector<pii> ans;

void read() {
  scanf("%d", &n);
  for (int i=1; i<=n; i++) {
    scanf("%d", &a[i]);
    idx[a[i]] = i;
  }
}

void swap_range(int l, int r) {
  int len = (r - l + 1) / 2;
  ans.push_back(make_pair(l, r));
  for (int i=0; i<len; i++) {
    int x = l + i;
    int y = l + len + i;
    swap(a[x], a[y]);
    idx[a[x]] = x;
    idx[a[y]] = y;
  }
}

void do_case() {
  read();
  ans.clear();
  for (int i=1; i<=n; i++) {
    int mid = (i + n) >> 1;
    if (idx[i] > mid) {
      int len = idx[i] - mid;
      swap_range(mid-len+1, idx[i]);
    }
    // idx[i] in [i, mid]
    if (idx[i] != i) {
      int len = idx[i] - i;
      swap_range(i, idx[i]+len-1);
    }
  }
  printf("%d\n", (int)ans.size());
  for (pii i: ans) printf("%d %d\n", i.first, i.second);
}

int main() {
  int T;
  cin >> T;
  while (T--) do_case();
  return 0;
}
