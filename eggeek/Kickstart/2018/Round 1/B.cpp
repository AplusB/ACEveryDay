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
const double EPS = 1e-6;
int n, k, cnt, m, mcnt;
double tot, p, ave;
vector<double> v, sum;

double bs(double var) {
  int l = 0, r = n-1, best = r;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (v[mid] >= var) {
      best = mid;
      r = mid - 1;
    }
    else l = mid + 1;
  }
  return best;
}

double get_sum(int r, int l) {
  if (l == 0) return sum[r];
  else return sum[r] - sum[l-1];
}

double solve(int i) {
  if (i == 0) {
    return tot / (double)n;
  }
  else {
    double nxt = solve(i-1);
    int idx = bs(nxt);
    double e = get_sum(n-1, idx) / (double)n;
    double res = e + (double)idx / (double)n * nxt;
    return res;
  }
}

void do_case() {
  cin >> n >> k;
  v.resize(n);
  sum.resize(n);
  for (int i=0; i<n; i++) cin >> v[i];
  sort(ALL(v));
  sum[0] = v[0];
  for (int i=1; i<n; i++) sum[i] = sum[i-1] + v[i];
  tot = 0;
  for (auto i: v) tot += i;
  m = v[0];
  mcnt = 0;
  for (int i=0; i<n; i++) if (fabs(v[i] - v[0]) < EPS) mcnt ++;
  ave = tot / (double)n;
  cnt = 0;
  for (auto i: v) if (i >= ave) cnt++;
  p = (double)mcnt/ (double)n;
  double res = solve(k);
  printf("%.6lf\n", res);
}

int main() {
  int cas;
  cin >> cas;
  for (int i=1; i<=cas; i++) {
    printf("Case #%d: ", i);
    do_case();
  }
  return 0;
}
