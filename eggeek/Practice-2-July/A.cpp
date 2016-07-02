#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define N 300010
int a[N], c[N], n, k;

void update(int& ans, int& ansl, int& ansr, int cnt, int l, int r) {
  if (cnt > ans) {
    ansl = l;
    ansr = r;
    ans = cnt;
  }
}

void solve() {
  int best = 0, l, r, cnt, used;
  int ansl, ansr;

  l = r = cnt = used = 0;
  memset(c, 0, sizeof(c));

  while (l < n) {
    while (r < n) {
      if (a[r] == 1) {
        r++;
        cnt++;
        update(best, ansl, ansr, cnt, l, r);
        //printf("l:%d r:%d used:%d, ans:%d ansl:%d ansr:%d\n", l, r, used, best, ansl, ansr);
      } else if (used + 1 <= k) {
        c[r] = 1;
        r++;
        cnt++;
        used++;
        update(best, ansl, ansr, cnt, l, r);
        //printf("l:%d r:%d used:%d, ans:%d ansl:%d ansr:%d\n", l, r, used, best, ansl, ansr);
      } else break;
    }
    if (r >= n) break;

    if (c[l]) {
      c[l] = 0;
      used--;
    }
    if (cnt) {
      cnt--;
    }
    l++;
    if (r < l) r = l;
  }
  //printf("l:%d r:%d used:%d, ans:%d ansl:%d ansr:%d\n", l, r, used, best, ansl, ansr);
  if (best == 0) {
    printf("0\n");
    for (int i=0; i<n; i++) printf("%d%c", a[i], i+1==n?'\n': ' ');
  } else {
    printf("%d\n", best);
    vi ans;
    for (int i=0; i<ansl; i++) ans.push_back(a[i]);
    for (int i=ansl; i<ansr; i++) ans.push_back(1);
    for (int i=ansr; i<n; i++) ans.push_back(a[i]);
    for (int i=0; i<n; i++) {
      printf("%d%c", ans[i], i+1==n?'\n': ' ');
    }
  }

}

int main() {
  scanf("%d%d", &n, &k);
  for (int i=0; i<n; i++) {
    scanf("%d", &a[i]);
  }
  solve();
  return 0;
}
