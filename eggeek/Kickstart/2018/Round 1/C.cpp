#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) int((a).size())
#define LOWB(x) (x & (-x))
#define UNIQUE(a) sort(ALL(a)), (a).erase(unique(ALL(a)), (a).end())
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
int n, l, cnt[26], cntd[26];
ll a, b, c, d;
vi x;
vector<string> dict;
string s1, s2, s;

void gen_str() {
  s.resize(l);
  x.resize(l);
  s[0] = s1[0];
  s[1] = s2[0];
  x[0] = (int)s1[0];
  x[1] = (int)s2[0];
  for (int i=2; i<l; i++) {
    x[i] = (a * (ll)x[i-1] + (ll)b * (ll)x[i-2] + (ll)c) % d;
    s[i] = char(97 + (ll)x[i] % 26ll);
  }
}

bool check(int x, int y) {
  memset(cnt, 0, sizeof(cnt));
  for (int i=x; i<=y; i++) cnt[int(s[i]-'a')]++;
  for (int i=0; i<26; i++) if (cnt[i] != cntd[i]) return false;
  return true;
}

int get_cnt(const string& str) {
  int len = (int)str.size();
  for (int i=0; i <= l - len; i++) {
    if (s[i] == str[0] && s[i+len-1] == str[len-1]) {
      bool flag = check(i, i+len-1);
      if (flag)
        return flag;
    }
  }
  return 0;
}

void do_case() {
  cin >> n;
  dict.resize(n);
  for (int i=0; i<n; i++) {
    cin >> dict[i];
  }
  cin >> s1 >> s2;
  cin >> l >> a >> b >> c >> d;
  gen_str();
  int ans = 0;
  for (const string& str: dict) {
    memset(cntd, 0, sizeof(cntd));
    for (char ci: str) cntd[int(ci - 'a')] ++;
    ans += get_cnt(str);
  }
  printf("%d\n", ans);
}

int main() {
  int cas;
  cin >> cas;
  for (int i=1; i<=cas; i++) {
    printf("Case #%d: ", i);
    do_case();
  }
  return 0;
}
