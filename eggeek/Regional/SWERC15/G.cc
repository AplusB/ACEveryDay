#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define maxP 110
#define maxN 1010
int P, K, c[maxP], s[maxP][maxN];
int dp[maxP][maxN], sg[maxP];

int dfs(int pid, int pos) {
  if (pos == 0) return dp[pid][pos] = 0;
  if (dp[pid][pos] != -1) return dp[pid][pos];
  set<int> g;
  for (int i=0; i<=K && pos - i > 0; i++) {
    if (pos - i >= s[pid][pos-i]) {
      int v = dfs(pid, pos - i - s[pid][pos-i]);
      g.insert(v);
    } //else g.insert(0);
  }
  dp[pid][pos] = 0;
  while (true) {
    if (!g.count(dp[pid][pos])) return dp[pid][pos];
    dp[pid][pos]++;
  }
  assert(false);
}

int main() {
  cin >> P >> K;
  for (int i=0; i<P; i++) {
    cin >> c[i];
    for (int j=1; j<=c[i]; j++) cin >> s[i][j];
  }
  memset(dp, -1, sizeof(dp));
  for (int i=0; i<P; i++) {
    sg[i] = dfs(i, c[i]);
    //printf("sg[%d]:%d\n", i, sg[i]);
  }
  int flag = 0;
  for (int i=0; i<P; i++) flag ^= sg[i];
  printf(flag?"Alice can win.\n": "Bob will win.\n");
  return 0;
}
