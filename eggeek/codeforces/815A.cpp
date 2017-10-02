#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) int((a).size())
#define LOWB(x) (x & (-x))
#define UNIQUE(a) sort(ALL(a)), (a).erase(unique(ALL(a)), (a).end())
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
#define N 110
int n, m, g[N][N], row[N], col[N];

int f(int v) {
  int res = 0;
  row[1] = v;
  for (int i=1; i<=m; i++) {
    col[i] = g[1][i] - row[1];
    if (col[i] < 0) return -1;
  }
  for (int i=2; i<=n; i++) {
    row[i] = g[i][1] - col[1];
    if (row[i] < 0) return -1;
  }
  for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++) if (row[i] + col[j] != g[i][j]) return -1;
  for (int i=1; i<=n; i++) res += row[i];
  for (int i=1; i<=m; i++) res += col[i];
  return res;
}

pii solve() {
  int res = -1, argv;
  for (int i=0; i<=g[1][1]; i++) {
    int tmp = f(i);
    if (res == -1) {
      res = tmp;
      argv = i;
    } else if (tmp != -1 && res > tmp) {
      res = tmp;
      argv = i;
    }
  }
  return {res, argv};
}

int main() {
  cin >> n >> m;
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=m; j++) cin >> g[i][j];
  }
  pii res = solve();
  if (res.first == -1) cout << -1 << endl;
  else {
    cout << res.first << endl;
    f(res.second);
    for (int i=1; i<=n; i++) {
      for (int j=1; j<=row[i]; j++) cout << "row " << i << endl;
    }
    for (int i=1; i<=m; i++) {
      for (int j=1; j<=col[i]; j++) cout << "col " << i << endl;
    }
  }
  return 0;
}
