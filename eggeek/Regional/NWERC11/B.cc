#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define x first
#define y second

string solve(int a, int b) {
  if (a == b) return "";
  if (a > b) {
    int ai = b;
    int bi = a - b;
    string pre = solve(ai, bi);
    pre.push_back('R');
    return pre;
  } else {
    int bi = a;
    int ai = b - a;
    string pre = solve(ai, bi);
    pre.push_back('L');
    return pre;
  }
}

int main() {
	int cases;
	cin >> cases;

	while (cases-- > 0) {
    int a, b;
	  scanf("%d/%d", &a, &b);
    string ans = solve(a, b);
    reverse(ans.begin(), ans.end());
    printf("%s\n", ans.c_str());
	}
	return 0;
}
