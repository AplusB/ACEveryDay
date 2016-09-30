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
#define N 1000010
int t[N], f[N];

ll count1(int k, int n, string s) {
  ll res = 0;
  int l = 0, r = 0, cnt = s[0] == '1';
  while (l < n && s[l] == '0') l++;
  r = l; cnt = 1;
  while (r < n) {
    while (r+t[r] < n && cnt < k) {
      r += t[r];
      cnt ++;
    }
    //printf("l:%d r:%d\n", l, r);
    if (cnt == k) {
      //printf("res += %d * %d\n", f[l], t[r]);
      res += (ll)f[l] * (ll)t[r];
    } else break;
    l += t[l];
    cnt--;
  }
  return res;
}

ll count0(int k, int n, string s) {
  ll res = 0;
  int l = 0;
  while (l < n && s[l] == '1') l++;
  while (l < n) {
    //printf("l: %d, t: %d\n", l, t[l]);
    res += t[l];
    l++;
    while (l < n && s[l] == '1') l++;
  }
  return res;
}

int main() {
  int k, n;
  string s;
  cin >> k >> s;
  n = SZ(s);

  f[0] = 1;
  for (int i=1; i<n; i++) {
    if (s[i-1] == '0') f[i] = f[i-1] + 1;
    else f[i] = 1;
  }
  t[n-1] = 1;
  for (int i=n-2; i>=0 ; i--) {
    if (s[i+1] == '0') t[i] = t[i+1] + 1;
    else t[i] = 1;
  }

  if (k) {
    cout << count1(k, n, s) << endl;
  } else {
    cout << count0(k, n, s) << endl;
  }
  return 0;
}
