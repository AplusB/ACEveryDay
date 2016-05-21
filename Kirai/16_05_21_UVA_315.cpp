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
#define BUG puts("here!!!")
#define W(a) while(a--)
#define pb(a) push_back(a)
#define Rint(a) scanf("%d", &a)
#define Rll(a) scanf("%lld", &a)
#define Rs(a) scanf("%s", a)
#define Cin(a) cin >> a
#define FRead() freopen("in", "r", stdin)
#define FWrite() freopen("out", "w", stdout)
#define Rep(i, len) for(int i = 0; i < (len); i++)
#define For(i, a, len) for(int i = (a); i < (len); i++)
#define Cls(a) memset((a), 0, sizeof(a))
#define Clr(a, x) memset((a), (x), sizeof(a))
#define Full(a) memset((a), 0x7f7f, sizeof(a))
#define lrt rt << 1
#define rrt rt << 1 | 1
#define pi 3.14159265359
#define RT return
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef vector<LL> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;

const int maxn = 220;
char str[66666];
int n, m, rt, bcnt;
int G[maxn][maxn];
int dfn[maxn], low[maxn], vis[maxn];
int in[maxn];
bool cut[maxn];
vi e[maxn];
int bridge[maxn][3];

void dfs(int u, int p, int d) {
	int son = 0;
	vis[u] = 1; dfn[u] = low[u] = d;
	Rep(i, e[u].size()) {
		int v = e[u][i];
		if(vis[v] == 1 && v != p) low[u] = min(low[u], dfn[v]);
		if(vis[v] == 0) {
			dfs(v, u, d+1);
			son++;
			low[u] = min(low[u], low[v]);
			if((u == rt && son > 1) || 
				(u != rt && dfn[u] <= low[v])) cut[u] = 1;
			// if(dfn[u] < low[v]) {
			// 	bridge[bcnt][0] = u;
			// 	bridge[bcnt++][1] = v;
			// }
		}
	}
	vis[u] = 2;
}

int main() {
	// FRead();
	int u, v;
	while(~Rint(n) && n) {
		Cls(G); Cls(dfn); Cls(low); Cls(in);
		Cls(vis); Cls(bridge); Cls(cut); bcnt = 0;
		Rep(i, n+5) e[i].cl();
		getchar();
		while(gets(str) && strcmp("0", str)) {
			char* p = strtok(str, " ");
			sscanf(p, "%d", &u);
			p = strtok(NULL, " ");
			while(p) {
				sscanf(p, "%d", &v);
				p = strtok(NULL, " ");
				G[u][v] = G[v][u] = 1;
			}
		}
		For(i, 1, n+1) {
			For(j, i+1, n+1) {
				if(G[i][j]) {
					e[i].push_back(j);
					e[j].push_back(i);
				}
			}
		}
		rt = 1;
		int ret = 0;
		dfs(1, -1, 0);
		For(i, 1, n+1) if(cut[i]) ret++;
		printf("%d\n", ret);
	}
	RT 0;
}
