#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define N 1010
int n, B, M[N];

ll count(ll t) {
  ll cnt = 0;
  for (int i=1; i<=B; i++) {
    cnt += (ll)(t + M[i] - 1ll) / (ll)M[i]; 
  }
  return cnt;
}

ll bsearch() {
  ll l = 0, r = 1e15, best = 0;
  while (l <= r) {
    ll mid = (l + r) >> 1;
    ll cnt = count(mid);
    if (cnt < n) {
      best = mid;
      l = mid + 1;
    } else r = mid - 1;
  }
  return best;
}

ll do_case() {
  cin >> B >> n;
  for (int i=1; i<=B; i++) cin >> M[i];
  ll t = bsearch();
  ll cnt = count(t);
  assert(cnt < n);
  for (int i=1; i<=B; i++) if (t % (ll)M[i] == 0) {
    cnt++;
    if (cnt == n) return i;
  }
  assert(false);
  return -1;
}

int main() {
  int cas;
  cin >> cas;
  for (int i=1; i<=cas; i++) {
    ll ans = do_case();
    printf("Case #%d: %lld\n", i, ans);
  }
  return 0;
}
