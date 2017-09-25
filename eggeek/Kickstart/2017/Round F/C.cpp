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
int n, m, d[N][N], P;
double tmp1[N][N], tmp2[N][N], tmp3[N][N], e0[N][N], e[N][N], p[N][N], p0[N][N];

void floyd() {
  for (int k=1; k<=n; k++) {
    for (int i=1; i<=n; i++) if (i != k && d[i][k] != -1) {
      for (int j=1; j<=n; j++) if (j != i && j != k && d[j][k] != -1) {
        d[i][j] = d[i][j] == -1? d[i][k] + d[k][j]: min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

void add(double (&a)[N][N], double (&b)[N][N], double (&ans)[N][N]) {
  for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++) ans[i][j] = a[i][j] + b[i][j];
}

void mult(double (&a)[N][N], double (&b)[N][N], double (&ans)[N][N], double (&tmp)[N][N]) {
  memset(tmp, 0, sizeof(tmp));
  for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
      for (int k=1; k<=n; k++)
        tmp[i][j] += a[i][k] * b[k][j];
  for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++) ans[i][j] = tmp[i][j];
}

void print_arr(double (&a)[N][N], string header) {
  printf("%s\n", header.c_str());
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=n; j++) printf("%.4lf ", a[i][j]);
    printf("\n");
  }
  printf("----------\n");
}

void calc() {
  for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++) {
      e[i][j] = i == j?0.0: (double)d[i][j] * 1.0 / (n - 1.0);
      e0[i][j] = e[i][j];
      p[i][j] = i == j?0.0: 1.0 / (n - 1.0);
      p0[i][j] = p[i][j];
    }
  int cntb = 0;
  while ((1 << (cntb+1)) <= P) cntb++;
  int v = 1;
  for (int i=cntb-1; i>=0; i--) {
    v <<= 1;
    mult(e, p, tmp1, tmp2);
    mult(p, e, tmp2, tmp3);
    add(tmp1, tmp2, e);
    mult(p, p, p, tmp2);

    if (P & (1<<i)) {
      v |= 1;
      mult(e, p0, e, tmp1);
      mult(p, e0, tmp1, tmp2);
      add(e, tmp1, e);
      mult(p, p0, p, tmp1);
    }
  }
}


double solve() {
  cin >> n >> m >> P;
  memset(d, -1, sizeof(d));
  for (int i=0; i<m; i++) {
    int u, v, di;
    cin >> u >> v >> di;
    d[u][v] = d[v][u] = di;
  }
  floyd();
  calc();
  double tot = 0.0;
  for (int i=1; i<=n; i++) tot += e[1][i];
  return tot;
}

int main() {
  int cas;
  cin >> cas;
  for (int i=1; i<=cas; i++) {
    double ans = solve();
    printf("Case #%d: %.6lf\n", i, ans);
  }
  return 0;
}
