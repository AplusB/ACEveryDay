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
#define N 5001
int n, w, h, dp[N];
int H[N], W[N], ind[N], pre[N];
queue<int> q;

void solve() {
  int maxarg = -1, maxv = -1;
  memset(pre, -1, sizeof(pre));
  int tot = 0;
  for (int i=0; i<n; i++) if (W[i] > w && H[i] > h && !ind[i]) {
    q.push(i);
    dp[i] = 1;
    tot++;
  }
  while (!q.empty()) {
    int c = q.front(); q.pop();
    if (dp[c] > maxv) {
      maxv = dp[c];
      maxarg = c;
    }
    for (int i=0; i<n; i++) {
      if (W[i] <= W[c] || H[i] <= H[c]) continue;
      ind[i]--;
      if (ind[i] == 0) {
        dp[i] = dp[c] + 1;
        pre[i] = c;
        tot++;
        q.push(i);
      }
    }
    assert(tot <= n);
  }
  if (maxv == -1) printf("0\n");
  else {
    vi path;
    int c = maxarg;
    while (c != -1) {
      path.push_back(c);
      c = pre[c];
    }
    reverse(ALL(path));
    printf("%d\n", maxv);
    for (int i=0; i<maxv; i++) printf("%d%c", path[i]+1, i+1==maxv?'\n': ' ');
    assert(maxv == (int)path.size());
  }
}

int main() {
  scanf("%d%d%d", &n, &w, &h);
  for (int i=0; i<n; i++) {
    scanf("%d%d", &W[i], &H[i]);
  }
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) if (W[j] > W[i] && H[j] > H[i]) {
      if (W[i] > w && H[i] > h) ind[j] ++;
    }
  }
  solve();
  return 0;
}
