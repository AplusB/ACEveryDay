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
int n, cnt[N][N], t[N], ans[N];

void solve() {
  for (int i=1; i<=n; i++) {
    int maxarg = -1, maxv = -1;
    for (int j=i; j<=n; j++) {
      cnt[i][t[j]]++;
      if (cnt[i][t[j]] > maxv) {
        maxv = cnt[i][t[j]];
        maxarg = t[j];
      } else if (cnt[i][t[j]] == maxv && maxarg > t[j]) {
        maxarg = t[j];
      }
      ans[maxarg]++;
    }
  }
  for (int i=1; i<=n; i++) printf("%d%c", ans[i], i==n?'\n': ' ');
}

int main() {
  scanf("%d", &n);
  for (int i=1; i<=n; i++) scanf("%d", t+i);
  solve();
  return 0;
}
