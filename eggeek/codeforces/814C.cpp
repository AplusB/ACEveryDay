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
#define N 1501
int f[N][N][27], g[N][27], n, q;
char s[N];

void update(int& v1, int v2) {
  if (v1 <= v2) v1 = v2;
}

void init() {
  memset(f, -1, sizeof(f));
  memset(g, -1, sizeof(g));
  for (int c=0; c<26; c++) {
    for (int i=0; i<n; i++) {
      if (s[i]-'a' == c) {
        f[i][0][c] = i>0?f[i-1][0][c] + 1: 1;
      } else f[i][0][c] = 0;
      f[i][1][c] = i>0?f[i-1][0][c] + 1: 1;
      for (int j=1; j<=i+1; j++) {
        if (i-1>=0 && (s[i]-'a') == c) {
          update(f[i][j][c], f[i-1][j][c] + 1);
        }
        if (i-1 >= 0) update(f[i][j][c], f[i-1][j-1][c] + 1);
      }
    }
  }
  for (int j=0; j<=n; j++) {
    for (int c=0; c<26; c++) {
      for (int i=0; i<n; i++) g[j][c] = max(g[j][c], f[i][j][c]);
    }
  }
}

int main() {
  scanf("%d%s", &n, s);
  init();
  scanf("%d", &q);
  for (int i=0; i<q; i++) {
    int m;
    char t[2];
    scanf("%d%s", &m, t);
    cout << g[m][t[0]-'a'] << endl;
  }
  return 0;
}
