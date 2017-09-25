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
int e, n;
vi s;

int solve() {
  cin >> e >> n;
  s.resize(n);
  for (int i=0; i<n; i++) cin >> s[i];
  sort(ALL(s));
  int cnt = 0, rest = e, l = 0;
  while (l < n && rest > s[l]) {
    rest -= s[l];
    l++;
    cnt++;
  }
  int r = n-1, cur = cnt;
  while (l < r) {
    if (rest > s[l]) {
      rest -= s[l++];
      cur++;
      cnt = max(cnt, cur);
    }
    else if (cur){
      rest += s[r--];
      cur--;
      cnt = max(cnt, cur);
    } else break;
  }
  if (l <= r && rest > s[l]) {
    cur++;
    cnt = max(cnt, cur);
  }
  assert(rest > 0);
  return cnt;
}

int main() {
  int cas;
  cin >> cas;
  for (int i=1; i<=cas; i++) {
    int ans = solve();
    printf("Case #%d: %d\n", i, ans);
  }
  return 0;
}
