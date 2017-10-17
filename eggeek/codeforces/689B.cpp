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
const int N = 200010;
int n, a[N], dp[N];
vi nxt[N];

priority_queue<pii, vector<pii>, less<pii>> q;

void Dijkstra() {
  for (int i=1; i<=n; i++) dp[i] = N;
  dp[1] = 0;
  q.push({0, 1});
  while (!q.empty()) {
    pii c = q.top(); q.pop();
    if (c.first != dp[c.second]) continue;
    for (int i: nxt[c.second]) if (c.first + 1 < dp[i]) {
      dp[i] = c.first + 1;
      q.push({dp[i], i});
    }
    if (c.second + 1 <= n && c.first + 1 < dp[c.second + 1]) {
      dp[c.second + 1] = c.first + 1;
      q.push({dp[c.second + 1], c.second + 1});
    }
    if (c.second - 1 >  1 && c.first + 1 < dp[c.second - 1]) {
      dp[c.second - 1] = c.first + 1;
      q.push({dp[c.second - 1], c.second - 1});
    }
  }
  for (int i=1; i<=n; i++) printf("%d%c", dp[i], i<n?' ': '\n');
}
int main() {
  scanf("%d", &n);
  for (int i=1; i<=n; i++) {
    scanf("%d", a+i);
    if (a[i] != i) nxt[i].push_back(a[i]);
  }
  Dijkstra();
  return 0;
}
