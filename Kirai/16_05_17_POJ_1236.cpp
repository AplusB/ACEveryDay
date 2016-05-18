/*
━━━━━┒ギリギリ♂ eye！
┓┏┓┏┓┃キリキリ♂ mind！
┛┗┛┗┛┃＼○／
┓┏┓┏┓┃ /
┛┗┛┗┛┃ノ)
┓┏┓┏┓┃
┛┗┛┗┛┃
┓┏┓┏┓┃
┛┗┛┗┛┃
┓┏┓┏┓┃
┛┗┛┗┛┃
┓┏┓┏┓┃
┃┃┃┃┃┃
┻┻┻┻┻┻
*/
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
#define cl clear
#define W(a) while(a--)
#define pb(a) push_back(a)
#define Rint(a) scanf("%d", &a)
#define Rll(a) scanf("%I64d", &a)
#define Rs(a) scanf("%s", a)
#define FRead() freopen("in", "r", stdin)
#define FWrite() freopen("out", "w", stdout)
#define Rep(i, len) for(int i = 0; i < (len); i++)
#define For(i, a, len) for(int i = (a); i < (len); i++)
#define Cls(a) memset((a), 0, sizeof(a))
#define Clr(a, x) memset((a), (x), sizeof(a))
#define Full(a) memset((a), 0x7f7f, sizeof(a))

const int inf = 0x7f7f7f;
const int maxn = 111;
int n, m;
int in[maxn], out[maxn];
int dp[maxn][maxn];
int pos[maxn], cnt;
int pre[maxn];
int belong[maxn];

int find(int x) {
	return x == pre[x] ? x : pre[x] = find(pre[x]);
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if(x != y) pre[x] = y;
}

int main() {
	// FRead();
	int v;
	while(~Rint(n)) {
		Cls(in); Cls(out);
		For(i, 1, n+1) {
			pre[i] = i;
			For(j, 1, n+1) dp[i][j] = inf;
			dp[i][i] = 0;
		}
		For(u, 1, n+1) {
			while(Rint(v)) {
				if(v == 0) break;
				dp[u][v] = 1;
			}
		}
		For(k, 1, n+1) {
			For(i, 1, n+1) {
				For(j, 1, n+1) {
					if(dp[i][j] > dp[i][k] + dp[k][j]) {
						dp[i][j] = dp[i][k] + dp[k][j];
					}
				}
			}
		}
		For(i, 1, n+1) {
			For(j, i+1, n+1) {
				if(dp[i][j] != inf && dp[j][i] != inf) {
					unite(i, j);
				}
			}
		}
		For(i, 1, n+1) {		
			int fa = find(i);
			if(i == fa) pos[cnt++] = i;
			belong[i] = fa;
		}
		if(cnt == 1) {
			printf("1\n0\n");
			continue;
		}
		For(i, 1, n+1) {
			For(j, 1, n+1) {
				if(i == j) continue;
				if(belong[i] != belong[j] && dp[j][i] == inf && dp[i][j] != inf) {
					in[belong[i]]++;
					out[belong[j]]++;
				}
			}
		}
		int ans1 = 0, ans2 = 0;
		Rep(i, cnt) {
			if(!out[pos[i]]) ans1++;
			if(!in[pos[i]]) ans2++;
		}
		printf("%d\n%d\n", ans1, max(ans1, ans2));
	}
	return 0;
}
