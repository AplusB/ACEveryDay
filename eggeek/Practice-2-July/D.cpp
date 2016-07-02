#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int gcd(int a, int b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  return gcd(b, a%b);
}
void solve(vi& a) {
  vi ans;
  int cnt = 0;
  for (int i=0; i<(int)a.size(); i++) {
    if (i+1 < (int)a.size()) {
      int x = a[i];
      int y = a[i+1];
      int g = gcd(x, y);
      if (g == 1) {
        ans.push_back(a[i]);
      } else {
        ans.push_back(a[i]);
        ans.push_back(1);
        cnt++;
      }
    } else {
      ans.push_back(a[i]);
    }
  }
  printf("%d\n", cnt);
  for (int i=0; i<(int)ans.size(); i++)
    printf("%d%c", ans[i], i+1==(int)ans.size()?'\n': ' ');
}

int main() {
  int n;
  scanf("%d", &n);
  vi a;
  for (int i=0; i<n; i++) {
    int t;
    scanf("%d", &t);
    a.push_back(t);
  }
  solve(a);
  return 0;
}
