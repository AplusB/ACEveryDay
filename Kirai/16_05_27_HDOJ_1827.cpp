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
#define Cin(a) cin >> a
#define FRead() freopen("in", "r", stdin)
#define FWrite() freopen("out", "w", stdout)
#define Rep(i, len) for(int i = 0; i < (len); i++)
#define For(i, a, len) for(int i = (a); i < (len); i++)
#define Cls(a) memset((a), 0, sizeof(a))
#define Clr(a, x) memset((a), (x), sizeof(a))
#define Full(a) memset((a), 0x7f7f, sizeof(a))
#define pi 3.14159265359
#define RT return
#define lowbit(x) x & (-x)
#define onenum(x) __builtin_popcount(x)
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

const int maxn = 1010;
const int maxm = 2020;
const int inf = 0x7f7f7f;
int n, m;
vector<int> G[maxn];
int vis[maxn][maxn];
int w[maxn];
int dfn[maxn], low[maxn], idx;
int st[maxn], top;
int belong[maxn], bcnt;
int in[maxn], out[maxn];
int cost[maxn];

void tarjan(int u) {
	int v = u;
	dfn[u] = low[u] = ++idx;
	vis[0][u] = 1; st[++top] = u;
	Rep(i, G[u].size()) {
		v = G[u][i];
		if(!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if(vis[0][v]) low[u] = min(low[u], dfn[v]);
	}
	if(low[u] == dfn[u]) {
		bcnt++;
		do {
			v = st[top--];
			vis[0][v] = 0;
			belong[v] = bcnt;
		} while(u != v);
	}
}

int main() {
	// FRead();
	int u, v;
	while(~Rint(n) && ~Rint(m)) {
		Cls(dfn); Cls(low); Cls(w);
		Cls(st); Cls(vis); top = 0;
		Cls(belong); bcnt = 0; idx = 0;
		Cls(in); Cls(out);
		For(i, 1, n+1) {
			Rint(w[i]);
			G[i].cl();
			cost[i] = inf;
		}
		Rep(i, m) {
			Rint(u); Rint(v);
			G[u].pb(v);
		}
		For(i, 1, n+1) if(!dfn[i]) tarjan(i);
		Cls(vis);
		For(u, 1, n+1) {
			cost[belong[u]] = min(cost[belong[u]], w[u]);
			Rep(i, G[u].size()) {
				int v = G[u][i];
				if(belong[u] == belong[v]) continue;
				in[belong[v]]++;
				out[belong[u]]++;
			}
		}
		int ret1 = 0, ret2 = 0;
		For(i, 1, bcnt+1) {
			if(in[i] == 0) {
				ret1++;
				ret2 += cost[i];
			}
		}
		printf("%d %d\n", ret1, ret2);
	}
	RT 0;
}
