#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int find_p(int x, int y) {
	int dis = x * x + y * y;
	for (int p = 10; p>=0; p--) {
		int rad = 20 * (11 - p);
		if (dis <= rad * rad) return p;
	}
	return 0;
}

void do_case() {
	int n;
	scanf("%d", &n);
	int tot = 0;
	for (int i=0; i<n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		int p = find_p(x, y);
		tot += p;
	}
	printf("%d\n", tot);
}

int main() {
	int cas;
	cin >> cas;
	while (cas --) do_case();
	return 0;
}
