#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define N 2001
int n;
struct P {
  int x, y;
};
P ps[N];
map<pii, int> h;

void do_case() {
  for (int i=0; i<n; i++) {
    scanf("%d%d", &ps[i].x, &ps[i].y);
  }
  h.clear();
  for (int i=0; i<n; i++) {
    for (int j=i+1; j<n; j++) {
      pii s = make_pair(((ll)ps[i].x + (ll)ps[j].x),
                        ((ll)ps[i].y + (ll)ps[j].y));
      if (h.find(s) == h.end()) {
        h[s] = 1;
      } else h[s] = h[s] + 1;
      //printf("(%d, %d) cnt:%d\n", s.first, s.second, h[s]);
    }
  }
  ll ans = 0;
  for (auto it=h.begin(); it != h.end(); it++) {
    //printf("pii:(%d, %d) cnt:%d\n", it->first.first, it->first.second, it->second);
    ll cnt = it->second;
    ans += cnt * (cnt -1l) / 2l;
  }
  cout << ans << endl;
}

int main() {
  while (cin >> n) do_case();
  return 0;
}
