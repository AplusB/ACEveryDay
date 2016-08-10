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
int na, ma;
char a[55][55];
int nb, mb;
char b[55][55];

int shift(int x, int y) {
  int sum = 0;
  for (int i=1; i<=na; i++) {
    for (int j=1; j<=ma; j++) {
      if (1 <= i+x  && i+x <= nb && 1 <= j+y && j+y <= mb) {
        sum += (a[i][j] - '0') * (b[i+x][j+y] - '0');
      }
    }
  }
  return sum;
}

int main() {
  cin >> na >> ma;
  for (int i=1; i<=na; i++) scanf("%s", a[i]+1);
  cin >> nb >> mb;
  for (int i=1; i<=nb; i++) scanf("%s", b[i]+1);
  int x = -1, y = -1, v = -1;
  for (int i=-50; i<50; i++)
    for (int j=-50; j<50; j++) {
      int tmp = shift(i, j);
      if (tmp > v) {
        x = i;
        y = j;
        v = tmp;
      }
    }
  cout << x << " " << y << endl;
  return 0;
}
