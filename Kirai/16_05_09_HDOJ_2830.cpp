#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>

using namespace std;

#define fr first
#define sc second
#define Rint(a) scanf("%d", &a)
#define Rll(a) scanf("%lld", &a)
#define Rs(a) scanf("%s", a)
#define FRead() freopen("in", "r", stdin)
#define Rep(i, n) for(int i = 0; i < (n); i++)
#define For(i, a, n) for(int i = (a); i < (n); i++)
#define Cls(a) memset((a), 0, sizeof(a))
const int maxn = 1010;

int n, m;
int h[maxn];
int dp[maxn];
char G[maxn][maxn];

int main() {
	// FRead();
	while(~Rint(n) && ~Rint(m)) {
		int ans = 0;
		Cls(h); Cls(dp);
		Rep(i, n) Rs(G[i]);
		Rep(i, n) {
			Rep(j, m) {
				if(G[i][j] == '1') h[j]++;
				else h[j] = 0;
				dp[j] = h[j];
			}
			sort(dp, dp+m, greater<int>());
			Rep(j, m) {
				if(dp[j] == 0) break;
				ans = max(ans, dp[j] * (j + 1));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
