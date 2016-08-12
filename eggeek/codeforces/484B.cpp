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
#define N 1000001
int n, lg[N];
int exist[N][21];
vi a;
set<int> sa;

void init() {
  sa = set<int>(a.begin(), a.end());
  memset(exist, 0, sizeof(exist));
  for (int i: a) exist[i][0] = i;
  for (int k=1; (1<<k) < N; k++) {
    for (int i=0; i<N; i++) {
      if (i + (1<<(k-1)) < N)
        exist[i][k] = max(exist[i][k-1],  exist[i+(1<<(k-1))][k-1]);
      else
        exist[i][k] = exist[i][k-1];
    }
  }
  lg[0] = 0;
  for (int i=1; i<N; i++) {
    int tmp = i;
    while (tmp >> 1) {
      lg[i]++;
      tmp >>= 1;
    }
  }
}

int query(int l, int r) {
  int len = r - l + 1;
  assert(len > 0);
  return max(exist[l][lg[len]], exist[r - (1<<lg[len]) + 1][lg[len]]);
}

int solve() {
  int ans = 0;
  for (int i: sa) if (i > 1) {
    int v = i;
    while (v < N-1) {
      int x = query(v+1, min(v+i-1, N-1));
      ans = max(ans, x % i);
      v += i;
    }
  }
  return ans;
}

int main() {
  cin >> n;
  for (int i=0; i<n; i++) {
    int x;
    scanf("%d", &x);
    a.push_back(x);
  }
  init();
  int ans = solve();
  printf("%d\n", ans);
  return 0;
}
