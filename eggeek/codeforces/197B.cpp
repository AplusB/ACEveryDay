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
#define N 101
int n, m, pa[N], pb[N];

void solve() {
  for (int i=100; i>=0; i--) {
    if (pa[i] == 0 && pb[i] == 0) continue;
    else if (pa[i] == 0) {
      printf("0/1\n");
      return;
    }
    else if (pb[i] == 0) {
      int f=0;
      for (int j=i; j>=0; j--) if (pb[j] != 0) {
        f = pb[j];
        break;
      }
      if (f >= 0) printf(pa[i]>0?"Infinity\n": "-Infinity\n");
      else printf(pa[i]<0?"Infinity\n": "-Infinity\n");
      return;
    }
    else {
      int g = __gcd(abs(pa[i]), abs(pb[i]));
      if (pa[i] * pb[i] < 0) printf("-%d/%d\n", abs(pa[i]) / g, abs(pb[i]) / g);
      else printf("%d/%d\n", abs(pa[i]) / g, abs(pb[i])/ g);
      return;
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i=n; i>=0; i--) scanf("%d", &pa[i]);
  for (int i=m; i>=0; i--) scanf("%d", &pb[i]);
  solve();
  return 0;
}
