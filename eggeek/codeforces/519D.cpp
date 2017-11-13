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
ll x[26];
ll sum[N];
int n;
string s;
map<ll, int> h;

ll solve_B(int v) {
  ll res = 0;
  for (int i=0; i<n; i++) sum[i+1] = sum[i] + x[(int)(s[i]-'a')];
  h.clear();
  for (int i=0; i<n; i++) if ((int)(s[i]-'a') == v) {
    res += h[sum[i]];
    h[sum[i+1]]++;
  }
  return res;
}

ll solve() {
  ll res = 0;
  for (int i=0; i<26; i++) {
    res += solve_B(i);
  }
  return res;
}

int main() {
  for (int i=0; i<26; i++) cin >> x[i];
  cin >> s;
  n = (int)s.size();
  cout << solve() << endl;
  return 0;
}
