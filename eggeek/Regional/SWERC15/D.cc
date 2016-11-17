#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define N 100
int cnt[N];

int main() {
  int n, m;
  cin >> n >> m;
  memset(cnt, 0, sizeof(cnt));
  for (int i=1; i<=n; i++)
  for (int j=1; j<=m; j++) cnt[i+j]++;
  int maxV = 0;
  for (int i=0; i<N; i++) maxV = max(maxV, cnt[i]);
  for (int i=1; i<N; i++) if (cnt[i] == maxV) printf("%d\n", i);
  return 0;
}
