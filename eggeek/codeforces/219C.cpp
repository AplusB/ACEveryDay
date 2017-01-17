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
#define N 500010
int n, k, dp[N][27];
char s[N];

int main() {
  scanf("%d%d", &n, &k);
  scanf("%s", s);
  if (k == 2) {
    int ans0=0, ans1=0;
    for (int i=0; i<n; i++) {
      ans0 += (s[i]-'A' != i%2);
    }
    for (int i=0; i<n; i++) {
      ans1 += (s[i]-'A' != (i+1)%2);
    }
    if (ans0 < ans1) {
      printf("%d\n", ans0);
      for (int i=0; i<n; i++) printf("%c", (i%2)+'A');
      printf("\n");
    } else {
      printf("%d\n", ans1);
      for (int i=0; i<n; i++) printf("%c", ((i+1)%2)+'A');
      printf("\n");
    }
  } else {
    int ans = 0;
    for (int i=0; i<n; i++) {
      int r = i;
      while (r+1<n && s[r+1] == s[i]) r++;
      int nxt = r+1<n?s[r+1]-'A': -1;
      int c = -1;
      for (int j=0; j<k; j++) if (j != s[i]-'A' && j != nxt) {
        c = j;
        break;
      }
      assert(c != -1);
      for (int j=i+1; j<=r; j+=2) {
        s[j] = c + 'A';
        ans++;
      }
      i = r;
    }
    printf("%d\n", ans);
    printf("%s\n", s);
  }
  return 0;
}
