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
#define N 101
char img[N][N], imgr[N][N], imgh[N][N], imgs[N<<1][N<<1];
int h, w;

int main() {
  cin >> w >> h;
  for (int i=0; i<h; i++) scanf("%s", img[i]);
  for (int i=0; i<w; i++)
    for (int j=0; j<h; j++) imgr[i][j] = img[j][i];
  for (int i=0; i<w; i++) imgr[i][h] = 0;
  for (int i=0; i<w; i++)
    for (int j=0; j<h; j++) imgh[i][j] = imgr[i][j];
  for (int i=0; i<w; i++) {
    for (int ki=0; ki<2; ki++) {
      for (int j=0; j<h; j++)
        for (int kj=0; kj<2; kj++) {
          imgs[i*2 + ki][j*2 + kj] = imgh[i][j];
        }
      imgs[i*2 + ki][2*h] = 0;
    }
  }
  for (int i=0; i<2*w; i++) printf("%s\n", imgs[i]);
  return 0;
}
