#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cstdio>
#include <random>
#include <cmath>
#include <ctime>
#include <functional>
#include <algorithm>
#include <complex>
#include <numeric>
#include <limits>
#include <bitset>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <array>
#include <list>
#include <map>
#include <set>
using namespace std;
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) int((a).size())
#define MP(x, y) make_pair((x),(y))
#define FI first
#define SE second
#define LOWB(x) (x & (-x))
#define UNIQUE(a) sort(ALL(a)), (a).erase(unique(ALL(a)), (a).end())
#define HEIGHT(n) (sizeof(int) * 8 - __builtin_clz(n)) //height of range n segment tree
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
const double eps = 1e-4;
double gcd(double x, double y) {
    while (fabs(x) > eps && fabs(y) > eps) {
        if (x > y) x -= floor(x / y) * y;
        else y -= floor(y / x) * x;
    }
    return x + y;
}

double dist(pair<double, double> u, pair<double, double> v) {
  double d1 = (u.first - v.first);
  double d2 = (u.second - v.second);
  return sqrt(d1*d1 + d2*d2);
}

double area(double a, double b, double c) {
  double s = (a + b + c) / 2;
  return sqrt(s * (s-a) * (s-b) * (s-c));
}

int main() {
  double x1, x2, x3;
  double y1, y2, y3;
  cin >> x1 >> y1;
  cin >> x2 >> y2;
  cin >> x3 >> y3;
  double a, b, c;
  a = dist({x1, y1}, {x2, y2});
  b = dist({x2, y2}, {x3, y3});
  c = dist({x3, y3}, {x1, y1});
  double S = area(a, b, c);
  double R = a*b*c / (4.0 * S);

  double A=acos((b*b+c*c-a*a)/(2*b*c));
  double B=acos((a*a+c*c-b*b)/(2*a*c));
  double C=acos((a*a+b*b-c*c)/(2*a*b));
  double g=gcd(A,gcd(B,C));
  double n=(acos(-1.0))/(g);
  double ans=((double)R*R*n*sin((2*acos(-1.0))/n))/2;
  printf("%.6lf\n",ans);
  return 0;
}
