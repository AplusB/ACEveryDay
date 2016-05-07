#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int md = 1e9 + 7;
const int maxn = 305;
const int B = 300;
LL dp[maxn][maxn * 2][3], g[maxn * 2][3];
int sz[maxn];
struct Edge{
	int v, next;
}E[maxn << 1];
int head[maxn], tol;

void init(){
	memset(head, -1, sizeof head);
	tol = 0;
}

void add_edge(int u, int v){
	E[tol].v = v;
	E[tol].next = head[u];
	head[u] = tol++;
}

void add(LL &a, LL b){
	(a += b) %= md;
}

void dfs(int u, int pre){
	memset(dp[u], 0, sizeof dp[u]);
	dp[u][1 + B][1] = 1;
	dp[u][0 + B][0] = 2;
	sz[u] = 1;
	for(int i = head[u]; ~i; i = E[i].next){
		int v = E[i].v;
		if(v == pre) continue;
		dfs(v, u);
		memset(g, 0, sizeof g);
		for(int j = -sz[u] + B; j <= sz[u] + B; j++){
			for(int k = -sz[v] + B; k <= sz[v] + B; k++){
				int x = j + k - B;
				if(x > 600 || x < 0) continue;
				add(g[x][0], dp[u][j][0] * dp[v][k][0] % md);
				add(g[x][0], dp[u][j][0] * dp[v][k][1] % md);
				add(g[x][0], dp[u][j][0] * dp[v][k][2] % md);

				add(g[x][1], dp[u][j][1] * dp[v][k][0] % md);
				if(x - 3 >= 0)
				add(g[x - 3][2], dp[u][j][1] * dp[v][k][1] % md);
				add(g[x + 1][1], dp[u][j][1] * dp[v][k][2] % md);
				
				add(g[x][2], dp[u][j][2] * dp[v][k][0] % md);
				add(g[x + 1][1], dp[u][j][2] * dp[v][k][1] % md);
				add(g[x + 1][2], dp[u][j][2] * dp[v][k][2] % md);
			}
		}
		memcpy(dp[u], g, sizeof g);
		sz[u] += sz[v];
	}
}

int main(){
	int n, u, v;
	while(scanf("%d", &n) != EOF){
		init();
		for(int i = 1; i < n; i++){
			scanf("%d%d", &u, &v);
			add_edge(u, v);
			add_edge(v, u);
		}
		dfs(1, -1);
		LL ans = 0;
		for(int i = -sz[1] + B; i <= sz[1] + B; i++){
			LL sum = 0;
			for(int j = 0; j < 3; j++){
				add(sum, dp[1][i][j]);
			}
			add(ans, sum * max(0, i - B) % md);
		}
		ans = (ans * 3LL) % md;
		printf("%lld\n", ans);
	}
	return 0;
}
