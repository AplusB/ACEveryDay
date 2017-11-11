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
int n, l, x, y, a[N];
set<int> v, v2;

bool exist(int b) {
  if (v.find(b) != v.end()) return true;
  for (int i=0; i<n; i++) {
    if (v.find(a[i]-b) != v.end() || v.find(a[i]+b) != v.end()) return true;
  }
  return false;
}

void solve() {
  if (exist(x) && exist(y)) {
    printf("0\n");
    return;
  }
  if (exist(x)) {
    printf("1\n%d\n", y);
    return;
  }
  if (exist(y)) {
    printf("1\n%d\n", x);
    return;
  }
  for (int i=0; i<n; i++) {
    int t;
    t = a[i] - x;
    if (t >= 0 && t <= l) v2.insert(t);
    t = a[i] + x;
    if (t >= 0 && t <= l) v2.insert(t);
  }
  for (int i=0; i<n; i++) {
    int t;
    t = a[i] - y;
    if (v2.find(t) != v2.end()) {
      printf("1\n%d\n", t);
      return;
    }
    t = a[i] + y;
    if (v2.find(t) != v2.end()) {
      printf("1\n%d\n", t);
      return;
    }
  }
  printf("2\n%d %d\n", x, y);
}

int main() {
  scanf("%d%d%d%d", &n, &l, &x, &y);
  for (int i=0; i<n; i++) scanf("%d", &a[i]);
  for (int i=0; i<n; i++) v.insert(a[i]);
  solve();
  return 0;
}
