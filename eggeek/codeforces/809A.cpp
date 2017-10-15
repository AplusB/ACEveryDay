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
const int N = 300010;
const ll mod = 1000000007ll;
int n, x[N];
ll f[N], p[N];

ll solve() {
  sort(x+1, x+1+n);
  if (n == 1) return 0;
  if (n == 2) return x[2] - x[1];
  p[0] = 1;
  for (int i=1; i<=n; i++) p[i] = 2ll * p[i-1] % mod;
  ll res = 0;
  ll subs = 1;
  ll sum = x[1] + x[2];
  f[1] = 0, f[2] = x[2] - x[1];
  for (int i=3; i<=n; i++) {
    f[i] = 2ll * (f[i-1] + subs * (ll)(x[i] - x[i-1]));
    f[i] += x[i] - x[i-1];
    f[i] %= mod;
    sum += x[i];
    subs = (subs * 2ll + 1) % mod;
  }
  for (int i=1; i<=n; i++) res = (res + f[i]) % mod;
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i=1; i<=n; i++) scanf("%d", x+i);
  cout << solve() << endl;
  return 0;
}
