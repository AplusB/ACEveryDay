#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4 + 5;
#define lowbit(x) (x & (-x))
typedef long long LL;
const int INF = 2100000000;
int dp[105][maxn];
int a[maxn], b[maxn], d[maxn], rr[maxn];
vector < pair < int, int > > p[maxn];

struct BIT{
	int Min[maxn], n;

	void init(int n){
		this->n = n;
		fill(Min, Min + n + 1, INF);
	}

	void update(int x, int val){
		for(int i = x; i <= n; i += lowbit(i)){
			Min[i] = min(Min[i], val);
		}
	}

	int query(int x){
		if(x > n) return 0;
		int ans = INF;
		for(int i = x; i; i -= lowbit(i)){
			ans = min(ans, Min[i]);
		}
		return ans;
	}

}gao;

int main(){
	int T, n, k;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &k);
		for(int i = 0; i < maxn; i++){
			p[i].clear();
		}
		d[1] = 0;
		for(int i = 2; i <= n; i++){
			scanf("%d", &d[i]);
			d[i] += d[i - 1];
		}
		d[n + 1] = INF;
		for(int i = 1; i <= n; i++){
			scanf("%d%d%d", &a[i], &rr[i], &b[i]);
		}
		for(int i = 1; i <= n; i++){
            int l = lower_bound(d + 1, d + n + 2, d[i] - rr[i]) - d;
            int r = upper_bound(d + 1, d + n + 2, d[i] + rr[i]) - d - 1;
            p[r].push_back(make_pair(l, a[i]));
		}
		for(int i = 0; i <= k; i++)
			for(int j = 0; j <= n; j++)
				dp[i][j] = INF;
		dp[0][0] = 0;
		for(int i = 1; i <= n; i++){
			dp[0][i] = dp[0][i - 1] + b[i];
		}
		int ans = dp[0][n];
		for(int i = 1; i <= k; i++){
			gao.init(n);
			for(int j = 1; j < i; j++){
				gao.update(n - j + 1, dp[i - 1][j]);
			}
			for(int j = i; j <= n; j++){
				gao.update(n - j + 1, dp[i - 1][j]);
				dp[i][j] = min(dp[i][j], dp[i][j - 1] + b[j]);
				for(int t = 0; t < p[j].size(); t++){
					int l = p[j][t].first - 1, val =  p[j][t].second;
					dp[i][j] = min(dp[i][j], gao.query(n - l + 1) + val);
				}
			}
			ans = min(ans, dp[i][n]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
