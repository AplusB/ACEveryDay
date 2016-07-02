#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
int n, p, cur;
int mp[30][30], first[30];

void addE(int u, int v) {
  mp[u][v] = 1;
  mp[v][u] = 1;
  cur++;
}

void do_case() {
  cin >> n >> p;
  memset(mp, 0, sizeof(mp));
  int tot = n * 2 + p;
  cur = 0;
  for (int i=1; i<n; i++) {
    addE(i, n);
    if (i+1 < n) addE(i, i+1);
  }

  for (int i=1; i<=n-3; i++) {
    first[i] = i + 2;
  }

  int idx = 1;
  while (cur < tot) {
    if (first[idx] > n-1) idx++;
    addE(idx, first[idx]++);
  }
  for (int i=1; i<=n; i++) {
    for (int j=i+1; j<=n; j++) if (mp[i][j]) printf("%d %d\n", i, j);
  }
}

int main() {
  int cas;
  cin >> cas;
  while (cas--) do_case();
  return 0;
}
