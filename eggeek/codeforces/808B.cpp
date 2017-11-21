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
#define N 200010
int n, k, a[N];
ll sum[N];

int main() {
  scanf("%d%d", &n, &k);
  for (int i=1; i<=n; i++) scanf("%d", &a[i]);
  for (int i=1; i<=n; i++) sum[i] = sum[i-1] + (ll)a[i];
  ll tot = 0;
  for (int i=k; i<=n; i++) {
    tot += sum[i] - sum[i-k];
  }
  printf("%.6lf\n", (double)tot / (double)(n - k + 1));
  return 0;
}
