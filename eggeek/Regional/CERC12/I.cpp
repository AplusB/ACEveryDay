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
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template<class T> inline T min(T a, T b, T c) {return min(min(a,b),c);}
template<class T> inline T min(T a, T b, T c, T d) {return min(min(a,b),min(c,d));}
template<class T> inline T max(T a, T b, T c) {return max(max(a,b),c);}
template<class T> inline T max(T a, T b, T c, T d) {return max(max(a,b),max(c,d));}
const int INF = 1e9;
const ll INF_LL = 4e18;
const double pi = acos(-1.0);
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
/*-----------------------------------*/
const int N = 101;
const int M = 50001;
int n, m;
struct Line {
  ll A, B, C;

  void read() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    this->A = a;
    this->B = b;
    this->C = c;
  }
}l[N];

struct Point {
  ll x, y;

  void read() {
    int _x, _y;
    scanf("%d%d", &_x, &_y);
    this->x = _x;
    this->y = _y;
  }
}p[M];

vector<vi> q;

bool out(Point point, Line line) {
  ll v = line.A * point.x + line.B * point.y + line.C;
  return v < 0;
}

bool cross(Line a, Line b) {
  return a.A * b.B != a.B * b.A;
}

void do_case() {
  scanf("%d%d", &n, &m);
  for (int i=0; i<n; i++) l[i].read();
  for (int i=0; i<m; i++) p[i].read();
  q.clear();
  vi a;
  for (int i=0; i<m; i++) a.push_back(i);

  q.push_back(a);
  for (int i=0; i<n; i++) {
    int s = SZ(q);
    for (int j=0; j<s; j++) {
      vi cur = q[j];
      vi t1, t2;
      for (int k: cur) {
        if (out(p[k], l[i])) t1.push_back(k);
        else t2.push_back(k);
      }
      if (t1.empty()) {
        q[j] = t2;
      } else {
        q[j] = t1;
        if (!t2.empty()) q.push_back(t2);
      }
    }
  }

  int cnt = 1;
  for (int i=0; i<n; i++) {
    cnt++;
    for (int j=i+1; j<n; j++) if (cross(l[i], l[j])) cnt++;
  }
  if (q.size() == cnt)
    printf("PROTECTED\n");
  else
    printf("VULNERABLE\n");
}

int main() {
  int cas;
  cin >> cas;
  while (cas--) do_case();
  return 0;
}
