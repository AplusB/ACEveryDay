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
#define N 1001
int n, m, r[N], c[N], tot;
char s[N][N];

void do_case() {
  for (int i=0; i<n; i++) scanf("%s", s[i]);
  memset(r, 0, sizeof(r));
  memset(c, 0, sizeof(c));
  tot = 0;
  for (int i=0; i<n; i++)
    for (int j=0; j<m; j++) if (s[i][j] == '*') {
      r[i]++;
      c[j]++;
      tot++;
    }

  for (int i=0; i<n; i++)
    for (int j=0; j<m; j++) {
      if (r[i] + c[j] - (s[i][j]=='*') == tot) {
        printf("YES\n");
        printf("%d %d\n", i+1, j+1);
        return;
      }
    }
  printf("NO\n");
}

int main() {
  while (cin >> n >> m) do_case();
  return 0;
}
