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
int x[3], y[3];

int solve() {
  if (x[0] == x[1] && x[1] == x[2]) return 1;
  if (y[0] == y[1] && y[1] == y[2]) return 1;
  for (int i=0; i<3; i++) {
    for (int j=i+1; j<3; j++) {
      int k = 3 - i - j;
      if (x[i] == x[j]) {
        if (y[k] <= min(y[i], y[j])) return 2;
        if (y[k] >= max(y[i], y[j])) return 2;
      }
      if (y[i] == y[j]) {
        if (x[k] <= min(x[i], x[j]) ||
            x[k] >= max(x[i], x[j])) return 2;
      }
    }
  }
  return 3;
}

int main() {
  for (int i=0; i<3; i++) {
    scanf("%d%d", &x[i], &y[i]);
  }
  cout << solve() << endl;
  return 0;
}
