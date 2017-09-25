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
#define N 10010
int dp[N];

void init() {
  dp[0] = 0;
  for (int i=1; i<N; i++) {
    dp[i] = i;
    for (int j=1; j*j<=i; j++) dp[i] = min(dp[i], dp[i-j*j] + 1);
  }
}

int main() {
  int cas;
  init();
  cin >> cas;
  for (int i=1; i<=cas; i++) {
    int n;
    cin >> n;
    int ans = dp[n];
    printf("Case #%d: %d\n", i, ans);
  }
  return 0;
}
