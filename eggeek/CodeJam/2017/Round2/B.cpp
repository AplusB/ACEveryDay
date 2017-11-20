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
#define N 1010
int n, c, m, cntB[N], cntP[N], p[N], b[N];

void read() {
  cin >> n >> c >> m;
  for (int i=0; i<m; i++) {
    cin >> p[i] >> b[i];
  }
}

pii solve() {
  int x=0, y=0;
  memset(cntP, 0, sizeof(cntP));
  memset(cntB, 0, sizeof(cntB));
  for (int i=0; i<m; i++) {
    cntP[p[i]]++;
    cntB[b[i]]++;
    x = max(x, cntB[b[i]]);
  }
  int tot = 0;
  for (int i=1; i<=n; i++) {
    tot += cntP[i];
    x = max(x, (tot + i - 1) / i);
  }
  for (int i=1; i<=n; i++) if (cntP[i] > x) y += cntP[i] - x;
  return {x, y};
}

int main() {
  int cas;
  cin >> cas;
  for (int i=1; i<=cas; i++) {
    read();
    pii res = solve();
    printf("Case #%d: %d %d\n", i, res.first, res.second);
  }
  return 0;
}
