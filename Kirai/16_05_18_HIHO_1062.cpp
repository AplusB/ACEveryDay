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
#define Rll(a) scanf("%I64d", &a)
#define Rs(a) scanf("%s", a)
#define FRead() freopen("in", "r", stdin)
#define FWrite() freopen("out", "w", stdout)
#define Rep(i, len) for(int i = 0; i < (len); i++)
#define For(i, a, len) for(int i = (a); i < (len); i++)
#define Cls(a) memset((a), 0, sizeof(a))
#define Clr(a, x) memset((a), (x), sizeof(a))
#define Full(a) memset((a), 0x7f7f, sizeof(a))
#define lrt rt << 1
#define rrt rt << 1 | 1

const int maxn = 1110;
const int maxm = 1110;

map<string, int> ns;
map<int, string> sn;
int cnt;
int G[maxn][maxn];
int pre[maxn];
int depth[maxn];
int n, m;
int in[maxn];

void dfs(int u, int p, int d) {
	pre[u] = p;
	depth[u] = d;
	For(i, 1, cnt+1) {
		if(p != i && G[u][i]) dfs(i, u, d+1);
	}
}

int lca(string uu, string vv) {
	int ret = 0;
	int u = ns[uu], v = ns[vv];
	while(depth[u] > depth[v]) u = pre[u];
	while(depth[v] > depth[u]) v = pre[v];
	while(u != v) {
		u = pre[u];
		v = pre[v];
	}
	if(sn.find(v) == sn.end()) return -1;
	return u;
}

int main() {
	// FRead();
	while(~Rint(n)) {
		cnt = 1;
		string u, v;
		Cls(depth); ns.cl(); Cls(G); sn.cl(); Cls(in); Cls(pre);
		Rep(i, n) {
			cin >> u >> v;
			if(ns.find(u) == ns.end()) {
				ns[u] = cnt;
				sn[cnt++] = u;
			}
			if(ns.find(v) == ns.end()) {
				ns[v] = cnt;
				sn[cnt++] = v;
			}
			in[ns[v]]++;
			G[ns[u]][ns[v]] = 1;
		}
		For(i, 1, cnt+1) if(in[i] == 0) dfs(i, -1, 1);
		Rint(m);
		W(m) {
			cin >> u >> v;
			int tmp = lca(u, v);
			if(tmp == -1) puts("-1");
			else cout << sn[tmp] << endl;
		}
	}
	return 0;
}
