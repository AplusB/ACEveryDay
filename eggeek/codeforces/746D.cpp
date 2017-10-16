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
int n, k, a, b;

string solve(int num0, char c0, int num1, char c1) {
  // num0 >= num1
  if ((ll)num0 > (ll)k * (num1 + 1ll)) return "NO";
  int diff = num0 - num1;
  string res = "";
  int rest0 = num0;
  for (int i=0; i<num1; i++) {
    res.push_back(c0);
    rest0--;
    for (int j=1; j<k && diff; j++) {
      res.push_back(c0);
      rest0--;
      diff--;
    }
    res.push_back(c1);
  }
  assert(rest0 <= k);
  for (int i=0; i<rest0; i++) {
    res.push_back(c0);
    diff--;
  }
  assert(diff == 0);
  return res;
}

int main() {
  cin >> n >> k >> a >> b;
  if (a >= b) cout << solve(a, 'G', b, 'B') << endl;
  else cout << solve(b, 'B', a, 'G') << endl;
  return 0;
}
