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
int cnt[300];

int calc() {
  int res = 0;
  for (int i=0; i<26; i++) res += (cnt[i+'a']>0) + (cnt[i+'A']>0);
  return res;
}

int main() {
  int n, tot;
  string s;
  cin >> n >> s;
  for (int i=0; i<n; i++) cnt[s[i]]++;
  tot = calc();
  memset(cnt, 0, sizeof(cnt));
  int res, r = 0, l = 0;
  while (r < n && calc() < tot) cnt[s[r]]++, r++;
  while (l < r) {
    cnt[s[l]]--;
    if (calc() == tot) l++;
    else {
      cnt[s[l]]++;
      break;
    }
  }
  res = r - l;
  while (r < n) {
    cnt[s[r]]++;
    r++;
    while (l < r) {
      cnt[s[l]]--;
      if (calc() == tot) l++;
      else {
        cnt[s[l]]++;
        break;
      }
    }
    res = min(res, r - l);
  }
  cout << res << endl;
  return 0;
}
