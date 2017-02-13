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
#define N 100010
int cntp[26], cnts[27], lens, lenp;
char s[N], p[N];

int main() {
  scanf("%s%s", s, p);
  lens = strlen(s);
  lenp = strlen(p);
  for (int i=0; i<lenp; i++) cntp[p[i]-'a']++;
  int res = 0, r = 0;
  for (int i=0; i+lenp <= lens; i++) {
    while (r - i < lenp) {
      if (s[r] == '?') cnts[26]++;
      else cnts[s[r] - 'a']++;
      r++;
    }
    assert(r <= lens);
    bool flag = true;
    int miss = 0;
    for (int j=0; j<26; j++) {
      if (cnts[j] > cntp[j]) {
        flag = false;
        break;
      }
      miss += cntp[j] - cnts[j];
    }
    if (flag && miss == cnts[26]) res++;
    if (s[i] == '?') cnts[26]--;
    else cnts[s[i]-'a']--;
  }
  printf("%d\n", res);
  return 0;
}
