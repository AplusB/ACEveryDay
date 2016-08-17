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
int n, cnt[10];
string s;

int main() {
  cin >> n >> s;
  sort(s.begin(), s.end());
  for (char i: s) {
    if (i == '9') {
      cnt[7]++;
      cnt[3] += 2;
      cnt[2]++;
    }
    if (i == '8') {
      cnt[7]++;
      cnt[2] += 3;
    }
    if (i == '7') {
      cnt[7]++;
    }
    if (i == '6') {
      cnt[5]++;
      cnt[3]++;
    }
    if (i == '5') cnt[5]++;
    if (i == '4') {
      cnt[3]++;
      cnt[2] += 2;
    }
    if (i == '3') {
      cnt[3]++;
    }
    if (i == '2') {
      cnt[2]++;
    }
  }
  string ans = "";
  for (int i=7; i>=2; i--) {
    while(cnt[i]--) {
      ans.push_back((char)(i + '0'));
    }
  }
  cout << ans << endl;
  return 0;
}
