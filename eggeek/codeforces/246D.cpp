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
int n, m, c[N];
set<int> s[N];

int main() {
  scanf("%d%d", &n, &m);
  for (int i=1; i<=n; i++) scanf("%d", c+i);
  for (int i=0; i<m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    if (c[v] != c[u]) {
      s[c[u]].insert(c[v]);
      s[c[v]].insert(c[u]);
    }
  }
  int maxarg = c[1];
  for (int i=1; i<=n; i++)  {
    if (s[c[i]].size() == s[maxarg].size() && c[i] < maxarg) maxarg = c[i];
    else if (s[c[i]].size() > s[maxarg].size()) maxarg = c[i];
  }
  printf("%d\n", maxarg);
  return 0;
}
