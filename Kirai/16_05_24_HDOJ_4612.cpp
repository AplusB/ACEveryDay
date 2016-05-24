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

const int maxn = 200020;
const int maxm = 1500000;

typedef struct Edge {
	int u, v;
	int next;
	bool cut, r;
	Edge() { next = -1; cut = 0; }
}Edge;

typedef struct Tmp {
	int u, v;
	Tmp() {}
	Tmp(int uu, int vv) : u(uu), v(vv) {}
	bool operator==(Tmp p) { RT u == p.u && v == p.v; }
}Tmp;

int head[maxn], ecnt;
int n, m;
int bcnt, idx;
int dfn[maxn], low[maxn];
int stk[maxn], top;
int belong[maxn];
bool instk[maxn];
Edge edge[maxm];
Tmp tmp[maxm];
vector<int> G[maxn];

bool cmp(Tmp x, Tmp y) {
	if(x.u == y.u) RT x.v < y.v;
	RT x.u < y.u;
}

void init() {
	memset(edge, 0, sizeof(edge));
	memset(head, -1, sizeof(head));
	memset(instk, 0, sizeof(instk));
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(belong, 0, sizeof(belong));
	ecnt = top = bcnt = idx = 0;
}

void adde(int uu, int vv, bool p) {
	edge[ecnt].u = uu;
	edge[ecnt].v = vv;
	edge[ecnt].cut = 0;
	edge[ecnt].r = p;
	edge[ecnt].next = head[uu];
	head[uu] = ecnt++;
}

void tarjan(int u, int p, int r) {
	int v = u;
	dfn[u] = low[u] = ++idx;
	stk[++top] = u;
	instk[u] = 1;
	for(int i = head[u]; ~i; i=edge[i].next) {
		v = edge[i].v;
		if(v == p && (!r)) continue;
		// if(v == p) continue;
		if(!dfn[v]) {
			tarjan(v, u, edge[i].r);
			low[u] = min(low[u], low[v]);
			if(low[v] > dfn[u]) edge[i].cut = edge[i^1].cut = 1;
		}
		else if(instk[v]) low[u] = min(low[u], dfn[v]);
	}
	if(dfn[u] == low[u]) {
		bcnt++;
		do {
			v = stk[top--];
			instk[v] = 0;
			belong[v] = bcnt;
		} while(v != u);
	}
}

void dfs(int u) {
	Rep(i, G[u].size()) {
		int v = G[u][i];
		if(dfn[v] != -1) continue;
		dfn[v] = max(dfn[v], dfn[u] + 1);
		dfs(v);
	}
}

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

int main() {
	// FRead();
	int u, v;
	while(~scan_d(n) && ~scan_d(m) && n + m) {
		init();
		Rep(i, n+10) G[i].cl();
		Rep(i, m) {
			scan_d(u); scan_d(v);
			if(u == v) continue;
			if(u > v) swap(u, v);
			tmp[i] = Tmp(u, v);
		}
		sort(tmp, tmp+m, cmp);
		// m = unique(tmp, tmp+m) - tmp;
		Rep(i, m) {
			u = tmp[i].u; v = tmp[i].v;
			if(i == 0 || (tmp[i].u != tmp[i-1].u || tmp[i].v != tmp[i-1].v)) {
				if(i < m - 1 && (tmp[i].u == tmp[i+1].u && tmp[i].v == tmp[i+1].v)) {
					adde(u, v, 1); adde(v, u, 1);
				}
				else {
					adde(u, v, 0); adde(v, u, 0);
				}
			}
		}
		tarjan(1, 0, 0);
		For(u, 1, n+1) {
			for(int i = head[u]; ~i; i=edge[i].next) {
				if(edge[i].cut) {
					v = edge[i].v;
					G[belong[u]].pb(belong[v]);
				}
			}
		}
		Clr(dfn, -1); dfn[1] = 0;
		dfs(1);
		int pos = 1;
		For(i, 1, bcnt+1) if(dfn[i] > dfn[pos]) pos = i;
		Clr(dfn, -1); dfn[pos] = 0;
		dfs(pos);
		int ret = 0;
		Rep(i, bcnt+1) {
			ret = max(ret, dfn[i]);
		}
		printf("%d\n", bcnt - ret - 1);
	}
	RT 0;
}
