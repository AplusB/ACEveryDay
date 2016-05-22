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
#include 					<algorithm>
#include 					<iostream>
#include 					<iomanip>
#include 					<cstring>
#include 					<climits>
#include 					<complex>
#include 					<fstream>
#include 					<cassert>
#include 					<cstdio>
#include 					<bitset>
#include 					<vector>
#include 					<deque>
#include 					<queue>
#include 					<stack>
#include 					<ctime>
#include 					<set>
#include 					<map>
#include 					<cmath>
using namespace 			std;
#define fr 					first
#define sc 					second
#define cl 					clear
#define BUG 				puts("here!!!")
#define W(a) 				while(a--)
#define pb(a) 				push_back(a)
#define Rint(a) 			scanf("%d", &a)
#define Rll(a) 				scanf("%lld", &a)
#define Rs(a) 				scanf("%s", a)
#define Cin(a) 				cin >> a
#define FRead() 			freopen("in", "r", stdin)
#define FWrite() 			freopen("out", "w", stdout)
#define Rep(i, len) 		for(int i = 0; i < (len); i++)
#define For(i, a, len) 		for(int i = (a); i < (len); i++)
#define Cls(a) 				memset((a), 0, sizeof(a))
#define Clr(a, x) 			memset((a), (x), sizeof(a))
#define Full(a) 			memset((a), 0x7f7f, sizeof(a))
#define lp					p << 1
#define rp					p << 1 | 1
#define pi					3.14159265359
#define RT					return
typedef	long long 			LL;
typedef	long double 		LD;
typedef	unsigned long long 	ULL;
typedef	pair<int, int> 		pii;
typedef	pair<string, int> 	psi;
typedef	map<string, int> 	msi;
typedef	vector<int> 		vi;
typedef	vector<LL> 			vl;
typedef	vector<vl> 			vvl;
typedef	vector<bool> 		vb;

inline bool scan_d(int &num) {
    char in;bool IsN=false;
    in=getchar();
    if(in==EOF) return false;
    while(in!='-'&&(in<'0'||in>'9')) in=getchar();
    if(in=='-'){ IsN=true;num=0;}
    else num=in-'0';
    while(in=getchar(),in>='0'&&in<='9'){
            num*=10,num+=in-'0';
    }
    if(IsN) num=-num;
    return true;
}

const int maxn = 200010;
const int maxm = 900020;

typedef struct Edge {
	int idx, v;
	Edge() {}
	Edge(int vv, int ii) : v(vv), idx(ii) {}
}Edge;

int n, m, q, cnt, b;
int depth[maxn], fa[maxn], vis[maxn];
int dfn[maxn], low[maxn], pbr[maxm];
vector<Edge> G[maxn];
bool bri[maxm];
void dfs(int u, int p, int d) {
	fa[u] = p; depth[u] = d;
	Rep(i, G[u].size()) {
		int v = G[u][i].v;
		if(!vis[v]) {
			vis[v] = 1;
			dfs(v, u, d+1);
		}
	}
}

void tarjan(int u, int p, int d, int pe) {
	low[u] = dfn[u] = d;
	pbr[u] = pe;
	Rep(i, G[u].size()) {
		int idx = G[u][i].idx;
		int v = G[u][i].v;
		if(!dfn[v]) {
			tarjan(v, u, d+1, idx);
			low[u] = min(low[u], low[v]);
			if(low[v] > dfn[u]) bri[idx] = 1;
		}
		else if(v != p) low[u] = min(low[u], dfn[v]);
	}
}

void lca(int u, int v) {
	while(depth[u] > depth[v]) {
		if(bri[pbr[u]]) {
			bri[pbr[u]] = 0; b--;
		}
		u = fa[u];
	}
	while(depth[v] > depth[u]) {
		if(bri[pbr[v]]) {
			bri[pbr[v]] = 0; b--;
		}
		v = fa[v];
	}
	while(u != v) {
		if(bri[pbr[u]]) {
			bri[pbr[u]] = 0; b--;
		}
		u = fa[u];
		if(bri[pbr[v]]) {
			bri[pbr[v]] = 0; b--;
		}
		v = fa[v];
	}
}

int main() {
	// FRead();
	int u, v, _ = 1;
	while(~scan_d(n) && ~scan_d(m) && n + m) {
		Cls(depth); Cls(vis); Cls(fa); Cls(pbr);
		Cls(dfn); Cls(low); Cls(bri); b = 0;
		Rep(i, n+5) G[i].cl();
		Rep(i, m) {
			scan_d(u); scan_d(v);
			G[u].pb(Edge(v, cnt++)); G[v].pb(Edge(u, cnt++));
		}
		dfs(1, 1, 0); tarjan(1, 1, 0, 0);
		scan_d(q);
		printf("Case %d:\n", _++);
		For(i, 1, cnt+1) if(bri[i]) b++;
		W(q) {
			scan_d(u); scan_d(v);
			lca(u, v);
			printf("%d\n", b);
		}
	}
	RT 0;
}
