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
int p, X, Y, x, y;

bool check(int i) {
  for (int j=0; j<25; j++) {
    i = (i * 96 + 42) % 475;
    if (i + 26 == p) return true;
  }
  return false;
}

int hackto(int i) {
  int ax = x / 475, bx = x % 475;
  int ay = y / 475, by = y % 475;
  if (ax == ay) {
    if (i > by && i <= bx) return 0;
    else if (i == by && X - (bx - i) * 50 >= Y) return 0;
    else if (i >= bx) return (i - bx + 1) / 2;
    else return (475 + i - bx + 1) / 2;
  } else {
    if (bx >= i || X - (bx + 475 - i) * 50 >= Y) return 0;
    else {
      return (i - bx + 1) / 2;
    }
  }
}

int solve() {
  int res = INF;
  x = X / 50;
  y = Y / 50;
  for (int i=0; i<475; i++) if (check(i)) {
    int v = hackto(i);
    res = min(res, v);
  }
  return res;
}

int main() {
  cin >> p >> X >> Y;
  cout << solve() << endl;
  return 0;
}
