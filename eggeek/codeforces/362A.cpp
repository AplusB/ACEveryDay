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
int dx[] = {-2, 2, 2, -2};
int dy[] = {2, 2, -2, -2};
/*-----------------------------------*/
#define N 10
char s[N][N];
int d[2][N][N];

queue<pii> q;
void bfs(int id, int r, int c) {
  d[id][r][c] = 0;
  q.push(make_pair(r, c));
  while (!q.empty()) {
    pii cur = q.front(); q.pop();
    for (int i=0; i<4; i++) {
      int nxtr = cur.first + dx[i];
      int nxtc = cur.second + dy[i];
      if (nxtr >= 0 && nxtr < 8 && nxtc >= 0 && nxtc < 8 && d[id][nxtr][nxtc] == -1) {
        d[id][nxtr][nxtc] = 1 - d[id][cur.first][cur.second];
        q.push(make_pair(nxtr, nxtc));
      }
    }
  }
}

void do_case() {
  for (int i=0; i<8; i++) scanf("%s", s[i]);
  memset(d, -1, sizeof(d));
  int cnt = 0;
  for (int i=0; i<8; i++)
    for (int j=0; j<8; j++) if (s[i][j] == 'K') {
      bfs(cnt++, i, j);
    }
  for (int i=0; i<8; i++)
    for (int j=0; j<8; j++) if (s[i][j] != '#' && d[0][i][j] != -1 && d[1][i][j] != -1) {
      if (d[0][i][j] % 2 == d[1][i][j] % 2) {
        printf("YES\n");
        return;
      }
    }
  printf("NO\n");
}

int main() {
  int cas;
  cin >> cas;
  while (cas--) do_case();
  return 0;
}
