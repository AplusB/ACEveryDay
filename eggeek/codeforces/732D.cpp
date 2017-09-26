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
#define N 100010
int n, m, vis[N], d[N], a[N];

bool check(int t) {
  memset(vis, 0, sizeof(vis));
  int tot = 0, cnt = 0, pre = -1, need = 0;
  for (int i=t; i>=1; i--) if (d[i] && !vis[d[i]]) {
    need = a[d[i]];
    vis[d[i]] = 1;
    cnt++;
    pre = i;
    if (cnt == m) {
      tot += need;
      break;
    }
    for (int j=i-1; j>=1; j--) {
      if (d[j] && !vis[d[j]]) {
        tot += need;
        i = j+1;
        break;
      } else {
        if (need-1 >= 0) need --;
        else tot = max(0, tot - 1);
      }
    }
  }
  if (cnt < m) return false;
  return (pre-1) >= tot;
}

int solve() {
  int l=1, r=n, best = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      best = mid;
      r = mid - 1;
    } else l = mid + 1;
  }
  return best;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i=1; i<=n; i++) scanf("%d", &d[i]);
  for (int i=1; i<=m; i++) scanf("%d", &a[i]);
  cout << solve() << endl;
  return 0;
}
