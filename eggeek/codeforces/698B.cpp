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
int n, p[N], f[N], root;

int find_fa(int x) {
  if (f[x] == x) return x;
  else {
    f[x] = find_fa(f[x]);
    return f[x];
  }
}

bool verify() {
  for (int i=1; i<=n; i++) f[i] = i;
  for (int i=1; i<=n; i++) if (i != root) {
    int fu = find_fa(i);
    int fv = find_fa(p[i]);
    if (fu == fv) return false;
    else f[fu] = fv;
  }
  return true;
}

int main() {
  scanf("%d", &n);
  for (int i=1; i<=n; i++) f[i] = i;
  for (int i=1; i<=n; i++) {
    scanf("%d", &p[i]);
  }
  root = -1;
  for (int i=1; i<=n; i++) {
    if (p[i] == i) {
      root = i;
      break;
    }
  }
  int cnt = 0;

  for (int i=1; i<=n; i++) if (i != root) {
    int fu = find_fa(i);
    int fv = find_fa(p[i]);
    if (fu == fv) {
      if (root == -1) {
        p[i] = i;
        root = i;
      } else p[i] = root;
      cnt++;
    } else f[fu] = fv;
  }
  printf("%d\n", cnt);
  for (int i=1; i<=n; i++) printf("%d%c", p[i], i==n?'\n': ' ');
  assert(verify());
  return 0;
}
