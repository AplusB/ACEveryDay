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
#define N 10001
char s[N];
char a[N], b[N], c[N];
int tot, n;

void go(int& i, int& cnt, char* num) {
  while (cnt != tot / 3) {
    int t = s[i] - '0';
    if (cnt + t <= tot / 3) {
      cnt += t;
      s[i] -= t;
      num[i] = t + '0';
    }
    else {
      t = tot / 3 - cnt;
      cnt += t;
      s[i] -= t;
      num[i] = t + '0';
    }
    if (cnt == tot / 3) break;
    else i++;
  }
}

void solve() {
  tot = 0, n = 0;
  for (int i=0; s[i]; i++, n++) tot += s[i] - '0';
  if (tot % 3) {
    printf("-1\n");
    return;
  }
  for (int i=0; i<n; i++) a[i] = b[i] = c[i] = '0';
  int i= 0;
  int cnta=0, cntb=0, cntc=0;
  go(i, cnta, a);
  go(i, cntb, b);
  go(i, cntc, c);
  int offa=0, offb=0, offc=0;
  while (offa < n && a[offa] == '0') offa++;
  while (offb < n && b[offb] == '0') offb++;
  while (offc < n && c[offc] == '0') offc++;
  printf("%s %s %s\n", a+offa, b+offb, c+offc);
}

int main() {
  //freopen("test.in", "r", stdin);
  scanf("%s", s);
  solve();
  return 0;
}
