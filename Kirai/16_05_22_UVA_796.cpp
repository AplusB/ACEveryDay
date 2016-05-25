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
#define lp p << 1
#define rp p << 1 | 1
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

const int maxn = 100010;
typedef struct Bridge {
	int u, v;
	Bridge() {}
	Bridge(int uu, int vv) : u(uu), v(vv) { if(u > v) swap(u, v); }
}Bridge;

int n;
int dfn[maxn], low[maxn];
vi G[maxn];
vector<Bridge> b;

void dfs(int u, int d, int p) {
	low[u] = dfn[u] = d;
	Rep(i, G[u].size()) {
		int v = G[u][i];
		if(!dfn[v]) {
			dfs(v, d+1, u);
			low[u] = min(low[u], low[v]);
			if(low[v] > dfn[u]) b.push_back(Bridge(u, v));
		}
		else if(p != v) low[u] = min(low[u], dfn[v]);
	}
}

bool cmp(Bridge x, Bridge y) {
	if(x.u == y.u) return x.v < y.v;
	return x.u < y.u;
}

int main() {
	// FRead();
	int u, v, p;
	while(~Rint(n)) {
		if(n == 0) {
			printf("0 critical links\n\n");
			continue;
		}
		Cls(dfn); Cls(low); b.cl();
		Rep(i, n+5) G[i].cl();
		Rep(i, n) {
			Rint(u);
			scanf(" (%d) ", &p);
			W(p) {
				Rint(v);
				G[u].push_back(v);
				G[v].push_back(u);
			}
		}
		Rep(i, n) if(!dfn[i]) dfs(i, 0, i);
		sort(b.begin(), b.end(), cmp);
		printf("%d critical links\n", b.size());
		Rep(i, b.size()) {
			printf("%d - %d\n", b[i].u, b[i].v);
		}
		printf("\n");
	}
	RT 0;
}
