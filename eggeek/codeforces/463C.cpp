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
#define N 2020
int n, a[N][N];
ll sum[N][N][2];

int main() {
  scanf("%d", &n);
  for (int i=0; i<n; i++) for (int j=0; j<n; j++) scanf("%d", &a[i][j]);
  for (int i=0; i<n; i++) {
    ll tmp = 0;
    for (int j=0; j<n; j++) if (i-j >= 0) {
      tmp += a[j][i-j];
    }
    for (int j=0; j<n; j++) if (i-j >= 0) {
      sum[j][i-j][0] = tmp;
    }
    tmp = 0;
    for (int j=0; j<n; j++) if (i+j < n) {
      tmp += a[j][i+j];
    }
    for (int j=0; j<n; j++) if (i+j < n) {
      sum[j][i+j][1] = tmp;
    }
  }
  for (int i=1; i<n; i++) {
    ll tmp = 0;
    for (int j=0; j<n; j++) if (i+j < n) {
      tmp += a[i+j][j];
    }
    for (int j=0; j<n; j++) if (i+j < n) {
      sum[i+j][j][1] = tmp;
    }
    tmp = 0;
    for (int j=0; j<n; j++) if (i+j < n && n-1-j >= 0) {
      tmp += a[i+j][n-1-j];
    }
    for (int j=0; j<n; j++) if (i+j < n && n-1-j >= 0) {
      sum[i+j][n-1-j][0] = tmp;
    }
  }
  ll even = -1, odd = -1;
  int x0, y0, x1, y1;
  x0 = y0 = x1 = y1 = -1;
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      ll tmp = sum[i][j][0] + sum[i][j][1] - a[i][j];
      //printf("sum[%d][%d][0]=%lld, sum[%d][%d][1]=%lld\n", i+1, j+1, sum[i][j][0], i+1, j+1, sum[i][j][1]);
      //printf("(%d, %d) %s sum:%lld\n", i+1, j+1, (i+j)%2?"odd": "even", tmp);
      if ((i+j) % 2) {
        if (tmp > odd) {
          odd = tmp;
          x0 = i, y0 = j;
        }
      } else {
        if (tmp > even) {
          even = tmp;
          x1 = i, y1 = j;
        }
      }
    }
  }
  cout << even + odd << endl;
  printf("%d %d %d %d\n", x0+1, y0+1, x1+1, y1+1);
  return 0;
}
