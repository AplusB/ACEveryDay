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
#define lowbit(x) x & (-x)
#define onenum(x) __builtin_popcount(x)
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef pair<LL, LL> pll;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef vector<LL> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;

const int maxn = 200020;
const int maxm = 1000100;
typedef struct Edge {
	int u, v;
	int next, i;
	bool cut;
	Edge() {}
	Edge(int uu, int vv, int ii) : u(uu), v(vv), i(ii) {}
}Edge;

Edge edge[maxm];
int head[maxn], ecnt;
int n, m, rt;
int d[maxn];
int dfn[maxn];
int low[maxn];
bool vis[maxn];
bool cut[maxn];
vi bridge;
vector<pii> out;

void init() {
	Clr(head, -1); Cls(low); Cls(dfn);
	Cls(vis); Cls(cut); Cls(d);
	ecnt = 0; bridge.cl(); out.cl();
}

void adde(int uu, int vv, int ii) {
	edge[ecnt] = Edge(uu, vv, ii);
	edge[ecnt].cut = 0;
	edge[ecnt].next = head[uu];
	head[uu] = ecnt++;
}

void tarjan(int u, int d) {
	int son = 0;
	vis[u] = 1; low[u] = dfn[u] = d;
	for(int i = head[u]; ~i; i=edge[i].next) {
		int v = edge[i].v;
		if(!vis[v]) {
			tarjan(v, d+1); son++;
			low[u] = min(low[u], low[v]);
			if((son > 1 && u == rt) || (u != rt && dfn[u] <= low[v])) cut[u] = 1;
		}
		else low[u] = min(low[u], dfn[v]);
	}
}

void tarjan1(int u, int d, int p) {
	low[u] = dfn[u] = d;
	for(int i = head[u]; ~i; i=edge[i].next) {
		int v = edge[i].v;
		int id = edge[i].i;
		if(p == id) continue;
		if(!dfn[v]) {
			tarjan1(v, d+1, id);
			low[u] = min(low[u], low[v]);
			if(low[v] > dfn[u]) {
				bridge.pb(i);
				edge[i].cut = edge[i^1].cut = 1;
			}
		}
		else low[u] = min(low[u], dfn[v]);
	}
}

int main() {
	// FRead();
	int u, v;
	while(~scanf("%d%d", &n, &m)) {
		init();
		For(i, 1, m+1) {
			Rint(u); Rint(v);
			adde(u, v, i); adde(v, u, i);
			d[u]++; d[v]++;
		}
		rt = 1;
		For(i, 2, n+1) if(d[rt] < d[i]) rt = i;
		tarjan(rt, 0);
		Cls(low); Cls(dfn); Cls(vis);
		tarjan1(1, 0, -1);
		bool flag = 0;
		For(i, 1, n+1) {
			if(cut[i]) {
				flag = 1;
				printf("%d ", i);
			}
		}
		if(!flag) printf("Null");
		printf("\n");
		Rep(i, bridge.size()) {
			u = edge[bridge[i]].u;
			v = edge[bridge[i]].v;
			if(u > v) swap(u, v);
			out.pb(pii(u, v));
		}
		sort(out.begin(), out.end());
		Rep(i, out.size()) printf("%d %d\n", out[i].fr, out[i].sc);
	}
	RT 0;
}
