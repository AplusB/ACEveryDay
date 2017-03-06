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
#define N 8002
string s1, s2;
int dp[N][N], len1, len2;

string expand(string s) {
  string res = "";
  for (char i: s) {
    if (i == '*') {
      for (int j=0; j<4; j++) res.push_back('*');
    } else res.push_back(i);
  }
  return res;
}

bool dfs(int i, int j) {
  if (dp[i][j] != -1) return dp[i][j];
  if (i == len1) {
    for (int k=j; k<len2; k++) if (s2[k] != '*') return dp[i][j] = false;
    return dp[i][j] = true;
  }
  if (j == len2) {
    for (int k=i; k<len1; k++) if (s1[k] != '*') return dp[i][j] = false;
    return dp[i][j] = true;
  }
  bool res = false, tmp;
  if (s1[i] == '*' && s2[j] != '*') {
    tmp = dfs(i+1, j);
    res |= tmp;
    tmp = dfs(i+1, j+1);
    res |= tmp;
  }
  else if (s1[i] == '*' && s2[j] == '*') {
    tmp = dfs(i+1, j+1);
    res |= tmp;
    tmp = dfs(i, j+1);
    res |= tmp;
    tmp = dfs(i+1, j);
    res |= tmp;
  }
  else if (s1[i] != '*' && s2[j] != '*') {
    if (s1[i] == s2[j]) {
      tmp = dfs(i+1, j+1);
      res |= tmp;
    }
  }
  else if (s1[i] != '*' && s2[j] == '*') {
    tmp = dfs(i+1, j+1);
    res |= tmp;
    tmp = dfs(i, j+1);
    res |= tmp;
  }
  return dp[i][j] = res;
}

bool DP() {
  memset(dp, 0, sizeof(dp));

  dp[len1][len2] = true;
  for (int i=len1; i>=0; i--) {
    for (int j=len2; j>=0; j--) if (dp[i][j]) {
      // (i-1, j)
      if (i-1>=0 && s1[i-1] == '*') {
        dp[i-1][j] = 1;
      }
      // (i-1, j-1)
      if (i-1>=0 && j-1>=0) {
        if (s1[i-1] == '*' || s2[j-1] == '*' || s1[i-1] == s2[j-1]) dp[i-1][j-1] = 1;
      }
      // (i, j-1)
      if (j-1 >= 0 && s2[j-1] == '*') {
        dp[i][j-1] = 1;
      }
    }
  }
  return dp[0][0];
}

void solve() {
  string ts1, ts2;
  s1.clear();
  s2.clear();
  cin >> ts1 >> ts2;
  s1 = expand(ts1);
  s2 = expand(ts2);
  //printf("\nexp s1: %s, s2: %s\n", s1.c_str(), s2.c_str());
  len1 = SZ(s1);
  len2 = SZ(s2);
  memset(dp, -1, sizeof(dp));
  //bool flag = dfs(0, 0);
  bool flag = DP();
  if (flag) cout << "TRUE" << endl;
  else cout << "FALSE" << endl;
}

int main() {
  int cases;
  cin >> cases;
  for (int i=1; i<=cases; i++) {
    printf("Case #%d: ", i);
    solve();
  }
  return 0;
}
