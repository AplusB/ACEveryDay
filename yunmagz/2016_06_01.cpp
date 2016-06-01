//lightoj 1086 – Jogging Trails
#include <bits/stdc++.h>
 
using namespace std;
 
const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
const double eps = 1e-15;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int, int> PLL;
const LL INF = (1LL << 60);
 
int dist[20][20];
int du[20];
int dp[(1 << 15) + 10];
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        memset(dp, inf, sizeof(dp));
        memset(dist, inf, sizeof(dist));
        memset(du, 0, sizeof(du));
        int u, v, w, n, m;
        scanf("%d%d", &n, &m);
        int sum = 0, sta = 0;
        for (int i = 1; i <= m; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            ++du[u];
            ++du[v];
            sum += w;
            dist[u][v] = min(dist[u][v], w);
            dist[v][u] = dist[u][v];
        }
        for (int i = 1; i <= n; ++i) {
            dist[i][i] = 0;
            if (du[i] % 2 == 0) {
                sta |= (1 << (i - 1));
            }
        }
        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        dp[sta] = sum;
        for (int i = sta; i < (1 << n); ++i) {
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    continue;
                }
                for (int k = 0; k < n; ++k) {
                    if (j == k) {
                        continue;
                    }
                    if (i & (1 << k)) {
                        continue;
                    }
                    int sta = (i | (1 << j));
                    sta |= (1 << k);
                    dp[sta] = min(dp[sta], dp[i] + dist[j + 1][k + 1]);
                }
            }
        }
        printf("Case %d: %d\n", icase++, dp[(1 << n) - 1]);
    }
    return 0;
}
