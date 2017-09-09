#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

pii do_case() {
  pii ans;
  vi p;
  int n;
  cin >> n;
  p.resize(n);
  for (int i=0; i<n; i++) cin >> p[i];
  ans.first = 0;
  for (int i=1; i<n; i++) if (p[i] < p[i-1]) ans.first += p[i-1] - p[i];
  int x = 0;
  for (int i=1; i<n; i++) if (p[i] < p[i-1]) x = max(x, p[i-1] - p[i]);
  ans.second = 0;
  for (int i=0; i<n-1; i++) {
    int eat = min(p[i], x);
    ans.second += eat;
  }
  return ans;
}

int main() {
  int cas;
  cin >> cas;
  for (int i=1; i<=cas; i++) {
    pii ans = do_case();
    printf("Case #%d: %d %d\n", i, ans.first, ans.second);
  }
  return 0;
}
