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
const int N = 100010;
int n, m, vis[N];
vi e[N];

int dfs(int cur, int pre) {
  vis[cur] = 1;
  for (int i: e[cur]) if (i != pre) {
    if (vis[i]) return 1;
    if (dfs(i, cur)) return 1;
  }
  return 0;
}

int solve() {
  int ans = 0;
  for (int i=1; i<=n; i++) if (!vis[i]) {
    if (!dfs(i, -1)) ans++;
  }
  return ans;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i=0; i<m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    e[u].push_back(v);
    e[v].push_back(u);
  }
  printf("%d\n", solve());
  return 0;
}
