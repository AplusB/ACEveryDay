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
int n, h;
double tot, p;
const double eps = 1e-6;

double calc(double d, double curh) {
  double u = sqrt(d*d - 2.0 * p * d/ curh);
  return u;
}

void solve() {
  double curh = h;
  double d = 1.0;
  vector<double> hs;
  for (int i=0; i<n-1; i++) {
    double u = calc(d, curh);
    double h0 = (d - u) / d  * curh;
    hs.push_back(h0);
    curh -= h0;
    d = u;
  }
  hs.push_back(curh);
  reverse(ALL(hs));
  curh = 0.0;
  for (int i=0; i<n-1; i++) {
    curh += hs[i];
    printf("%.6lf%c", curh, i==n-2?'\n': ' ');
  }
  curh += hs[n-1];
  assert(fabs(curh - h) <= eps);
}

int main() {
  cin >> n >> h;
  tot = (double)h / 2.0;
  p = (double)tot / n;
  solve();
  return 0;
}
