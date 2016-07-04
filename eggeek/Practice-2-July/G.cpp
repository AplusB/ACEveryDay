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
const ll mod = 1000000007;
const double pi = acos(-1.0);
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
/*-----------------------------------*/
#define N 1001
ll F[N][N], f[2][N][N], C[N][N], A[N], ans[N][N];

void init() {
  A[0] = 1ll;
  for (int i=1; i<N; i++) A[i] = A[i-1] * (ll)i % mod;
  for (int i=0; i<N; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j=1; j<i; j++)
      C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
  }

  int cur, pre;
  for (int i=0; i<N; i++) {
    for (int j=0; j<=i; j++)
      f[1][i][j] = 1;
    F[1][i] = f[1][i][i];
  }
  for (int i=2; i<=50; i++) {
    cur = i % 2;
    pre = 1 - cur;
    for (int j=0; j<N; j++) {
      for (int k=0; k<N; k++) {
        f[cur][j][k] = 0;
        if (j-1 >= 0) f[cur][j][k] += f[cur][j-1][k];
        if (j-1 >= 0 && k-j >= 0) f[cur][j][k] += f[pre][j-1][k-j];
        if (f[cur][j][k] >= mod) f[cur][j][k] %= mod;
      }
      for (int j=0; j<N; j++) F[i][j] = f[cur][j][j];
    }
  }

  for (int i=1; i<N; i++)
    for (int j=1; j<N; j++) {
      F[i][j] = F[i][j] * A[i];
      if (F[i][j] >= mod) F[i][j] %= mod;
    }
}

void do_case() {
  int n, k;
  scanf("%d%d", &n, &k);
  ll ans = 0;
  for (int sum=0; sum < n; sum++) {
    ll tmp = F[k][sum] * C[n-sum][k];
    if (tmp >= mod) tmp %= mod;
    ans += tmp;
    if (ans >= mod) ans %= mod;
  }
  printf("%d\n", (int)ans);
}
int main() {
  init();
  int cas;
  cin >> cas;
  while (cas--) do_case();
  return 0;
}
