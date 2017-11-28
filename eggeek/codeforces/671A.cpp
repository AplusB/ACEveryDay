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
ll ax, ay, bx, by, tx, ty, x[N], y[N];
vector<pair<double, int> > diff1, diff2;
int n;

double dist(ll x1, ll y1, ll x2, ll y2) {
  double dx = (double)(x1 - x2);
  double dy = (double)(y1 - y2);
  return sqrt(dx*dx + dy*dy);
}

int main() {
  cin >> ax >> ay >> bx >> by >> tx >> ty;
  cin >> n;
  double tot = 0;
  for (int i=0; i<n; i++) {
    cin >> x[i] >> y[i];
    tot += dist(x[i], y[i], tx, ty);
    diff1.push_back({- dist(x[i], y[i], tx, ty) + dist(ax, ay, x[i], y[i]), i});
    diff2.push_back({- dist(x[i], y[i], tx, ty) + dist(bx, by, x[i], y[i]), i});
  }
  sort(ALL(diff1));
  sort(ALL(diff2));
  double tmp;
  double res = 1e18;
  // a, b
  tmp = tot * 2.0 + diff1[0].first;
  for (int i=0; i<n; i++) {
    if (diff1[0].second != diff2[i].second && diff2[i].first < 0) {
      tmp += diff2[i].first;
      break;
    }
  }
  res = min(res, tmp);
  // b, a
  tmp = tot * 2.0 + diff2[0].first;
  for (int i=0; i<n; i++) {
    if (diff1[i].second != diff2[0].second && diff1[i].first < 0) {
      tmp += diff1[i].first;
      break;
    }
  }
  res = min(res, tmp);
  printf("%.6lf\n", res);
  return 0;
}
