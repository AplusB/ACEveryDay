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
const int N = 3001;
int n, m;
bool g[N][N];
vi pre[N];

ll solve() {
  ll res = 0;
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=n; j++) if (j != i) {
      int cnt = 0;
      for (int b: pre[j]) if (g[i][b]) cnt++;
      res += (cnt - 1) * cnt / 2;
    }
  }
  return res;
}

int main() {
  scanf("%d%d", &n, &m);
  memset(g, 0, sizeof(g));
  for (int i=0; i<m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u][v] = true;
    pre[v].push_back(u);
  }
  cout << solve() << endl;
  return 0;
}
