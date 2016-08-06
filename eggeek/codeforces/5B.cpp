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

int main() {
  string str;
  vector<string> contents;
  int maxL = 0;
  while (getline(cin, str)) {
    contents.push_back(str);
    maxL = max(maxL, SZ(str));
  }
  for (int i=0; i<maxL+2; i++) printf("*"); printf("\n");
  bool flag = false;
  for (string i: contents) {
    int l, r;
    if ((maxL - SZ(i)) % 2) {
      if (flag) l = (maxL - SZ(i)) / 2 + 1;
      else l = (maxL - SZ(i)) / 2;
      flag = !flag;
    }
    else l = (maxL - SZ(i)) / 2;
    r = maxL - SZ(i) - l;
    for (int j=0; j<l; j++) i = ' ' + i;
    for (int j=0; j<r; j++) i.push_back(' ');
    cout << "*" << i << "*" << endl;
  }
  for (int i=0; i<maxL+2; i++) printf("*"); printf("\n");
  return 0;
}
