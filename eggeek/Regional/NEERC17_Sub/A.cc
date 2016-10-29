#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define N 1000010
int r[N<<1], n;

void solve() {
    for (int i=0; i<n; i++) {
        if (r[i] < r[i+1] && r[i+1] > r[i+2]) {
            int a = i+1, b = (i+1)%n + 1, c = (i+2)%n + 1;
            printf("%d %d %d\n", a, b, c);
            return;
        }
    }
}

int main() {
    scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &r[i]);
    for (int i=0; i<n; i++) r[i+n] = r[i];
    solve();
	return 0;
}
