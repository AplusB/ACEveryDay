#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define N 101
int s[N][4];
int n, m;

void do_case() {
  int p = 1;
  memset(s, -1, sizeof(s));
  for (int i=1; i<=n && p<=m; i++) {
    if (p <= m) s[i][0] = p++;
    if (p <= m) s[i][3] = p++;
  }
  for (int i=1; i<=n && p<=m; i++) {
    if (p <= m) s[i][1] = p++;
    if (p <= m) s[i][2] = p++;
  }
  int cnt = 0;
  vi ans;
  for (int i=1; i<=n && cnt<m; i++) {
    if (s[i][1] != -1) {
      ans.push_back(s[i][1]);
      cnt++;
    }
    if (s[i][0] != -1) {
      ans.push_back(s[i][0]);
      cnt++;
    }
    if (s[i][2] != -1) {
      ans.push_back(s[i][2]);
      cnt++;
    }
    if (s[i][3] != -1) {
      ans.push_back(s[i][3]);
      cnt++;
    }
  }
  for (int i=0; i<m; i++) printf("%d%c", ans[i], i+1==m?'\n': ' ');
}

int main() {
  while (cin >> n >> m) do_case();
  return 0;
}
